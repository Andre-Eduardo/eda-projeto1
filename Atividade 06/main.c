#include "funcoes.h"
#include "identificador_de_solo.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if (argc > 1)
    {
        int num_camada_oculta = atoi(argv[1]);
    }
    else
    {
        puts("inicialize a camada oculta");
        return 1;
    }

    // teste
    Neuronio *n;
    n = inicializa_neuronio(4);
    for (int i = 0; i < 4; i++)
    {
        printf("Neuronio: %d\n", i);
        for (int j = 0; j < 536; j++)
        {
            printf("%2.lf, ", n[i].deslocamento);
        }
        puts("--------- ");
    }
    double *vet;
    vet = (double *)malloc(sizeof(double)*536);
    inic_peso(vet);

    double soma = F_aux(vet, n[0].pesos, n[0].deslocamento);
    printf("soma = %lf\n", soma);
    
      printf("valor = %lf\n", F_logistica(soma));
    free(n);
    return 0;
}
