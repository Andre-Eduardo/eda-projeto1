#ifndef _LISTACONTATOS_H_
#define _LCD_H_

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista de contatos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct elemento{

    char nome[101];
    char telefone[11];
    char endereco[101];
    unsigned int cep;
    char nascimento[11];

} elemento;

typedef struct contato{
    struct contato *ante;
    elemento dados;
    struct contato *prox;
} contato;

contato *criaListaVazia();
contato *appendContato(contato *lista, elemento dados);
contato *insereContato(contato *lista, elemento dados, int pos);
contato *insereOrdenado(contato *lista, elemento dados);
contato *deletaElemento(contato *lista, int pos);
contato *liberaLista(contato *lista);
contato *acessaElemento(contato *lista, int pos);
contato *procuraElemento(contato *lista, char *palavra);
int tamanhoLista(contato *lista);
void printLista(contato *lista);
void printElemento(contato *lista, int pos);
int compString(char *string1,char *string2);
void ler_arq(contato *lista);
int ocorrenciaString(char *texto, char *palavra);

#endif
