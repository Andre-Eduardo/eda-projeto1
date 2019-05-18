// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista de contatos

#include "listaContatos.h"


// Objetivo: Cria lista vazia
// Parâmetro:
// Retorno: ponteiro nulo
contato *criaListaVazia()
{
    return NULL;
}

// Objetivo: Adiciona um contato ao final da lista
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
contato *appendContato(contato *lista, elemento dados){
    contato *novoContato;
    contato *elem;

    novoContato = (contato *)malloc(sizeof(contato));
    if(novoContato==NULL){
        fprintf(stderr,"Erro ao alocar novo contato\n");
        return NULL;
    }

    if(lista!=NULL){
      for(elem=lista; elem->prox!=NULL;elem=elem->prox){}

      novoContato->dados=dados;
      elem->prox=novoContato;
      novoContato->ante=elem;
      novoContato->prox=NULL;
    }else{
      novoContato->dados=dados;
      novoContato->ante=NULL;
      novoContato->prox=NULL;
      lista=novoContato;
    }

    return lista;
}

// Objetivo: Inserir um contato em uma posição da lista
// Parâmetro: lista, dados do contato a ser adicionado, posição para adicioná-lo
// Retorno: lista
contato *insereContato(contato *lista, elemento dados, int pos){
  contato *novoContato;
  contato *elem, *fimLista;
  int i;

  novoContato = (contato *)malloc(sizeof(contato));
  if(novoContato==NULL){
    fprintf(stderr,"Erro ao alocar novo contato\n");
    return NULL;
  }
  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar inserir um novo contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  if(lista!=NULL){
    for(i=0,elem=lista;i<pos && elem!=NULL;i++){
      if(elem->prox==NULL){
        fimLista=elem;
      }
      elem=elem->prox;
    }

    if(elem!=NULL){
      novoContato->dados=dados;
      novoContato->prox=elem;
      novoContato->ante=elem->ante;
      elem->ante=novoContato;
      elem=novoContato->ante;
      if(elem!=NULL){
        elem->prox=novoContato;
      }
    }else{
      novoContato->dados=dados;
      novoContato->prox=NULL;
      novoContato->ante=fimLista;
      fimLista->prox=novoContato;
    }
  }else{
    novoContato->dados=dados;
    novoContato->ante=NULL;
    novoContato->prox=NULL;
    lista=novoContato;
  }

  for(;lista->ante!=NULL;lista=lista->ante){}

  return lista;
}

// Objetivo: Inserir elemento na lista em ordem alfabética
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
contato *insereOrdenado(contato *lista, elemento dados){
  contato *elem;
  int i=0;

  if(lista==NULL){
    return appendContato(lista, dados);
  }

  elem=lista;

  while(elem!=NULL){
    if(compString(dados.nome, elem->dados.nome)<0){
      return insereContato(lista, dados, i);
    }

    elem=elem->prox;
    i++;
  }

  return appendContato(lista, dados);
}

// Objetivo: Deletar contato da lista
// Parâmetro: lista, posição a ser deletada
// Retorno: lista
contato *deletaElemento(contato *lista, int pos){
  contato *elem, *ante, *prox;
  int i;

  if(lista==NULL){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um contato...\n\n\nLista não inicializada!!!\n");
    return NULL;
  }
  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  for(i=0,elem=lista;i<pos && elem!=NULL; i++){
    elem=elem->prox;
  }

  if(i!=pos || elem==NULL){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  prox=elem->prox;
  ante=elem->ante;

  if(ante!=NULL){
    ante->prox=elem->prox;
  }

  if(prox!=NULL){
    prox->ante=elem->ante;
  }

  if(ante!=NULL){
    free(elem);
  }else{
    lista=elem->prox;
    free(elem);
  }

  return lista;
}

// Objetivo: Imprime os elementos da lista na tela
// Parâmetro: lista
// Retorno:
void printLista(contato *lista){
  contato *contatoAtual;

  if(lista==NULL){
    printf("Não há contatos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for(contatoAtual=lista; contatoAtual!=NULL;contatoAtual=contatoAtual->prox){
    printf("Nome:%s\n",contatoAtual->dados.nome);
    printf("Telefone:%s\n",contatoAtual->dados.telefone);
    printf("Endereço:%s\n",contatoAtual->dados.endereco);
    printf("CEP:%d\n",contatoAtual->dados.cep);
    printf("Nascimento:%s\n\n",contatoAtual->dados.nascimento);
  }

  return;
}

// Objetivo: Apagar a lista
// Parâmetro: lista
// Retorno: ponteiro nulo
contato *liberaLista(contato *lista){
  contato *aux, *aux2;

  for(aux=lista;aux!=NULL;aux=aux2){
    aux2=aux->prox;
    free(aux);
  }

  return NULL;
}

// Objetivo: Calcula a quantidade de elementos na lista
// Parâmetro: lista
// Retorno: número de elementos da lista
int tamanhoLista(contato *lista){
  contato *elem;
  int i;

  for(i=0, elem=lista; elem!=NULL; elem=elem->prox, i++);

  return i;
}

// Objetivo: Imprimir um elemento da lista na tela
// Parâmetro: lista, posição do elemento a ser printado
// Retorno:
void printElemento(contato *lista, int pos){
  contato *contatoAtual;
  int i;

  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar mostrar o contato...\n\n\nPosição inválida!!!\n");
    return;
  }

  if(lista==NULL){
    printf("Não há contatos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for(i=0, contatoAtual=lista; i<pos && contatoAtual!=NULL;i++){
    contatoAtual=contatoAtual->prox;
  }

  if(contatoAtual==NULL){
    printf("Este contato não pode ser mostrado pois ele não foi inicializado...\n");
    return;
  }

  printf("Nome:%s\n",contatoAtual->dados.nome);
  printf("Telefone:%s\n",contatoAtual->dados.telefone);
  printf("Endereço:%s\n",contatoAtual->dados.endereco);
  printf("CEP:%d\n",contatoAtual->dados.cep);
  printf("Nascimento:%s\n\n",contatoAtual->dados.nascimento);

  return;
}

// Objetivo: Compara 2 strings, para decidir a ordem alfabética delas
// Parâmetro: 2 strings
// Retorno: 0 se forem iguais, -1 se a string1 for primeira na ordem, e 1 se a string2 for primeira na ordem
int compString(char *string1,char *string2){
  int i=0, fim=0, result=0;
  char charA,charB;

  while(*(string1+i)!='\0' && *(string2+i)!='\0' && fim==0){
    charA=tolower(*(string1+i));
    charB=tolower(*(string2+i));
    if(charA==charB){
      i++;
    }else if(charA>charB){
      fim=1;
      result=1;
    }else{
      fim=1;
      result=-1;
    }
  }

  if(*(string1+i)=='\0' && *(string2+i)!='\0'){
    result=-1;
  }else if(*(string2+i)=='\0' && *(string1+i)!='\0'){
    result=1;
  }

  return result;
}
