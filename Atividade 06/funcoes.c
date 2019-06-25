
#include "funcoes.h"

double F_logistica(double n)
{
    double p;
    double e = M_E; // numero de Euler da fuc Math.h
    p = 1 / 1 + pow(e, n * (-1));
    return p;
}
double F_soma(int p, double w)
{
    double s;
    s = p * w;
    return s;
}
double F_aux(int *p, double *w, double b)
{
    double s;

    for (int i = 0; i < VET_FEQ; i++)
    {
        s += F_soma(p[i], w[i]);
    }
    s += b;
    return s;
}
// aloca neuronios e inicializa peso e deslocamento
// entrada: quantidade de neuronios peso
Neuronio *inicializa_neuronio(int qtd)
{
    Neuronio *neu;
    for (int i = 0; i < qtd; i++)
    {
        neu = (Neuronio *)malloc(sizeof(Neuronio) * qtd);
        inic_peso(neu[i].pesos);
        neu[i].deslocamento = inic_deslocamento();
    }
    return neu;
}

double *inic_peso(double *vet){
    for (int i = 0; i < TAMANHO_VET; i++)
    {
        vet[i]= rand()%15000;
    }
    return vet;
    
}
double inic_deslocamento(){
    return rand()%15000;
}