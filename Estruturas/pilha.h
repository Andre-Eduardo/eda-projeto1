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

typedef struct elem{
    //Coloque os dados da lista aqui
    char nome[101];

} elem;

typedef struct pilha{
    struct pilha *ante;
    elem dados;
} pilha;

pilha *criaPilhaVazia();
pilha *push(pilha *, elem);
pilha *liberaPilha(pilha *);
elem pop(pilha**);
int tamanhoPilha(pilha *);

#endif
