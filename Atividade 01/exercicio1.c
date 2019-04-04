/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int fneuronio(float *entradas, float *pesos, float tamanho, float limiar);

int main(){
    float entradas[MAX], pesos[MAX];
    float limiar;
    int aux;
    puts("Ola!!");
    for(aux=0; aux<MAX; aux++){
        printf("Insira o %dº número do vetor de ENTRADAS\n", aux+1);
        scanf("%f", (entradas+aux));
        system("clear");
    }
    for(aux=0; aux<MAX; aux++){
        printf("Insira o %dº número do vetor de PESOS\n", aux+1);
        scanf("%f", (pesos+aux));
        system("clear");
    }

    printf("Insira um número para o limiar T\n");
    scanf("%f", &limiar);
    system("clear");

    if(fneuronio(entradas, pesos, MAX, limiar))
        printf("Neurônio ativado!");
    else
        printf("Neurônio inibido!");

    return 0;
}

int fneuronio(float *entradas, float *pesos, float tamanho, float limiar){
    float somap=0;
    int aux;

    for(aux=0; aux<tamanho; aux++)
        somap += (entradas[aux])*(pesos[aux]);

    if(somap>limiar)
        return 1;
    else
        return 0;
}
