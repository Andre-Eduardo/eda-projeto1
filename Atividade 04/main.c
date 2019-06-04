/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Organizar fila de vôos de aeroporto
// Entrada:
// Saída: log dos acontecimentos do aeroporto

#include "fila.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#define UNI_TIME 5 // unidade de tempo 1 uma unidade = 5 mim
#define MAX_AVI 64 // maximo de avioes
#define MIM_AVI 20 // mminimo de avioes

int inic_aletorio(int NVoos, int *NAproximacoes, int *NDecolagens);
fila inic_lista(int *NAproximacoes, int *NDecolagens, fila aviao, char *cod_Voos[64], int *NVoos);
int *inic_combustivel(int NAproximacoes, int *comb);
fila consome_combustivel(fila aviao);
void passaTempo(int *hora, int *minutos, int *pista);
fila decolagem(fila aviao, int *liberado, int hora, int min, int pista);
fila pouso(fila aviao, int *liberado, int hora, int min, int pista);

int main()
{
  //Declarações:
  char *cod_Voos[][7] = {"VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
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
  int horas = 6, minutos = 0;
  int comb_critico = 0;
  int pista[] = {0, 0, 0};

  fila avioes = criaFilaVazia();

  int i, contagem_tempo = 0;

  //Instruções:
  avioes = inic_lista(&NAproximacoes, &NDecolagens, avioes, *cod_Voos, &NVoos);
  printaInicio(NVoos, NAproximacoes, NDecolagens, horas, minutos, avioes);
  while (avioes.ini->prox != NULL)
  {
    // if (pista[0] == 0 || pista[1] == 0 || pista[2] == 0)
    // {
    //   avioes = verificaComb(avioes, &comb_critico);
    // }
    avioes = verificaComb(avioes, &comb_critico);

    //01
    avioes = pouso(avioes, &pista[0], horas, minutos, 1);

    avioes = decolagem(avioes, &pista[0], horas, minutos, 1);
    //02
    avioes = pouso(avioes, &pista[1], horas, minutos, 2);
    avioes = decolagem(avioes, &pista[1], horas, minutos, 2);
    //03

    if (comb_critico >= 3)
    {
      avioes = pouso(avioes, &pista[2], horas, minutos, 3);
    }
    else
    {
      avioes = decolagem(avioes, &pista[2], horas, minutos, 3);
    }
    passaTempo(&horas, &minutos, pista);
    printf("tamanho fila =%d\n", tamanhoFila(avioes));
    contagem_tempo++;

    if (contagem_tempo == 10)
    { // a cada 10 unidade de tempo o aviao decrementa combustivel
      avioes = consome_combustivel(avioes);
      contagem_tempo = 0;
    }
    avioes = verificaQueda(avioes);
  }

  liberaFila(avioes);
  return 0;
}

// Objetivo: inicializar numero de voos e decolagens
// Entrada: numero de voos ,decolagens e total
// Saída: total
int inic_aletorio(int NVoos, int *NAproximacoes, int *NDecolagens)
{
  srand(time(NULL));

  *NAproximacoes = (rand() % 23) + 10;
  *NDecolagens = (rand() % 23) + 10;
  return NVoos = *NAproximacoes + *NDecolagens;
}

// Objetivo: iniciliza valores de combustivel
// Entrada:numero de decolagens e combustivel
// Saída: combustivel
int *inic_combustivel(int NAproximacoes, int *comb)
{

  for (int i = 0; i < NAproximacoes; i++)
  {
    comb[i] = rand() % 13;
  }
  return comb;
}
// Objetivo: inicializa fila com os valores de voo
// Entrada: numero de aproximaçoes , decolagens , fila , code de voos e total de voos
// Saída: fila;
fila inic_lista(int *NAproximacoes, int *NDecolagens, fila aviao, char *cod_Voos[64], int *NVoos)
{
  int comb[32];
  *NVoos = inic_aletorio(*NVoos, NAproximacoes, NDecolagens);
  inic_combustivel(*NAproximacoes, comb);
  data d;
  int i, al_cod;
  for (i = 0; i < *NAproximacoes; i++)
  {

    strcpy(d.codigo, (cod_Voos[i]));
    d.sentido = 'A';
    d.combustivel = comb[i];

    printf("combustivel%d = %d \n", i, comb[i]);
    aviao = pushF(aviao, d);
  }
  for (i = 0; i < *NDecolagens; i++)
  {
    strcpy(d.codigo, (cod_Voos[i + *NAproximacoes]));
    d.sentido = 'D';
    aviao = pushF(aviao, d);
  }
  return aviao;
}
// realiza o pouso do aviao
fila pouso(fila aviao, int *liberado, int hora, int min, int pista)
{
  char status[] = "Aproximacao";
  if (aviao.ini == NULL)
  {
    return aviao;
  }
  if (tamanhoFila(aviao) >= 1)
  {

    list_enc *prov = aviao.ini;
    int aux = 0;
    if (*liberado == 0)
    {
      if (prov->dados.sentido != 'A' && prov->prox != NULL)
      {
        prov = prov->prox;
        aux++;
      }
      // print log
      printaStatus(status, prov->dados.codigo, hora, min, pista);
      aviao = delElem(aviao, aux);
      *liberado = 4; //unidade de  tempo para realizar um pouso
    }
  }
  return aviao;
}
// realiza a decolagem do aviao
fila decolagem(fila aviao, int *liberado, int hora, int min, int pista)
{
  char status[] = "Decolagem";
  if (aviao.ini == NULL)
  {
    return aviao;
  }
  if (tamanhoFila(aviao) >= 1)
  {
    list_enc *prov = aviao.ini;
    int aux = 0;
    if (*liberado == 0)
    {
      if (prov->dados.sentido != 'D' && prov->prox != NULL)
      {
        prov = prov->prox;
        aux++;
      }
      // print log
      printaStatus(status, prov->dados.codigo, hora, min, pista);
      aviao = delElem(aviao, aux);
      *liberado = 2; // unidae de  tempo para realizar uma decolagem
    }
  }
  return aviao;
}
// incrementa o tempo do sistema;
void passaTempo(int *hora, int *minutos, int *pista)
{

  *minutos += 5;
  if (*minutos > 59)
  {
    *minutos = 0;
    *hora += 1;
    if (*hora >= 24)
    {
      *hora = 0;
    }
  }
  if (pista[0] > 0)
  {
    pista[0] -= 1;
  }
  if (pista[1] > 0)
  {
    pista[1] -= 1;
  }
  if (pista[2] > 0)
  {
    pista[2] -= 1;
  }
}
// decrementa o combustivel das aeronaves
fila consome_combustivel(fila aviao)
{
  list_enc *prov = aviao.ini;

  while (prov != NULL)
  {
    prov->dados.combustivel -= 1;
    prov = prov->prox;
  }
  return aviao;
}