/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#ifndef _PILHA_H_
#define _PILHA_H_

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct data{
    //Coloque os dados da lista aqui
    char nome[101];

} data;

typedef struct list_enc{
    data dados;
    struct list_enc *prox;
} list_enc;

typedef struct fila{
    list_enc *ini;
    list_enc *fim;
} fila;

fila criaFilaVazia();
fila pushF(fila, data);
fila liberaFila(fila);
data popF(fila*);
int tamanhoFila(fila);

#endif
