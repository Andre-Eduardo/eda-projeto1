/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/
#include "funcoes.h"

double F_logistica(double n)
{
    double e = 2.71828182;
    double p = 0;
    p = 1/(1+exp((-1*n)));


    return p;
}
double F_mult(int p, double w)
{
    double s = 0;
    s = p * w;
    return s;
}
// entradas: vetor de elementos, vetor de pesos , deslocamento
// responsavel por fazer o somatorio com os pesos e o deslocamento do neuronio;
double F_aux(double *p, double *w, double b, int tam_camada_anterior)
{
    double s=0;

    for (int i = 0; i < tam_camada_anterior; i++)
    {
        s += F_mult(p[i], w[i]);
    }
    //printf(" b= %lf\n",b);
    s += b;
    return s;
}
// aloca neuronios e inicializa peso e deslocamento
// entrada: quantidade de neuronios peso
Neuronio *inicializa_neuronio(int qtd)
{
    Neuronio *neu;
    for (int i = 0; i < qtd; i++)
    {
        neu = (Neuronio *)malloc(sizeof(Neuronio) * qtd);

    }
    if (neu == NULL){
        printf("deu ruim no alocamento");
        exit(1);
    }
        for (int i = 0; i < qtd; i++)
    {

        inic_peso(neu[i].pesos);
        neu[i].deslocamento = inic_deslocamento();
    }


    return neu;
}

// aloca neuronios e inicializa peso e deslocamento
// entrada: quantidade de neuronios peso
Neuronio_saida *inicializa_neuronio_saida(int qtd, int tam_camada_oculta)
{
    Neuronio_saida *neu;
    for (int i = 0; i < qtd; i++)
    {
        neu = (Neuronio_saida *)malloc(sizeof(Neuronio_saida) * qtd);

    }
    if (neu == NULL){
        printf("deu ruim no alocamento");
        exit(1);
    }
        for (int i = 0; i < qtd; i++)
    {

        neu[i].pesos=inic_peso_saida(tam_camada_oculta);
        neu[i].tam_vet_pesos=tam_camada_oculta;
        neu[i].deslocamento = inic_deslocamento();
    }


    return neu;
}

double *inic_peso(double *vet){

    for (int i = 0; i < TAMANHO_VET; i++)
    {
        vet[i]= rand()%10;
    }
    return vet;
}

double *inic_peso_saida(int qtd){
    double *vet;

    vet= (double *)malloc(qtd*sizeof(double));

    for (int i = 0; i < qtd; i++)
    {
        vet[i]= rand()%10;
    }
    return vet;
}

double inic_deslocamento(){
    return rand()%10;
}



// entrada:vetor de feature e camada inicial, camada oculta , numeros de neuronios da camada ouculta e neuronio final
// retorna o valor de saida de um neuronio
double F_neuronio(double *vet, Neuronio *camada_oculta,int N_camada, Neuronio_saida *camada_saida){
  double * aux_oculta = (double*)malloc(sizeof(double)*N_camada);

  // camada oculta
  for (int i = 0; i < N_camada; i++){
     camada_oculta[i].saida = F_logistica(F_aux(vet, camada_oculta[i].pesos, camada_oculta[i].deslocamento, VET_FEQ));
     aux_vet[i] = camada_oculta[i].saida;
  }
        camada_saida->saida = F_logistica(F_aux(aux_vet, camada_saida->pesos, camada_saida->deslocamento, N_camada));

  free(aux_oculta);

  return camada_saida->saida;
}

// Objetivo: Calcular erro da saída
// Parâmetro: saída e valor esperado
// Retorno: erro
double erro_saida(double esperado, double real){
  return esperado-real;
}

// Objetivo: Calcular derivada da logística para um valor x
// Parâmetro: saída do neurônio
// Retorno: derivada da logística
double d_F_logistica(double x){
  return 1-x*x;
}

// Objetivo: Calcular gradiente do neurônio da saída
// Parâmetro: saída e valor esperado
// Retorno: gradiente do neurônio de Saída
double gradiente_saida(double esperado, double real){
  return d_F_logistica(real)*erro_saida(esperado, real);
}

// Objetivo: Calcular gradiente do neurônio da saída
// Parâmetro:
// Retorno: gradiente do neurônio de Saída
double gradiente_camada_oculta(double saida_neuronio, int pos_neu, Neuronio_saida *camada_saida, int tam_camada, double *gradientes){
  double somatorio=0;
  int i;

  for(i=0; i<tam_camada; i++){
    somatorio+=*(gradientes+i)*((camada_saida+i)->pesos[pos_neu]);
  }

  return d_F_logistica(saida_neuronio)*somatorio;
}

// Objetivo: Calcular diferença dos pesos
// Parâmetro: saída associada ao peso, gradiente do neuronio
// Retorno: diferença de pesos
double diff_pesos(double saida, double gradiente){
  return 2*ALFA*saida*gradiente;
}

// Objetivo: calcular novo peso w
// Parâmetro: saída associada ao peso, gradiente do neuronio
// Retorno: diferença de pesos
double novo_peso(double peso, double saida, double gradiente){
  return peso + diff_pesos(saida, gradiente);
}

// Objetivo: Método backpropagation de treinamento de rede neural
// Parâmetro: camada de entradas, camada oculta, camada de saída, valor esperado, tamanho da camada oculta
// Retorno: rede neural atualizada
void backpropagation(double *entrada, Neuronio *camada_oculta,int tam_camada_oculta, Neuronio_saida *camada_saida, double esperado){
  //Declarações
  double grad_saida;
  double *grad_camada_oculta;
  int i, j;
  //Instruções
  if(tam_camada_oculta<1){
    fprintf(stderr, "\n\nValor inválido de camada oculta!");
    exit(-1);
  }

  grad_saida=gradiente_saida(esperado, camada_saida->saida);
  grad_camada_oculta=(double *)malloc(tam_camada_oculta*sizeof(double));

  for(i=0; i<tam_camada_oculta; i++){
    *(grad_camada_oculta+i)=gradiente_camada_oculta((camada_oculta+i)->saida, i, camada_saida, 1, &grad_saida);
  }

  //calcula pesos da saída
  for(i=0; i<tam_camada_oculta; i++){
    camada_saida->pesos[i]=novo_peso(camada_saida->pesos[i], (camada_oculta+i)->saida, grad_saida);
  }
  camada_saida->deslocamento=novo_peso(camada_saida->deslocamento, 1, grad_saida);
  //calcula pesos camada oculta
  for(i=0; i<tam_camada_oculta; i++){
    for(j=0; j<TAMANHO_VET; j++){
      camada_oculta->pesos[j]=novo_peso(camada_oculta->pesos[j], *(entrada+j), *(grad_camada_oculta+i));
    }
    camada_oculta->deslocamento=novo_peso(camada_oculta->deslocamento, 1, *(grad_camada_oculta+i));
  }
  free(grad_camada_oculta);

  return;
}


// Objetivo: libera rede neural
// Parâmetro: camada de entradas, camada oculta, camada de saída
// Retorno:
int libera_rede_neural(double* vet_feat_grama, double* vet_feat_asfalto,
double* vet_feat_grama_teste, double* vet_feat_asfalto_teste,
Neuronio *camada_oculta, Neuronio_saida *camada_saida){

  free(vet_feat_grama);
  free(vet_feat_asfalto);
  free(vet_feat_grama_teste);
  free(vet_feat_asfalto_teste);

  free(camada_oculta);

  free(camada_saida->pesos);
  free(camada_saida);

  return 0;
}

// Objetivo: Calcula a variância
// Parâmetro: saida do neuronio, valor esperad
// Retorno: nova variância
double mse(double variancia_anterior, double valor_esperado, double valor_real, int epoca){
  double resultado;

  if(epoca==1){
    resultado = (valor_real-valor_esperado)*(valor_real-valor_esperado);
  }else if(epoca>1){
    resultado=variancia_anterior/(epoca-1);
    resultado+=(valor_real-valor_esperado)*(valor_real-valor_esperado);
    resultado/=epoca;
  }else{
    fprintf(stderr, "\n\nÉpoca inválida!!!!");
    exit(-1);
  }

  return resultado;
}
