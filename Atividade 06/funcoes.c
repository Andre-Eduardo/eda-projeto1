
#include"funcoes.h"

double F_logistica(double n){
    double p;
    double e = M_E; // numero de Euler da fuc Math.h
    p = 1/ 1+pow(e,n*(-1));
    return p;
}
double F_soma(int p, double w){
    double s;
    s = p*w;
    return s;

}
double F_aux(int *p, double *w, double b){
    double s;
    
    for (int i = 0; i < VET_FEQ; i++)
    {
        s += F_soma(p[i],w[i]);
        
    }
    s+=b;
    return s;
    
}