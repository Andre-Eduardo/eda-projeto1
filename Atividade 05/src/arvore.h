/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

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
                                   // void printPreOrder();// andre
void printPostOrder(arvore *tree);             // andre
void balanceTree(arvore *tree);    // andre
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
