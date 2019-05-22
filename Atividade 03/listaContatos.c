// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista de contatos

#include "listaContatos.h"

// Objetivo: Cria lista vazia
// Parâmetro:
// Retorno: ponteiro nulo
contato *criaListaVazia()
{
  //Declarações:

  //Instruções:

  return NULL;
}

// Objetivo: Adiciona um contato ao final da lista
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
contato *appendContato(contato *lista, elemento dados)
{
  //Declarações:
  contato *novoContato;
  contato *elem;
  //Instruções:

  novoContato = (contato *)malloc(sizeof(contato));
  if (novoContato == NULL)
  {
    fprintf(stderr, "Erro ao alocar novo contato\n");
    return NULL;
  }

  if (lista != NULL)
  {
    for (elem = lista; elem->prox != NULL; elem = elem->prox)
    {
    }

    novoContato->dados = dados;
    elem->prox = novoContato;
    novoContato->ante = elem;
    novoContato->prox = NULL;
  }
  else
  {
    novoContato->dados = dados;
    novoContato->ante = NULL;
    novoContato->prox = NULL;
    lista = novoContato;
  }

  return lista;
}

// Objetivo: Inserir um contato em uma posição da lista
// Parâmetro: lista, dados do contato a ser adicionado, posição para adicioná-lo
// Retorno: lista
contato *insereContato(contato *lista, elemento dados, int pos)
{
  //Declarações:
  contato *novoContato;
  contato *elem, *fimLista;
  int i;
  //Instruções:

  novoContato = (contato *)malloc(sizeof(contato));
  if (novoContato == NULL)
  {
    fprintf(stderr, "Erro ao alocar novo contato\n");
    return NULL;
  }
  if (pos < 0)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar inserir um novo contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  if (lista != NULL)
  {
    for (i = 0, elem = lista; i < pos && elem != NULL; i++)
    {
      if (elem->prox == NULL)
      {
        fimLista = elem;
      }
      elem = elem->prox;
    }

    if (elem != NULL)
    {
      novoContato->dados = dados;
      novoContato->prox = elem;
      novoContato->ante = elem->ante;
      elem->ante = novoContato;
      elem = novoContato->ante;
      if (elem != NULL)
      {
        elem->prox = novoContato;
      }
    }
    else
    {
      novoContato->dados = dados;
      novoContato->prox = NULL;
      novoContato->ante = fimLista;
      fimLista->prox = novoContato;
    }
  }
  else
  {
    novoContato->dados = dados;
    novoContato->ante = NULL;
    novoContato->prox = NULL;
    lista = novoContato;
  }

  for (; lista->ante != NULL; lista = lista->ante)
  {
  }

  return lista;
}

// Objetivo: Inserir elemento na lista em ordem alfabética
// Parâmetro: lista, dados do contato a ser adicionado
// Retorno: lista
contato *insereOrdenado(contato *lista, elemento dados)
{
  //Declarações:
  contato *elem;
  int i = 0;
  //Instruções:

  if (lista == NULL)
  {
    return appendContato(lista, dados);
  }

  elem = lista;

  while (elem != NULL)
  {
    if (compString(dados.nome, elem->dados.nome) < 0)
    {
      return insereContato(lista, dados, i);
    }

    elem = elem->prox;
    i++;
  }

  return appendContato(lista, dados);
}

// Objetivo: Deletar contato da lista
// Parâmetro: lista, posição a ser deletada
// Retorno: lista
contato *deletaElemento(contato *lista, int pos)
{
  //Declarações:
  contato *elem, *ante, *prox;
  int i;
  //Instruções:

  if (lista == NULL)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar deletar um contato...\n\n\nLista não inicializada!!!\n");
    return NULL;
  }
  if (pos < 0)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar deletar um contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  for (i = 0, elem = lista; i < pos && elem != NULL; i++)
  {
    elem = elem->prox;
  }

  if (i != pos || elem == NULL)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar deletar um contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  prox = elem->prox;
  ante = elem->ante;

  if (ante != NULL)
  {
    ante->prox = elem->prox;
  }

  if (prox != NULL)
  {
    prox->ante = elem->ante;
  }

  if (ante != NULL)
  {
    free(elem);
  }
  else
  {
    lista = elem->prox;
    free(elem);
  }

  return lista;
}

// Objetivo: Imprime os elementos da lista na tela
// Parâmetro: lista
// Retorno:
void printLista(contato *lista)
{
  //Declarações:
  contato *contatoAtual;
  //Instruções:

  if (lista == NULL)
  {
    fprintf(stderr, "Não há contatos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for (contatoAtual = lista; contatoAtual != NULL; contatoAtual = contatoAtual->prox)
  {
    printf("Nome:%s\n", contatoAtual->dados.nome);
    printf("Telefone:%s\n", contatoAtual->dados.telefone);
    printf("Endereço:%s\n", contatoAtual->dados.endereco);
    printf("CEP:%d\n", contatoAtual->dados.cep);
    printf("Nascimento:%s\n\n", contatoAtual->dados.nascimento);
  }

  return;
}

// Objetivo: Apagar a lista
// Parâmetro: lista
// Retorno: ponteiro nulo
contato *liberaLista(contato *lista)
{
  //Declarações:
  contato *aux, *aux2;
  //Instruções:

  for (aux = lista; aux != NULL; aux = aux2)
  {
    aux2 = aux->prox;
    free(aux);
  }

  return NULL;
}

// Objetivo: Calcula a quantidade de elementos na lista
// Parâmetro: lista
// Retorno: número de elementos da lista
int tamanhoLista(contato *lista)
{
  //Declarações:
  contato *elem;
  int i;
  //Instruções:

  for (i = 0, elem = lista; elem != NULL; elem = elem->prox, i++)
    ;

  return i;
}

// Objetivo: Imprimir um elemento da lista na tela
// Parâmetro: lista, posição do elemento a ser printado
// Retorno:
void printElemento(contato *lista, int pos)
{
  //Declarações:
  contato *contatoAtual;
  int i;
  //Instruções:

  if (pos < 0)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar mostrar o contato...\n\n\nPosição inválida!!!\n");
    return;
  }

  if (lista == NULL)
  {
    fprintf(stderr, "Não há contatos para mostrar porque a lista não foi inicializada...\n");
    return;
  }

  for (i = 0, contatoAtual = lista; i < pos && contatoAtual != NULL; i++)
  {
    contatoAtual = contatoAtual->prox;
  }

  if (contatoAtual == NULL)
  {
    fprintf(stderr, "Este contato não pode ser mostrado pois ele não foi inicializado...\n");
    return;
  }

  printf("Nome:%s\n", contatoAtual->dados.nome);
  printf("Telefone:%s\n", contatoAtual->dados.telefone);
  printf("Endereço:%s\n", contatoAtual->dados.endereco);
  printf("CEP:%d\n", contatoAtual->dados.cep);
  printf("Nascimento:%s\n\n", contatoAtual->dados.nascimento);

  return;
}

// Objetivo: Compara 2 strings, para decidir a ordem alfabética delas
// Parâmetro: 2 strings
// Retorno: 0 se forem iguais, -1 se a string1 for primeira na ordem, e 1 se a string2 for primeira na ordem
int compString(char *string1, char *string2)
{
  //Declarações:
  int i = 0, fim = 0, result = 0;
  char charA, charB;
  //Instruções:

  while (*(string1 + i) != '\0' && *(string2 + i) != '\0' && fim == 0)
  {
    charA = tolower(*(string1 + i));
    charB = tolower(*(string2 + i));
    if (charA == charB)
    {
      i++;
    }
    else if (charA > charB)
    {
      fim = 1;
      result = 1;
    }
    else
    {
      fim = 1;
      result = -1;
    }
  }

  if (*(string1 + i) == '\0' && *(string2 + i) != '\0')
  {
    result = -1;
  }
  else if (*(string2 + i) == '\0' && *(string1 + i) != '\0')
  {
    result = 1;
  }

  return result;
}

// Objetivo: Acessar um elemento da lista
// Parâmetro: lista, posição a ser acessada
// Retorno: ponteiro para o elemento da lista
contato *acessaElemento(contato *lista, int pos)
{
  //Declarações:
  int i;
  contato *contatoAtual;
  //Instruções:
  if (pos < 0)
  {
    fprintf(stderr, "Um erro ocorreu ao tentar acessar o contato...\n\n\nPosição inválida!!!\n");
    return NULL;
  }

  if (lista == NULL)
  {
    fprintf(stderr, "Não há contatos para acessar porque a lista não foi inicializada...\n");
    return NULL;
  }

  for (i = 0, contatoAtual = lista; i < pos && contatoAtual != NULL; i++)
  {
    contatoAtual = contatoAtual->prox;
  }

  if (contatoAtual == NULL)
  {
    fprintf(stderr, "Este contato não pode ser mostrado pois ele não foi inicializado...\n");
    return NULL;
  }

  return contatoAtual;
}

// Objetivo: buscar dados do arquivo
// Parâmetro: ponteiro para uma lista,
// Retorno: lista com valores obtidos do arquivo
void ler_arq(contato *lista)
{
  int quantidade = 0;
  FILE *arq;
  char string[100];
  char *separador;
  elemento dados;
  arq = fopen("contato.txt", "rt");
  while (!feof(arq))
  {
    separador = fgets(string, 2, arq);
    if ((*separador == '$'))
    {
      quantidade += 1;
    }
  }
  fclose(arq);
  arq = fopen("contato.txt", "rt");
  if (arq == NULL)
  {
    printf("Problemas na leitura do arquivo\n");
    return;
  }

  for (size_t i = 0; i < quantidade; i++)
  {
    // Lê uma linha (inclusive com o '\n')
     sprintf( dados.nome, "%s",fgets(string, 100, arq));
     sprintf( dados.telefone, "%s",fgets(string, 12, arq));
     sprintf( dados.endereco, "%s",fgets(string, 102, arq));
     dados.cep = atoi(fgets(string, 100, arq));
     sprintf( dados.nascimento, "%s",fgets(string, 12, arq));
    separador = fgets(string, 2, arq);
    appendContato(lista, dados);
  }

  fclose(arq);
}