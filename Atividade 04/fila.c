/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista

#include "fila.h"


// Objetivo: Cria fila vazia
// Parâmetro:
// Retorno: ponteiro nulo
fila criaFilaVazia(){
  //Declarações:
  fila filaVazia={NULL, NULL};
  //Instruções:

  return filaVazia;
}

// Objetivo: Adiciona um contato ao final da fila
// Parâmetro: fila, dados serem adicionados
// Retorno: fila
fila pushF(fila queue, data dados){
  //Declarações:
  list_enc *novoElem;
  list_enc *element;
  //Instruções:

  novoElem = (list_enc *)malloc(sizeof(list_enc));
  if(novoElem==NULL){
      fprintf(stderr,"Erro ao alocar novo elemento na fila\n");
      return (fila){NULL, NULL};
  }

  if(queue.ini!=NULL){
    novoElem->dados=dados;
    queue.fim->prox=novoElem;
    novoElem->prox=NULL;
    queue.fim=novoElem;
  }else{
    novoElem->dados=dados;
    novoElem->prox=NULL;
    queue.ini=novoElem;
    queue.fim=novoElem;
  }

  return queue;
}

// Objetivo: Acessar o início da fila
// Parâmetro: endereço da fila
// Retorno: elemento do início da fila
data popF(fila* queue){
  //Declarações:
  data resultado;
  list_enc *aux;
  //Instruções:

  if(queue->ini==NULL){
    fprintf(stderr,"Não há elementos para acessar porque a fila não foi inicializada...\n");
    return (data){"", 0, 0};
  }

  resultado=queue->ini->dados;
  aux=queue->ini;
  if(queue->ini==queue->fim)
    queue->fim=NULL;
  queue->ini=queue->ini->prox;
  free(aux);

  return resultado;
}

// Objetivo: Apagar a pilha
// Parâmetro: pilha
// Retorno: ponteiro nulo
fila liberaFila(fila queue){
  //Declarações:
  list_enc *aux, *aux2;
  //Instruções:

  for(aux=queue.ini;aux!=NULL;aux=aux2){
    aux2=aux->prox;
    free(aux);
  }
  queue.ini=NULL;
  queue.fim=NULL;
  return queue;
}

// Objetivo: Calcula a quantidade de elementos na fila
// Parâmetro: fila
// Retorno: número de elementos da fila
int tamanhoFila(fila queue){
  //Declarações:
  list_enc *element;
  int i;
  //Instruções:

  for(i=0, element=queue.ini; element!=NULL; element=element->prox, i++);

  return i;
}

// Objetivo: Deletar elemento na fila
// Parâmetro: fila
// Retorno: fila com elemento deletado
fila delElem(fila queue, int pos){
  //Declarações:
  list_enc *element;
  list_enc *ante;
  list_enc *aux;
  int i;
  //Instruções:
  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um elemento na lista...\n\n\nPosição inválida!!!\n");
    return (fila){NULL, NULL};
  }

  if(queue.ini==NULL||queue.fim==NULL){
    fprintf(stderr,"Não há elementos para deletar porque a fila não foi inicializada...\n");
    return (fila){NULL, NULL};
  }

  if(pos==0){
    element=queue.ini;
    queue.ini=element->prox;
  }else{
    for(i=0, ante=queue.ini; i<pos-1; ante=ante->prox, i++);
    element=ante->prox;
    ante->prox=element->prox;
  }

  free(element);

  for(aux=queue.ini; aux->prox!=NULL; aux=aux->prox);
  queue.fim=aux;

  return queue;
}

// Objetivo: Verificar se há aviões com combustível igual a zero, e colocá-los no começo da fila
// Parâmetro: fila
// Retorno: fila organizada
fila verificaComb(fila queue,  int *S_combustivel){
  //Declarações:
  list_enc *element;
  list_enc *ante;
  list_enc *aux;
  int i, sent=1;
  int avioesScomb; // qtd de avioes sem combustivel
  
  //Instruções:
  if(queue.ini==NULL||queue.fim==NULL){
    fprintf(stderr,"Não há elementos para verificar porque a fila não foi inicializada...\n");
    return (fila){NULL, NULL};
  }

  while(sent){
    for(element=queue.ini, avioesScomb=0; element->prox!=NULL && element->dados.combustivel==0; element=element->prox){
      avioesScomb++;
      *S_combustivel = avioesScomb;
    }
    if(element==queue.fim){
      sent=0;
    }else{
      for(element=queue.ini, i=0; element->prox!=NULL && i<avioesScomb; element=element->prox, i++);
      for(; element->prox!=NULL && element->dados.combustivel!=0; element=element->prox){
        ante=element;
      }
      if(!(element->prox==NULL && element->dados.combustivel!=0)){
        ante->prox=element->prox;
        for(aux=queue.ini, i=0; aux->prox!=NULL && i<avioesScomb; aux=aux->prox, i++);
        if(aux==queue.ini){
          element->prox=aux;
          queue.ini=element;
        }else{
          element->prox=aux;
          for(aux=queue.ini, i=0; aux->prox!=NULL && i<avioesScomb-1; aux=aux->prox, i++);
          aux->prox=element;
        }
      }else{
        sent=0;
      }
    }
  }
  for(aux=queue.ini; aux->prox!=NULL; aux=aux->prox);
  queue.fim=aux;
  
  return queue;
}

// Objetivo: Verificar se há aviões com combustível negativo e excluí-los da fila
// Parâmetro: fila
// Retorno: fila sem aeronaves caídas
fila verificaQueda(fila queue){
  //Declarações:
  list_enc *element;
  int i, sent=1;
  //Instruções:
  if(queue.ini==NULL||queue.fim==NULL){
    fprintf(stderr,"Não há elementos para verificar porque a fila não foi inicializada...\n");
    return (fila){NULL, NULL};
  }
  while(sent){
    for(element=queue.ini, i=0; element->prox!=NULL && element->dados.combustivel!=-1; element=element->prox, i++);
    if(element->prox==NULL && element->dados.combustivel!=-1){
      sent=0;
    }else{
      queue= delElem(queue, i);
      puts("ALERTA CRÍTICO, AERONAVE IRÁ CAIR");
    }
  }


  return queue;
}

//Objetivo: Printar informacoes iniciais
void printaInicio(int NVoos, int NAproximacoes, int Ndecolagens, int hora, int min){

      puts("----------------------------------------------------------------");
      puts("“Aeroporto Internacional Santos Dumont inventou o aviao”");
      printf("Hora Inicial: %d:%d\n", hora, min);             //recebe hora
      puts("Fila de Pedidos: ");                    // ???
      printf("NVoos: %d\n", NVoos);                 //revebe NVoos
      printf("Naproximacoes: %d\n", NAproximacoes); //recebe Naproximacoes
      printf("NDecolagens: %d\n", Ndecolagens);      //recebe NDecolagens
      puts("----------------------------------------------------------------");
}

//Objetivo: Printar lista de status de cada aeronave
void printaStatus(char *Status, char *Codigo, int hora, int min, char NPista){
     

      puts("Listagem de eventos:");                               //recebe lista de eventos
      puts("");                                                   // pula linha
      printf("Codigo do voo: %s\n", Codigo);                      // recebe string do codigo voo
      printf("Status: %s\n", Status);                               //["aeronave decolou" ou "aeronave pousou"]
      printf("Horario do inicio do procedimento: %d:%d\n", hora, min); //recebe hora do movimento da aeronave
      printf("Numero da pista: %d\n", NPista);                    //recebe numero da pista do procedimento
}
