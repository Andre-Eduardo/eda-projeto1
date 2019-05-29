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
#include "pilha.h"

int main(){
  //Declarações:
  pilha *oi;
  pilha *aux;
  elem ale;
  elem porquera;
  int i;
  //Instruções:
  ale.nome[0]='a';
  ale.nome[1]='\0';

  oi=criaPilhaVazia();
  oi=push(oi, ale);
  oi=push(oi, ale);
  oi=push(oi, ale);
  ale.nome[0]='a';
  ale.nome[1]='b';
  ale.nome[2]='a';
  ale.nome[3]='\0';
  oi=push(oi, ale);
  printf("%d\n", tamanhoPilha(oi));
  for(i=0; i<5;i++){
    porquera=pop(&oi);
    printf("%s\n", porquera.nome);
  }

  oi=liberaPilha(oi);

  return 0;
}
