/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FOLHA elemAtual->filhoDir == NULL && elemAtual->filhoEsq == NULL
#define TEM_1_FILHO elemAtual->filhoDir != NULL && elemAtual->filhoEsq == NULL || elemAtual->filhoDir == NULL && elemAtual->filhoEsq != NULL
#define TEM_2_FILHO elemAtual->filhoDir != NULL && elemAtual->filhoEsq != NULL
#define TEM_FILHO_ESQ elemAtual->filhoEsq != NULL
#define TEM_FILHO_DIR elemAtual->filhoDir != NULL

typedef struct arvore
{
    struct arvore *pai;
    int dado;
    struct arvore *filhoEsq;
    struct arvore *filhoDir;
} arvore;

//======== Funcoes ========

//Interface
void imprimeMenu();
void opcaoMenu(char opcao);
char validaOpcao(char opcao);

//Principais
// void loadTreeFromFile();// hugo
// void showTree();// hugo
void isFull(arvore *tree);         // hercules
void searchValue(arvore *tree);    // hercules
void getHeight(arvore *tree);      // hercules
arvore *removeValue(arvore *tree); // hercules
                                   // void printInOrder(); // hugo
int printPreOrder(arvore *tree);   // andre
int printPostOrder(arvore *tree);  // andre
void balanceTree(arvore *tree);    // andre
void r_direita(arvore *avo, arvore *pai, arvore *filho);// andre
void r_esquerda(arvore *avo, arvore *pai, arvore *filho);//andre
int is_balance(arvore *tree);//andre
void backbone(arvore *root);//andre
void DSW(arvore *tree);// andre
void rotaciona(arvore *tree, int num);//andre
void sair(arvore *tree);

//Básicas
arvore *criaArvoreVazia();
arvore *insereArvore(arvore *tree, int dado);
arvore *buscaArvore(arvore *tree, int busca);
arvore *removeArvore(arvore *tree, int busca);
int alturaArvore(arvore *tree);
int nivelNo(arvore *tree);
int liberaArvore(arvore *tree);
int arvoreCheia(arvore *tree);
void limpabuffer();
char validaSN(char opcao);

#endif
