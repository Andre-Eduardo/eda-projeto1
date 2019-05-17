#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{

    char nome[101];
    char telefone[11];
    char endereco[101];
    unsigned int cep;
    char nascimento[11];

} elemento;

typedef struct contato
{
    struct contato *ante;
    elemento dados;
    struct contato *prox;
} contato;

contato *criaListaVazia();
contato *appendContato();

int main()
{

    return 0;
}

contato *criaListaVazia()
{
    return NULL;
}
contato *appendContato(contato *lista, elemento dados)
{
    contato *novoContato;
    contato *elem;

    novoContato = (contato *)malloc(sizeof(contato));

    if(novoContato==NULL){
        printf("Erro ao alocar novo contato\n");
        exit(-1);
    }

    for(elem=lista; elem->prox!=NULL;elem=elem->prox){}
    
    novoContato->dados=dados;
    elem->prox=novoContato;
    novoContato->ante=elem;
    novoContato->prox=NULL;

    return lista;
}