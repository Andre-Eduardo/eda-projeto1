// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista de contatos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContatos.h"

int main(){
    contato *lista;
    elemento hugo[3];

    strcpy(hugo[0].nome, "Hugo");
    strcpy(hugo[0].telefone, "99999-8888");
    strcpy(hugo[0].endereco, "Gama-DF");
    hugo[0].cep=72426070;
    strcpy(hugo[0].nascimento, "30/02/1994");

    strcpy(hugo[1].nome, "Marcelo");
    strcpy(hugo[1].telefone, "77777-8888");
    strcpy(hugo[1].endereco, "New York-DF");
    hugo[1].cep=72426070;
    strcpy(hugo[1].nascimento, "40/02/1994");

    strcpy(hugo[2].nome, "Tesla");
    strcpy(hugo[2].telefone, "99998-8888");
    strcpy(hugo[2].endereco, "Gama-DF");
    hugo[2].cep=72426070;
    strcpy(hugo[2].nascimento, "30/02/1978");

    lista= criaListaVazia();
    lista=insereOrdenado(lista, hugo[0]);
    lista=insereOrdenado(lista, hugo[1]);
    lista=insereOrdenado(lista, hugo[2]);
    lista=insereOrdenado(lista, hugo[2]);
    lista=insereOrdenado(lista, hugo[2]);
    printLista(lista);
    lista=liberaLista(lista);

    return 0;
}
