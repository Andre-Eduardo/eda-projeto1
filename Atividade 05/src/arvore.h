/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

//======== Funcoes ========

//Interface
void imprimeMenu();
void opcaoMenu(char opcao);
char validaOpcao(char opcao);

//Principais
void loadTreeFromFile();
void showTree();
void isFull();
void searchValue();
void getHeight();
void removeValue();
void printInOrder();
void printPreOrder();
void printPostOrder();
void balanceTree();

#endif