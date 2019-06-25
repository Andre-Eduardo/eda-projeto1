#include "funcoes.h"
#include <stdio.h>
int main(int argc, char const *argv[])

{   if(argc > 1){
    int num_camada_oculta = atoi(argv[1]);
}else{
    puts("inicialize a camada oculta");
    return 1;
}
    
    return 0;
}
