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
    return (data){""};
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
