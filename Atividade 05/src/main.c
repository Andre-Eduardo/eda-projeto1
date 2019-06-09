/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    arvore *tree=NULL;
    arvore *elem;
    // puts("Bem vindo a ferramenta de manipulacao de arvores!");
    // getchar();
    // imprimeMenu();

    tree=insereArvore(tree, 10);
    tree=insereArvore(tree, 11);
    tree=insereArvore(tree, 20);
    tree=insereArvore(tree, 26);
    tree=insereArvore(tree, 5);
    tree=insereArvore(tree, 9);
    tree=insereArvore(tree, 4);
    tree=insereArvore(tree, 1);
    tree=insereArvore(tree, 7);
    tree=insereArvore(tree, 80);
    elem=tree;
    printf("      %d\n", tree->dado);
    printf("     /  \\\n");
    elem=tree->filhoEsq;
    printf("    %d", elem->dado);
    elem=tree->filhoDir;
    printf("    %d\n", elem->dado);
    printf("   / \\     \\  \n");
    elem=tree->filhoEsq->filhoEsq;
    printf("  %d", elem->dado);
    elem=tree->filhoEsq->filhoDir;
    printf("   %d", elem->dado);
    elem=tree->filhoDir->filhoDir;
    printf("     %d\n", elem->dado);

    printf("\n\n\n\n%d\n\n", alturaArvore(tree));

    printf("\n\n      %d\n", tree->dado);
    printf("     /  \\\n");
    elem=tree->filhoEsq;
    printf("    %d", elem->dado);
    elem=tree->filhoDir;
    printf("    %d\n", elem->dado);
    printf("   / \\     \\  \n");
    elem=tree->filhoEsq->filhoEsq;
    printf("  %d", elem->dado);
    elem=tree->filhoEsq->filhoDir;
    printf("   %d", elem->dado);
    elem=tree->filhoDir->filhoDir;
    printf("     %d\n", elem->dado);


    if(liberaArvore(tree)){
      printf("erro...\n");
    }


    return 0;
}
