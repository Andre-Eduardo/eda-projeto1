/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/


#include<stdio.h>
#define QUANTIDADE 2

int recebe_notas(float *NOTAS, int num);

int main()
{   float NOTAS[10];
    int num_aprovados;
    printf("Por favor informe as 10 notas:");
    for( int i = 0; i < QUANTIDADE; i++)
    {
        scanf("%f",NOTAS);
    }
    

    printf("Quantidade de aprovados:");
    printf("Quantidade de reprovados:");
    printf("Percentual de aprovados:");
    printf("Percentual de reprovados:");
    printf("mais da metade da turma aprovada:");
    
    return 0;
}
// ========== FUNÇÕES =============

int recebe_notas(float *NOTAS, int num){
    int APR[QUANTIDADE];
    for(int i = 0; i < num; i++)
    {
        if (*(NOTAS+i) >= 6.0 ) {
            APR[i] = 1;
        }else
        {
            APR[1]= 0;
        }
    }
    return APR;


}

void conta_notas(int *APR,int num, int *num_aprovados, int *num_reprovados){
    for(size_t i = 0; i < num; i++)
    {
       if (*(APR + 1) == 1) {
           *num_aprovados =+ 1;
           
       }else
       {
           num_reprovados =+ 1;
       }
       
       
    }
}

int percent_aprov(int *num_aprovados, int *num_reprovados,float *prec_aprovados, float *perc_reprovados){

int total = *num_aprovados + num_reprovados;

prec_aprovados = (*num_aprovados/total)*100;
perc_reprovados = (*num_reprovados/total)*100;

    if ((*prec_aprovados) >= (*perc_reprovados)){
        return 1;

    }else
    {
        return 0;
    }
    

}
