#include "funcoes.h"
#include "identificador_de_solo.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
    //Declarações
    int i, aux, epocas=0;
    double teste;
    int acertos=0, falsa_rej=0, falsa_acei=0;
    double variancia=10;
    int num_camada_oculta;
    double esperado; //valor esperado na saída
    double* vet_feat_grama;
    double* vet_feat_asfalto;
    double* vet_feat_grama_teste;
    double* vet_feat_asfalto_teste;
    double* vet_feat_atual;
    Neuronio *camada_oculta;
    Neuronio_saida *camada_saida;
    FILE *arquivo;
    //Instruções
    srand(time(NULL));
    if (argc > 1)
    {
        num_camada_oculta = atoi(argv[1]);
    }
    else
    {
        puts("inicialize a camada oculta");
        return 1;
    }

    printf("Iniciado com %d elementos na camada oculta\n", num_camada_oculta);

    arquivo=fopen("dados.bin", "rb");
    if(arquivo==NULL){
      retira_features(&vet_feat_grama, &vet_feat_asfalto, &vet_feat_grama_teste, &vet_feat_asfalto_teste);
      arquivo = fopen("dados.bin", "wb");
      fwrite(vet_feat_grama, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fwrite(vet_feat_asfalto, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fwrite(vet_feat_grama_teste, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fwrite(vet_feat_asfalto_teste, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
    }else{
      vet_feat_grama = (double *)malloc((NUM_IMG / 2) * TAM_VET_FEAT * sizeof(double));
      vet_feat_asfalto = (double *)malloc((NUM_IMG / 2) * TAM_VET_FEAT * sizeof(double));
      vet_feat_grama_teste = (double *)malloc((NUM_IMG / 2) * TAM_VET_FEAT * sizeof(double));
      vet_feat_asfalto_teste = (double *)malloc((NUM_IMG / 2) * TAM_VET_FEAT * sizeof(double));

      fread(vet_feat_grama, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fread(vet_feat_asfalto, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fread(vet_feat_grama_teste, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
      fread(vet_feat_asfalto_teste, sizeof(double)*TAMANHO_VET, NUM_IMG/2, arquivo);
    }
    fclose(arquivo);

    puts("Features retirados");




    //n = inicializa_neuronio(VET_FEQ);// quantidade da primera camada/
    camada_oculta = inicializa_neuronio(num_camada_oculta); // numero de neuronios na camada oculta;
    camada_saida = inicializa_neuronio_saida(1, num_camada_oculta); // ultima camada da rede neural

    puts("Neurônios inicializados");

    while(epocas<EPOCAS && variancia>VARIANCIA){
      for(i=0; i<NUM_IMG; i++){
        aux=gera_num_alea(0);
        if(aux>25){
          vet_feat_atual=vet_feat_grama+(aux-26)*TAM_VET_FEAT;
          esperado = 1;
        }else{
          vet_feat_atual=vet_feat_asfalto+(aux-1)*TAM_VET_FEAT;
          esperado = 0;
        }

        F_neuronio(vet_feat_atual,camada_oculta, num_camada_oculta, camada_saida);
        backpropagation(vet_feat_atual, camada_oculta, num_camada_oculta, camada_saida, esperado);
      }

      epocas++;
      variancia = mse(variancia, esperado, camada_saida->saida, epocas);
      fprintf(stderr, "\rÉpocas %d; Variância %.2lf", epocas, variancia);
      gera_num_alea(1);
    }

    printf("\nTreinamento finalizado após %d épocas\n", epocas);



    for (i = 0; i < (NUM_IMG / 2); i++){
      teste = F_neuronio(vet_feat_asfalto_teste + i * TAM_VET_FEAT, camada_oculta, num_camada_oculta, camada_saida);
      if (teste<=0.5){
        acertos++;
      }else{
        falsa_acei++;
      }
    }

    puts("Realizando testes...");

    for (i = 0; i < (NUM_IMG / 2); i++)
    {
      teste = F_neuronio(vet_feat_grama_teste + i * TAM_VET_FEAT, camada_oculta, num_camada_oculta, camada_saida);
      if (teste>0.5){
        acertos++;
      }else{
        falsa_rej++;
      }
    }

    puts("\n");
    lista_resultado(acertos,falsa_rej, falsa_acei);

    libera_rede_neural(vet_feat_grama,
                       vet_feat_asfalto,
                       vet_feat_grama_teste,
                       vet_feat_asfalto_teste,
                       camada_oculta,
                       camada_saida);

    return 0;
}
