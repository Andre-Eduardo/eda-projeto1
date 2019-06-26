#include "funcoes.h"
#include "identificador_de_solo.h"
#include <stdio.h>
int main(int argc, char const *argv[]){
    //Declarações
    int num_camada_oculta;
    double* vet_feat_grama;
    double* vet_feat_asfalto; 
    double* vet_feat_grama_teste;
    double* vet_feat_asfalto_teste;
    Neuronio *n,n2,n_f;
    //Instruções

    srand(time(NULL));
    if (argc > 1)
    {
        num_camada_oculta = atoi(argv[1]);
    }
    else
    {
        puts("inicialize a camada oculta");
        return 1;
    }



    n = inicializa_neuronio(VET_FEQ);// quantidade da primera camada/
    n2 = inicializa_neuronio(num_camada_oculta); // numero de neuronios na camada oculta;
    n_f = inicializa_neuronio(1); // ultima camada da rede neural
    
    // teste
   
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
