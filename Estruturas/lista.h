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
lista *appendLista(lista *, elemento );
lista *insereLista(lista *, elemento , int );
lista *insereOrdenado(lista *, elemento );
lista *deletaElemento(lista *, int );
lista *liberaLista(lista *);
lista *acessaElemento(lista *, int );
lista *procuraElemento(lista *, char *);
int tamanhoLista(lista *);
void printLista(lista *);
void printElemento(lista *, int );
int compString(char *,char *);
int ocorrenciaString(char *, char *);
void ftiraBarraN(char *, FILE *);
void tiraBarraN(char *);
void limpabuffer(void);

#endif
