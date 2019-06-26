#ifndef _FUNCOES_
#define _FUNCOES_

#include <math.h>
#include <stdlib.h>
#include<time.h>
#include <stdio.h>
#define VET_FEQ 536
#define TAMANHO_VET 536
typedef struct neuronio
{
    double pesos[536];
    double deslocamento;

} Neuronio;

Neuronio *inicializa_neuronio(int qtd);
double F_aux(double *p, double *w, double b);
double F_mult(int p, double w);
double F_logistica(double n);
double *inic_peso(double *vet);
double inic_deslocamento();



#endif