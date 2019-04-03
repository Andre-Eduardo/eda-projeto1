#include <stdio.h>

void resolve(int n, char atual, char final, char intermediaria){
    if (n == 1) {
        printf("\nMover o disco 1 da torre %c para a torre %c", atual, final);
        return;
    }
    
    resolve(n-1, atual, intermediaria, final);
    printf("\nMover o disco %d da torre %c para a torre %c", n, atual, final);
    resolve(n-1, intermediaria, final, atual);
};

int main(){
    int discos;

    printf("\t\tCalculadora de Hanoi\n\n");

    printf("Digite a quantidade de discos: ");
    scanf("%d", &discos);
    resolve(discos, 'A', 'C', 'B');

    return 0;
}
