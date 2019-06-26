#include "identificador_de_solo.h"
#include <stdio.h>

int main(){
    double* vet_feat_grama;
    double* vet_feat_asfalto;
    double* vet_feat_grama_teste; 
    double* vet_feat_asfalto_teste;

    retira_features(&vet_feat_grama, &vet_feat_asfalto, &vet_feat_grama_teste, &vet_feat_asfalto_teste);
    for(int i=0; i<10; i++){
        printf("%lf\n", *(vet_feat_grama+i));
    }
    return 0;
}