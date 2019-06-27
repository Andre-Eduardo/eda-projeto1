#ifndef _FUNCOES_
#define _FUNCOES_

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define VET_FEQ 2 //536
#define TAMANHO_VET 2 //536
#define ALFA 0.1
#define EPOCAS 1000
#define VARIANCIA 0.2

typedef struct neuronio
{
    double pesos[TAMANHO_VET];
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
Neuronio_saida *inicializa_neuronio_saida(int qtd, int tam_camada_oculta)
double F_aux(double *p, double *w, double b, int tam_camada_anterior);
double F_mult(int p, double w);
double F_logistica(double n);
double *inic_peso(double *vet);
double *inic_peso_saida(int qtd);
double inic_deslocamento();
double F_neuronio(double *vet, Neuronio *camada_oculta,int N_camada, Neuronio_saida *camada_saida);
double erro_saida(double esperado, double real);
double d_F_logistica(double x);
double gradiente_saida(double esperado, double real);
double gradiente_camada_oculta(double saida_neuronio, int pos_neu, Neuronio_saida *camada_saida, int tam_camada, double *gradientes);
double diff_pesos(double saida, double gradiente);
double novo_peso(double peso, double saida, double gradiente);
void backpropagation(double *entrada, Neuronio *camada_oculta,int tam_camada_oculta, Neuronio_saida *camada_saida, double esperado);
int libera_rede_neural(double* vet_feat_grama, double* vet_feat_asfalto, double* vet_feat_grama_teste, double* vet_feat_asfalto_teste, Neuronio *camada_oculta, Neuronio_saida *camada_saida);
double mse(double variancia_anterior, double valor_esperado, double valor_real, int epoca);


#endif
