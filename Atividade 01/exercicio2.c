/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/


#include<stdio.h>
#define QUANTIDADE 10

int *recebe_notas(float *NOTAS, int num, int *apr);
void conta_notas(int *APR,int num, int *num_aprovados, int *num_reprovados);
int percent_aprov(int num_aprovados, int num_reprovados,float *prec_aprovados, float *perc_reprovados);


int main()
{   float NOTAS[QUANTIDADE];
    float prec_aprovados, perc_reprovados;
    int num_aprovados, num_reprovados;
    int APR[QUANTIDADE], *apr, mais_metade;
   
    

    printf("Por favor informe as 10 notas:\n");
    for( int i = 0; i < QUANTIDADE; i++)
    {
        scanf("%f",&NOTAS[i]);
    }
    
    apr = recebe_notas(NOTAS,QUANTIDADE,APR);
    conta_notas(apr, QUANTIDADE,&num_aprovados,&num_reprovados);
    mais_metade = percent_aprov(num_aprovados,num_reprovados,&prec_aprovados, &perc_reprovados);

   
    printf("Quantidade de aprovados: %d \n",num_aprovados);
    printf("Quantidade de reprovados: %d \n",num_reprovados);
    printf("Percentual de aprovados: %.2f \n", prec_aprovados);
    printf("Percentual de reprovados: %.2f \n", perc_reprovados);
    printf("Mais da metade da turma aprovada: %s \n", mais_metade == 1 ?  "SIM" : "NAO");
    
    return 0;
}
// ========== FUNÇÕES =============

int *recebe_notas(float *NOTAS, int num,int *apr){
    
    for(int i = 0; i < num; i++)
    {
        if (*(NOTAS+i) >= 6.0 ) {
            *(apr + i) = 1;
        }else
        {
            *(apr + i)= 0;
        }
        
    }
    return apr;


}

void conta_notas(int *APR,int num, int *num_aprovados, int *num_reprovados){
    *num_aprovados = 0;
    *num_reprovados = 0;
    for(size_t i = 0; i < num; i++)
    {
        
       if (*(APR + i) == 1) {
           *num_aprovados += 1;
           
       }else
       {
           *num_reprovados += 1;
           
       }
       
       
    }
}

int percent_aprov(int num_aprovados, int num_reprovados,float *prec_aprovados, float *perc_reprovados){

float total = num_aprovados + num_reprovados;


*prec_aprovados = (num_aprovados/total)*100;
*perc_reprovados = (num_reprovados/total)*100;

    if ((*prec_aprovados) >= (*perc_reprovados)){
        return 1;

    }else
    {
        return 0;
    }
    

}
