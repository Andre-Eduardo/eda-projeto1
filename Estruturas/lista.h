/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#ifndef _LISTA_H_
#define _LISTA_H_

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct elemento{
    //Coloque os dados da lista aqui
    char nome[101];

} elemento;

typedef struct lista{
    struct lista *ante;
    elemento dados;
    struct lista *prox;
} lista;

lista *criaListaVazia();
lista *appendLista(lista *lista, elemento dados);
lista *insereLista(lista *lista, elemento dados, int pos);
lista *insereOrdenado(lista *lista, elemento dados);
lista *deletaElemento(lista *lista, int pos);
lista *liberaLista(lista *lista);
lista *acessaElemento(lista *lista, int pos);
lista *procuraElemento(lista *lista, char *palavra);
int tamanhoLista(lista *lista);
void printLista(lista *lista);
void printElemento(lista *lista, int pos);
int compString(char *string1,char *string2);
int ocorrenciaString(char *texto, char *palavra);
void ftiraBarraN(char *string, FILE *arq);
void tiraBarraN(char *string);
void limpabuffer(void);

#endif
