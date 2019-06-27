#ifndef _FUNCOES_
#define _FUNCOES_

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define VET_FEQ 536
#define TAMANHO_VET 536
typedef struct neuronio
{
    double pesos[536];
    double deslocamento;
    double saida;

} Neuronio;

typedef struct neuronio_saida
{
    double *pesos;
    int tam_vet_pesos;
    double deslocamento;
    double saida;

} Neuronio_saida;


Neuronio *inicializa_neuronio(int qtd);
double F_aux(double *p, double *w, double b);
double F_mult(int p, double w);
double F_logistica(double n);
double *inic_peso(double *vet);
double inic_deslocamento();
double F_neuronio(double *vet, Neuronio *camada1, Neuronio *camada2,int N_camada, Neuronio *n_f);
double erro_saida(double esperado, double real);
double d_F_logistica(double x);
double gradiente_saida(double esperado, double real);
double gradiente_camada_oculta(double saida_neuronio, int pos_neu, Neuronio_saida *camada_saida, int tam_camada, double *gradientes);
double diff_pesos(double saida, double gradiente);
double novo_peso(double peso, double saida, double gradiente);
void backpropagation(double *entrada, Neuronio *camada_oculta,int tam_camada_oculta, Neuronio_saida *camada_saida, double esperado);



#endif
