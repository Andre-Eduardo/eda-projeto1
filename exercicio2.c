#include<stdio.h>
#define QUANTIDADE 2
int main()
{   float NOTAS[10];
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