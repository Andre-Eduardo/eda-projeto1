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
#include <math.h>
#include <time.h>
#define UNI_TIME 5 // unidade de tempo 1 uma unidade = 5 mim
#define MAX_AVI 64 // maximo de avioes
#define MIM_AVI 20 // mminimo de avioes

void inic_alatorio(int *NVoos, int *NAproximacoes, int *NDecolagens);
fila inic_lista(int *comb, int NAproximacoes, int NDecolagens, fila aviao, char *cod_Voos);
int* inic_combustivel(int NDecolagens, int* comb);
int main()
{
  //Declarações:
  char *cod_Voos[64] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
                        "AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880",
                        "AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002",
                        "AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403",
                        "AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601",
                        "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392",
                        "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065",
                        "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510",
                        "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610",
                        "KL5611"};

  int NVoos;         // numero de voos (20 ate 64) NVoos = NAproximaçoes + NDecolagens
  int NAproximacoes; // numero de avioes querendo pousar (10 32)
  int NDecolagens;   // avioes querendo decolar (10 a 32)
  fila oi;
  data ale;
  list_enc bagaca;
  int i;
  //Instruções:

  // ale.nome[0] = 'a';
  // ale.nome[1] = '\0';

  // oi = criaFilaVazia();
  // oi = pushF(oi, ale);
  // oi = pushF(oi, ale);
  // oi = pushF(oi, ale);
  // ale.nome[0] = 'a';
  // ale.nome[1] = 'b';
  // ale.nome[2] = 'a';
  // ale.nome[3] = '\0';
  // oi = pushF(oi, ale);
  // bagaca = *(oi.fim);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(oi.ini);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // bagaca = *(bagaca.prox);
  // printf("%s\n", bagaca.dados.nome);
  // printf("%d\n", tamanhoFila(oi));
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // ale = popF(&oi);
  // printf("%s\n", ale.nome);
  // printf("%p\n", oi.fim);

  // oi = liberaFila(oi);
  inic_alatorio(&NVoos, &NAproximacoes, &NDecolagens);
  printf("total =%d\n", NVoos);
  printf("aprox =%d\n", NAproximacoes);
  printf("decola =%d\n", NDecolagens);
  return 0;
}
void inic_alatorio(int *NVoos, int *NAproximacoes, int *NDecolagens)
{
  srand(time(NULL));

  *NAproximacoes = (rand() % 32) + 10;
  *NDecolagens = (rand() % (62 - *NAproximacoes)) + 10;
  *NVoos = *NAproximacoes + *NDecolagens;
}
int* inic_combustivel(int NDecolagens, int* comb)
{
  
  for (int i = 0; i <= NDecolagens; i++)
  {
    comb[i] = rand() % 12;
  }
  return comb;
}

fila inic_lista(int *comb, int NAproximacoes, int NDecolagens, fila aviao, char *cod_Voos)
{

  data d;
  int i, al_cod;
  for (i = 0; i <= NAproximacoes; i++)
  {

    d.codigo = *(cod_Voos+i);
    d.sentido = 'A';
    d.combustivel = comb[i];
    pushF(aviao, d);
  }
  for (i = 0; i <= NDecolagens; i++)
  {
    d.codigo = (cod_Voos +i + NAproximacoes);
    d.sentido = 'D';
    pushF(aviao, d);
  }
  return aviao;
}