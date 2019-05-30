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
#include "fila.h"

int main(){
  //Declarações:
  fila oi;
  data ale;
  list_enc bagaca;
  int i;
  //Instruções:
  ale.nome[0]='a';
  ale.nome[1]='\0';

  oi=criaFilaVazia();
  oi=pushF(oi, ale);
  oi=pushF(oi, ale);
  oi=pushF(oi, ale);
  ale.nome[0]='a';
  ale.nome[1]='b';
  ale.nome[2]='a';
  ale.nome[3]='\0';
  oi=pushF(oi, ale);
  bagaca=*(oi.fim);
  printf("%s\n", bagaca.dados.nome);
  bagaca=*(oi.ini);
  printf("%s\n", bagaca.dados.nome);
  bagaca=*(bagaca.prox);
  printf("%s\n", bagaca.dados.nome);
  bagaca=*(bagaca.prox);
  printf("%s\n", bagaca.dados.nome);
  bagaca=*(bagaca.prox);
  printf("%s\n", bagaca.dados.nome);
  printf("%d\n", tamanhoFila(oi));
  ale=popF(&oi);
  printf("%s\n", ale.nome);
  ale=popF(&oi);
  printf("%s\n", ale.nome);
  ale=popF(&oi);
  printf("%s\n", ale.nome);
  ale=popF(&oi);
  printf("%s\n", ale.nome);
  printf("%p\n", oi.fim);


  oi=liberaFila(oi);

  return 0;
}
