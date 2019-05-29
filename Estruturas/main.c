/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Organizar fila de vôos de aeroporto
// Entrada:
// Saída: log dos acontecimentos do aeroporto

#include <stdio.h>
#include "lista.h"

int main(){
  //Declarações:
  lista *oi;
  lista *aux;
  elemento ale;
  //Instruções:
  ale.nome[0]='a';
  ale.nome[1]='\0';

  oi=criaListaVazia();
  oi= appendLista(oi, ale);
  oi= appendLista(oi, ale);
  oi= appendLista(oi, ale);
  ale.nome[0]='b';
  ale.nome[1]='\0';
  oi=insereOrdenado(oi, ale);
  ale.nome[0]='c';
  ale.nome[1]='\0';
  oi=insereOrdenado(oi, ale);
  ale.nome[0]='b';
  ale.nome[1]='a';
  ale.nome[2]='c';
  ale.nome[3]='\0';
  oi=insereOrdenado(oi, ale);
  ale.nome[0]='o';
  ale.nome[1]='a';
  ale.nome[2]='c';
  ale.nome[3]='\0';
  oi=insereLista(oi, ale, 2);
  oi= deletaElemento(oi,0);
  printLista(oi);

  aux= acessaElemento(oi, 2);
  printf("\n\n\n\n\n%s", aux->dados.nome);
  aux= procuraElemento(oi, "ac");
  printf("\n\n\n\n\n%s", aux->dados.nome);
  printf("\nTamanho da lista: %d", tamanhoLista(oi));


  oi=liberaLista(oi);

  return 0;
}
