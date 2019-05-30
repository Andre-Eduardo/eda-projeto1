/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista

#include "lista.h"


// Objetivo: Cria lista vazia
// Parâmetro:
// Retorno: ponteiro nulo
lista *criaListaVazia(){
  //Declarações:

  //Instruções:

  return NULL;
}

// Objetivo: Adiciona um contato ao final da lista
// Parâmetro: lista, dados a serem adicionados
// Retorno: lista
lista *appendLista(lista *l, elemento dados){
  //Declarações:
    lista *novaLista;
    lista *elem;
    //Instruções:

    novaLista = (lista *)malloc(sizeof(lista));
    if(novaLista==NULL){
        fprintf(stderr,"Erro ao alocar novo elemento na lista\n");
        return NULL;
    }

    if(l!=NULL){
      for(elem=l; elem->prox!=NULL;elem=elem->prox){}

      novaLista->dados=dados;
      elem->prox=novaLista;
      novaLista->ante=elem;
      novaLista->prox=NULL;
    }else{
      novaLista->dados=dados;
      novaLista->ante=NULL;
      novaLista->prox=NULL;
      l=novaLista;
    }

    return l;
}

// Objetivo: Inserir um contato em uma posição da lista
// Parâmetro: lista, dados do contato a ser adicionado, posição para adicioná-lo
// Retorno: lista
lista *insereLista(lista *l, elemento dados, int pos){
  //Declarações:
  lista *novaLista;
  lista *elem, *fimLista;
  int i;
  //Instruções:

  novaLista = (lista *)malloc(sizeof(lista));
  if(novaLista==NULL){
    fprintf(stderr,"Erro ao alocar novo elemento na lista\n");
    return NULL;
  }
  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar inserir um novo elemento na lista...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  if(l!=NULL){
    for(i=0,elem=l;i<pos && elem!=NULL;i++){
      if(elem->prox==NULL){
        fimLista=elem;
      }
      elem=elem->prox;
    }

    if(elem!=NULL){
      novaLista->dados=dados;
      novaLista->prox=elem;
      novaLista->ante=elem->ante;
      elem->ante=novaLista;
      elem=novaLista->ante;
      if(elem!=NULL){
        elem->prox=novaLista;
      }
    }else{
      novaLista->dados=dados;
      novaLista->prox=NULL;
      novaLista->ante=fimLista;
      fimLista->prox=novaLista;
    }
  }else{
    novaLista->dados=dados;
    novaLista->ante=NULL;
    novaLista->prox=NULL;
    l=novaLista;
  }

  for(;l->ante!=NULL;l=l->ante){}

  return l;
}

// Objetivo: Inserir elemento na lista em ordem alfabética
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
lista *insereOrdenado(lista *l, elemento dados){
  //Declarações:
  lista *elem;
  int i=0;
  //Instruções:

  if(l==NULL){
    return appendLista(l, dados);
  }

  elem=l;

  while(elem!=NULL){
    if(compString(dados.nome, elem->dados.nome)<0){
      return insereLista(l, dados, i);
    }

    elem=elem->prox;
    i++;
  }

  return appendLista(l, dados);
}

// Objetivo: Deletar contato da lista
// Parâmetro: lista, posição a ser deletada
// Retorno: lista
lista *deletaElemento(lista *l, int pos){
  //Declarações:
  lista *elem, *ante, *prox;
  int i;
  //Instruções:

  if(l==NULL){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um elemento na lista...\n\n\nLista não inicializada!!!\n");
    return NULL;
  }
  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um elemento na lista...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  for(i=0,elem=l;i<pos && elem!=NULL; i++){
    elem=elem->prox;
  }
  for(;l->ante!=NULL;l=l->ante){}

  if(i!=pos || elem==NULL){
    fprintf(stderr,"Um erro ocorreu ao tentar deletar um elemento na lista...\n\n\nPosição inválida!!!\n");
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
    l=elem->prox;
    free(elem);
  }

  return l;
}

// Objetivo: Imprime os elementos da lista na tela
// Parâmetro: lista
// Retorno:
void printLista(lista *l){
  //Declarações:
  lista *listaAtual;
  //Instruções:

  if(l==NULL){
    fprintf(stderr, "Não há elementos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for(listaAtual=l; listaAtual!=NULL;listaAtual=listaAtual->prox){
    //Print de todos os elementos dos seus dados
    printf("Nome:%s\n",listaAtual->dados.nome);
  }

  return;
}

// Objetivo: Apagar a lista
// Parâmetro: lista
// Retorno: ponteiro nulo
lista *liberaLista(lista *l){
  //Declarações:
  lista *aux, *aux2;
  //Instruções:

  for(aux=l;aux!=NULL;aux=aux2){
    aux2=aux->prox;
    free(aux);
  }

  return NULL;
}

// Objetivo: Calcula a quantidade de elementos na lista
// Parâmetro: lista
// Retorno: número de elementos da lista
int tamanhoLista(lista *l){
  //Declarações:
  lista *elem;
  int i;
  //Instruções:

  for(i=0, elem=l; elem!=NULL; elem=elem->prox, i++);

  return i;
}

// Objetivo: Imprimir um elemento da lista na tela
// Parâmetro: lista, posição do elemento a ser printado
// Retorno:
void printElemento(lista *l, int pos){
  //Declarações:
  lista *listaAtual;
  int i;
  //Instruções:

  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar mostrar o elemento da lista...\n\n\nPosição inválida!!!\n");
    return;
  }

  if(l==NULL){
    fprintf(stderr, "Não há elementos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for(i=0, listaAtual=l; i<pos && listaAtual!=NULL;i++){
    listaAtual=listaAtual->prox;
  }

  if(listaAtual==NULL){
    fprintf(stderr, "Este elemento não pode ser mostrado pois ele não foi inicializado...\n");
    return;
  }
  //Print de todos os elementos de sua lista
  printf("Nome:%s\n",listaAtual->dados.nome);

  return;
}

// Objetivo: Compara 2 strings, para decidir a ordem alfabética delas
// Parâmetro: 2 strings
// Retorno: 0 se forem iguais, -1 se a string1 for primeira na ordem, e 1 se a string2 for primeira na ordem
int compString(char *string1,char *string2){
  //Declarações:
  int i=0, fim=0, result=0;
  char charA,charB;
  //Instruções:

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

// Objetivo: Acessar um elemento da lista
// Parâmetro: lista, posição a ser acessada
// Retorno: ponteiro para o elemento da lista
lista *acessaElemento(lista *l, int pos){
  //Declarações:
  int i;
  lista *listaAtual;
  //Instruções:

  if(pos<0){
    fprintf(stderr,"Um erro ocorreu ao tentar acessar o elemento da lista...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  if(l==NULL){
    fprintf(stderr,"Não há elementos para acessar porque a lista não foi inicializada...\n");
    return NULL;
  }

  for(i=0, listaAtual=l; i<pos && listaAtual!=NULL;i++){
    listaAtual=listaAtual->prox;
  }

  if(listaAtual==NULL){
    fprintf(stderr, "Este elemento não pode ser mostrado pois ele não foi inicializado...\n");
    return NULL;
  }

  return listaAtual;
}

// Objetivo: Procura elemento na lista com determinada string no nome
// Parâmetro: lista, string a se procurar
// Retorno: ponteiro para o primeiro elemento da lista com a determinada string
lista *procuraElemento(lista *l, char *palavra){
  //Declarações:
  lista *listaAtual;
  //Instruções:

  for(listaAtual=l; listaAtual!=NULL && ocorrenciaString(listaAtual->dados.nome, palavra)==0;){
     listaAtual=listaAtual->prox;
  }

  return listaAtual;
}

// Objetivo: Procura um texto dentro de outro texto
// Parâmetro: texto para se procurar, texto a ser procurado
// Retorno: Número de ocorrências do texto
int ocorrenciaString(char *texto, char *palavra){
  //Declarações:
  int i, aux, sent=1;
  int ocorrencias=0;
  //Instruções:
  for(i=0; *(texto+i)!='\0'; i++){
    if(tolower(*(texto+i))==tolower(*(palavra))){
      sent=0;
      ocorrencias++;
      for(aux=0;sent==0; aux++){
        if( *(palavra+aux)=='\0' ){
          sent=1;
        }else if(*(texto+i+aux)=='\0'){
          sent=1;
          ocorrencias--;
        }else{
          if(tolower(*(texto+i+aux))!=tolower(*(palavra+aux))){
            sent=1;
            ocorrencias--;
          }
        }
      }
    }
  }

  return ocorrencias;
}

// Objetivo: Retirar /n (newline) de uma string, se houver, caso contrário pular até a próxima linha do arquivo
// Parâmetro: string a ser tratada, ponteiro para arquivo
// Retorno:
void ftiraBarraN(char *string, FILE *arq){
  //Declarações:
  char c;
  //Instruções:

  if(string[strlen(string)-1]=='\n')
    string[strlen(string)-1]='\0';
  else{
    while ((c = fgetc(arq)) != '\n' && c != EOF);
  }

  return;
}

// Objetivo: Retirar /n (newline) de uma string, se houver, caso contrário limpar buffer do teclado
// Parâmetro: string a ser tratada
// Retorno:
void tiraBarraN(char *string){
  //Declarações:

  //Instruções:
  if(string[strlen(string)-1]=='\n')
    string[strlen(string)-1]='\0';
  else
    limpabuffer();

  return;
}

// Objetivo: Limpar buffer do teclado
// Parâmetro:
// Retorno:
void limpabuffer(void){
  //Declarações:
  char c;
  //Instruções:
  while ((c = getchar()) != '\n' && c != EOF);
}
