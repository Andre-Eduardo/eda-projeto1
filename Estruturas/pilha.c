/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista

#include "pilha.h"


// Objetivo: Cria pilha vazia
// Parâmetro:
// Retorno: ponteiro nulo
pilha *criaPilhaVazia(){
  //Declarações:

  //Instruções:

  return NULL;
}

// Objetivo: Adiciona um contato ao final da lista
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
pilha *push(pilha *stack, elem dados){
  //Declarações:
    pilha *novoElem;
    //Instruções:

    novoElem = (pilha *)malloc(sizeof(pilha));
    if(novoElem==NULL){
        fprintf(stderr,"Erro ao alocar novo elemento na pilha\n");
        return NULL;
    }

    novoElem->dados=dados;
    novoElem->ante=stack;

    return novoElem;
}

// Objetivo: Acessar o topo da pilha
// Parâmetro: endereço do ponteiro para o topo da pilha
// Retorno: elemento do topo da pilha
elem pop(pilha **stack){
  //Declarações:
  elem resultado;
  //Instruções:
  resultado.nome[0]='\0';

  if(*stack==NULL){
    fprintf(stderr,"Não há elementos para acessar porque a pilha não foi inicializada...\n");
    return resultado;
  }

  resultado=(*stack)->dados;
  *stack=(*stack)->ante;


  return resultado;
}

// Objetivo: Apagar a pilha
// Parâmetro: pilha
// Retorno: ponteiro nulo
pilha *liberaPilha(pilha *stack){
  //Declarações:
  pilha *aux, *aux2;
  //Instruções:

  for(aux=stack;aux!=NULL;aux=aux2){
    aux2=aux->ante;
    free(aux);
  }

  return NULL;
}

// Objetivo: Calcula a quantidade de elementos na pilha
// Parâmetro: pilha
// Retorno: número de elementos da pilha
int tamanhoPilha(pilha *stack){
  //Declarações:
  pilha *element;
  int i;
  //Instruções:

  for(i=0, element=stack; element!=NULL; element=element->ante, i++);

  return i;
}
