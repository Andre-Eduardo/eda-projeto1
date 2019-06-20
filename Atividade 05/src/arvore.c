/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#include "arvore.h"

//Objetivo: mostrar menu na tela
void imprimeMenu()
{
  system("clear");
  puts("Selecione a ferramenta desejada digitando o número correpondente...");
  puts("0. Load Tree From File");   //Hugo
  puts("1. Show Tree");             //Hugo
  puts("2. Is Full");
  puts("3. Search Value");
  puts("4. Get Height");
  puts("5. Remove Value");          //Hércules
  puts("6. Print In Order");        //Hugo
  puts("7. Print Pre-Order");
  puts("8. Print Post-Order");
  puts("9. Balance Tree");
  puts("s. Sair");                 //Hercules

  return;
}

//Objetivo: receber a opcao do menu digitada pelo usuario
void opcaoMenu(){
    arvore *tree=NULL;
    int sent = 1;
    char opcao;

    while(sent){
    imprimeMenu();
    opcao = validaOpcao(opcao);
    char *cep;

    switch(opcao){
    case '0':
        cep = loadFile();
        tree=loadTreeFromFile(tree, cep);
        break;
    case '1':
        system("clear");
        showTree(tree, 0);
        puts("\n\nAperte qualquer coisa para continuar...");
        limpabuffer();
        break;
    case '2':
        isFull(tree);
        break;
    case '3':
        searchValue(tree);
        break;
    case '4':
        getHeight(tree);
        break;
    case '5':
        tree=removeValue(tree);
        break;
    case '6':
        preOrder(tree);
        break;
    case '7':
        preOrder(tree);
        break;
    case '8':
        postOrder(tree);
        break;
    case '9':
        //balanceTree();
        break;
    case 's':
        sair(tree);
        break;
    default:        //WARNING => 'stderr' deve ser declarado
        fprintf(stderr, "Um erro inesperado aconteceu...\n\n\nO programa será desligado\n");
        exit(-1);
    }
  }
}

//Objetivo: validar opcao do menu
char validaOpcao(char opcao){
        opcao = getchar();

        limpabuffer();

        while(opcao!='0' && opcao!='1' && opcao!='2' && opcao!='3'
              && opcao!='4' && opcao!= '5' && opcao!= '6' && opcao!= '7'
              && opcao!= '8'&& opcao!= '9' && opcao!= 's'){
                puts("\n\n\n\nOpção inválida!(digite um número entre 0 e 9 ou s)");
                opcao = getchar();
                limpabuffer();
        }
        return opcao;
}
//Objetivo: validar opcao do menu de arquivos
char validaOpcaoFile(char opcao){
        opcao = getchar();

        limpabuffer();

        while(opcao!='1' && opcao!='2' && opcao!='3' && opcao!='4'
              && opcao!='5' && opcao!= '6'){
                puts("\n\n\n\nOpção inválida!(digite um número entre 0 e 6)");
                opcao = getchar();
                limpabuffer();
        }
        return opcao;
}

// Objetivo: Cria árvore vazia
// Parâmetro:
// Retorno: ponteiro nulo
arvore *criaArvoreVazia(){

  return NULL;
}
//Carrega arquivo
char *loadFile(){
  char opcao;

  system("clear");
  puts("Digite o numero do arquivo que deseja abrir: ");
  puts("1 - bst1.txt");
  puts("2 - bst2.txt");
  puts("3 - bst3.txt");
  puts("4 - bst4.txt");
  puts("5 - bst5.txt");
  puts("6 - bst6.txt");

  opcao = validaOpcaoFile(opcao);
  switch(opcao){
    case '1':
      return "../BSTs/bst1.txt";
      break;
    case '2':
      return "../BSTs/bst2.txt";
      break;
    case '3':
      return "../BSTs/bst3.txt";
      break;
    case '4':
      return "../BSTs/bst4.txt";
      break;
    case '5':
      return "../BSTs/bst5.txt";
      break;
    case '6':
      return "../BSTs/bst6.txt";
      break;
    default:
      fprintf(stderr, "Um erro inesperado aconteceu...\n\n\nO programa será desligado\n");
        exit(-1);
  }

}

//Carrega arvore apartir de arquivo
arvore *loadTreeFromFile(arvore *tree, char *cep){
  FILE *txt;
  int valor;

  if(tree!=NULL)
    liberaArvore(tree);

  tree=criaArvoreVazia();

  txt = fopen(cep, "r");//abre no modo leitura sendo cep o endereco
  if(txt == NULL){//o modo r requer existencia de um arquivo
    printf("Arquivo inexistente...\n");
    exit(1);
  }else{
      while(!feof(txt)){
        fscanf(txt, "%d", &valor);
        tree=insereArvore(tree, valor);
      }
  }
  fclose(txt);

  system("clear");

  if(tree!=NULL)
    puts("Árvore carregada com sucesso");
  else
    puts("Um erro ocorreu ao carregar a árvore do arquivo...");

  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return tree;
}

//Mostrar Arvore
void showTree(arvore *tree, int space){
  if(tree == NULL)
      return;
  space += 10;

  showTree(tree->filhoDir, space);

  printf("\n");
  for(int i = 10; i < space; i++){
      printf(" ");
  }
  printf("%d\n", tree->dado);

  showTree(tree->filhoEsq, space);
}
//Prita raiz
void printRaiz(arvore *tree){
  showTree(tree, 0);
}

// Objetivo: Inserir um elemento na árvore
// Parâmetro: árvore, dado ser adicionado
// Retorno: árvore
arvore *insereArvore(arvore *tree, int dado)
{
  //Declarações:
  arvore *novoElem;
  arvore *elemAtual;
  arvore *prox;
  int sent = 1, esqDir;
  //Instruções:

  novoElem = (arvore *)malloc(sizeof(arvore));
  if (novoElem == NULL)
  {
    fprintf(stderr, "Erro ao alocar novo elemento na árvore\n");
    return NULL;
  }

  novoElem->dado = dado;
  novoElem->filhoEsq = NULL;
  novoElem->filhoDir = NULL;

  if (tree == NULL)
  {
    novoElem->pai = NULL;
    return novoElem;
  }
  else
  {
    elemAtual = tree;
    while (sent)
    {
      if (novoElem->dado > elemAtual->dado)
      {
        esqDir = 1;
        prox = elemAtual->filhoDir;
      }
      else
      {
        esqDir = 0;
        prox = elemAtual->filhoEsq;
      }

      if (prox == NULL)
      {
        if (esqDir)
        {
          elemAtual->filhoDir = novoElem;
          novoElem->pai = elemAtual;
        }
        else
        {
          elemAtual->filhoEsq = novoElem;
          novoElem->pai = elemAtual;
        }

        sent = 0;
      }
      else
      {
        elemAtual = prox;
      }
    }
  }

  return tree;
}

// Objetivo: Busca elemento na árvore
// Parâmetro: árvore, e elemento a ser buscado
// Retorno: ponteiro para o elemento da árvore com o valor buscado(se não achar retorna NULL)
arvore *buscaArvore(arvore *tree, int busca)
{
  //Declarações:
  arvore *elemAtual;
  int sent = 1;
  //Instruções:
  if (tree == NULL)
  {
    return NULL;
  }

  elemAtual = tree;

  while (elemAtual != NULL)
  {
    if (busca < elemAtual->dado)
    {
      elemAtual = elemAtual->filhoEsq;
    }
    else if (busca > elemAtual->dado)
    {
      elemAtual = elemAtual->filhoDir;
    }
    else
    {
      return elemAtual;
    }
  }

  return NULL;
}

// Objetivo: remove elemento na árvore
// Parâmetro: árvore, e elemento a ser removido
// Retorno: ponteiro para o elemento da árvore com o valor removido
arvore *removeArvore(arvore *tree, int busca)
{
  //Declarações:
  arvore *elemAtual;
  arvore *aux;
  int herdeiro;
  //Instruções:
  elemAtual = buscaArvore(tree, busca);

  if (FOLHA)
  {
    aux = elemAtual->pai;
    if (aux != NULL)
    {
      if (aux->filhoDir == elemAtual)
        aux->filhoDir = NULL;
      else
        aux->filhoEsq = NULL;
    }
    else
    {
      tree = NULL;
    }
    free(elemAtual);
  }
  else if (TEM_1_FILHO)
  {
    aux = elemAtual->pai;
    if (aux != NULL)
    {
      if (aux->filhoDir == elemAtual)
      {
        if (elemAtual->filhoDir == NULL)
        {
          aux->filhoDir = elemAtual->filhoEsq;
          elemAtual->filhoEsq->pai = aux;
        }
        else
        {
          aux->filhoDir = elemAtual->filhoDir;
          elemAtual->filhoDir->pai = aux;
        }
      }
      else
      {
        if (elemAtual->filhoDir == NULL)
        {
          aux->filhoEsq = elemAtual->filhoEsq;
          elemAtual->filhoEsq->pai = aux;
        }
        else
        {
          aux->filhoEsq = elemAtual->filhoDir;
          elemAtual->filhoDir->pai = aux;
        }
      }
    }
    else
    {
      if (elemAtual->filhoDir == NULL)
      {
        elemAtual->filhoEsq->pai = NULL;
        tree = elemAtual->filhoEsq;
      }
      else
      {
        elemAtual->filhoDir->pai = NULL;
        tree = elemAtual->filhoDir;
      }
    }
    free(elemAtual);
  }
  else
  { // tem 2 filhos
    aux = elemAtual->filhoDir;

    while (aux->filhoEsq != NULL)
    {
      aux = aux->filhoEsq;
    }

    herdeiro = aux->dado;
    tree = removeArvore(tree, herdeiro);
    elemAtual->dado = herdeiro;
  }

  return tree;
}

// Objetivo: libera árvore
// Parâmetro: árvor
// Retorno: 0 se for bem sucedido, -1 se ocorrer algum erro
int liberaArvore(arvore *tree)
{
  //Declarações:
  arvore *elemAtual;
  arvore *aux;
  //Instruções:

  if (tree == NULL)
  {
    fprintf(stderr, "\n\nOcorreu um erro ao tentar liberar a árvore...\n\nÁrvore não foi inicializada!");
    return -1;
  }

  elemAtual = tree;
  while (elemAtual != NULL)
  {
    while (elemAtual->filhoEsq != NULL)
    {
      elemAtual = elemAtual->filhoEsq;
    }

    if (FOLHA)
    {
      aux = elemAtual->pai;
      tree = removeArvore(tree, elemAtual->dado);
      elemAtual = aux;
    }
    else if (TEM_FILHO_DIR)
    {
      elemAtual = elemAtual->filhoDir;
    }
  }

  return 0;
}

// Objetivo: Calcular o nível do no
// Parâmetro: nó da árvore
// Retorno: retorna o nível do nó
int nivelNo(arvore *tree)
{
  //Declarações:
  int nivel = 0;
  //Instruções:
  while (tree != NULL)
  {
    tree = tree->pai;
    nivel++;
  }

  return nivel;
}

// Objetivo: procurar um valor na árvore
// Parâmetro: raiz da árvore, e número a ser buscado
// Retorno: Imprime na tela o que achou
void searchValue(arvore *tree)
{
  //Declarações:
  int busca;
  arvore *noArvore;
  arvore *irmao;
  //Instruções:
  system("clear");

  if (tree == NULL)
  {
    puts("A lista não foi inicializada, portanto não há valores a serem buscados...");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return;
  }

  puts("Digite o valor a ser procurado:");
  scanf("%d", &busca);
  limpabuffer();
  noArvore = buscaArvore(tree, busca);
  if (noArvore == NULL)
  {
    puts("\n\nO valor solicitado não foi encontrado.");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return;
  }
  printf("\n\nNível do nó: %d\n", nivelNo(noArvore));
  if (noArvore->pai != NULL)
    printf("Valor do Pai: %d\n", noArvore->pai->dado);
  else
    printf("Valor do Pai: Nó não tem pai...\n");

  if (noArvore->pai != NULL)
  {
    if (noArvore->pai->filhoEsq == noArvore)
    {
      irmao = noArvore->pai->filhoDir;
    }
    else
    {
      irmao = noArvore->pai->filhoEsq;
    }

    if (irmao == NULL)
      printf("Valor do Irmão: Não tem irmão\n");
    else
      printf("Valor do Irmão: %d\n", irmao->dado);
  }
  else
  {
    printf("Valor do Irmão: Não tem irmão...\n");
  }

  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return;
}
// Objetivo: Remover um valor da árvore
// Parâmetro: raiz da árvore
// Retorno: ponteiro para árvore com valor removido
arvore *removeValue(arvore *tree)
{
  //Declarações:
  int busca;
  arvore *noArvore;
  //Instruções:
  system("clear");

  if (tree == NULL)
  {
    puts("A lista não foi inicializada, portanto não há valores a serem removidos...");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return tree;
  }

  puts("Digite o valor a ser excluído:");
  scanf("%d", &busca);
  limpabuffer();
  noArvore = buscaArvore(tree, busca);
  if (noArvore == NULL)
  {
    puts("\n\nO valor solicitado não foi encontrado.");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return tree;
  }

  tree = removeArvore(tree, busca);
  puts("\n\nElemento removido com sucesso");
  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return tree;
}

// Objetivo: Calcular a altura da árvore
// Parâmetro: árvore
// Retorno: Imprime na tela a altura da árvore
void getHeight(arvore *tree)
{
  //Instruções:
  system("clear");
  printf("A altura da árvore é: %d\n", alturaArvore(tree));
  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return;
}

// Objetivo: Mostra se a arvore é cheia ou não
// Parâmetro: árvore
// Retorno: Imprime se é cheia ou não
void isFull(arvore *tree)
{
  //Declarações:

  //Instruções:
  system("clear");
  if (arvoreCheia(tree) == 1)
    puts("A árvore é cheia");
  else if (arvoreCheia(tree) == 0)
    puts("A árvore não é cheia");
  else
    puts("A árvore não foi inicializada!");
  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return;
}

// Objetivo: Limpar buffer do teclado
// Parâmetro:
// Retorno:
void limpabuffer(void)
{
  //Declarações:
  char c;
  //Instruções:
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Objetivo: calcula altura da arvore
// Parâmetro: árvore
// Retorno: altura da árvore
int alturaArvore(arvore *tree)
{
  //Declarações:
  arvore *elemAtual;
  int altura = 0;
  int cont = 0;
  int voltaEsqDir = 0; // Lado de volta, 1= esquerda ou 0= direita
  int volta = 0;
  //Instruções:
  if (tree != NULL)
  {
    cont++;
    altura++;
    elemAtual = tree;
    while (elemAtual != NULL)
    {
      if (!volta)
      {
        while (elemAtual->filhoEsq != NULL)
        {
          elemAtual = elemAtual->filhoEsq;
          volta = 0;
          cont++;
          voltaEsqDir = 0;
          if (cont > altura)
          {
            altura = cont;
          }
        }
      }

      if ((volta && !voltaEsqDir && elemAtual->filhoDir != NULL) || (TEM_FILHO_DIR && elemAtual->filhoEsq == NULL && !volta))
      {
        elemAtual = elemAtual->filhoDir;
        volta = 0;
        cont++;
        voltaEsqDir = 1;
        if (cont > altura)
        {
          altura = cont;
        }
      }
      else if (FOLHA || (volta && voltaEsqDir) || (volta && elemAtual->filhoDir == NULL))
      {
        if (elemAtual->pai != NULL)
        {
          if (elemAtual->pai->filhoEsq == elemAtual)
            voltaEsqDir = 0;
          else
            voltaEsqDir = 1;
        }

        elemAtual = elemAtual->pai;
        cont--;
        volta = 1;
      }
    }
  }

  return altura;
}

// Objetivo: Testa se a árvore é cheia ou não
// Parâmetro: árvore
// Retorno: 1=árvore cheia, 0= árvore não é cheia, -1=árvore não inicializada
int arvoreCheia(arvore *tree)
{
  //Declarações:
  arvore *elemAtual;
  int voltaEsqDir = 0; // Lado de volta, 1= esquerda ou 0= direita
  int volta = 0;
  int cheia = 1;
  //Instruções:
  if (tree != NULL)
  {
    elemAtual = tree;
    while (elemAtual != NULL)
    {
      if (TEM_1_FILHO)
        cheia = 0;

      if (!volta)
      {
        while (elemAtual->filhoEsq != NULL)
        {
          elemAtual = elemAtual->filhoEsq;
          volta = 0;
          voltaEsqDir = 0;
          if (TEM_1_FILHO)
            cheia = 0;
        }
      }

      if ((volta && !voltaEsqDir && elemAtual->filhoDir != NULL) || (TEM_FILHO_DIR && elemAtual->filhoEsq == NULL && !volta))
      {
        elemAtual = elemAtual->filhoDir;
        volta = 0;
        voltaEsqDir = 1;
      }
      else if (FOLHA || (volta && voltaEsqDir) || (volta && elemAtual->filhoDir == NULL))
      {
        if (elemAtual->pai != NULL)
        {
          if (elemAtual->pai->filhoEsq == elemAtual)
            voltaEsqDir = 0;
          else
            voltaEsqDir = 1;
        }

        elemAtual = elemAtual->pai;
        volta = 1;
      }
    }
  }
  else
  {
    return -1;
  }

  return cheia;
}

// Objetivo: Função para sair do programa
// Parâmetro: árvore
// Retorno:
void sair(arvore *tree)
{
  //Declarações:
  char opcao;
  //Instruções:
  system("clear");
  puts("Tem certeza que deseja sair?(S/N)");
  opcao = validaSN(opcao);

  if (opcao == 'S' || opcao == 's')
  {
    if(tree!=NULL)
      liberaArvore(tree);
    exit(0);
  }

  return;
}

// Objetivo: Verificar se a opção escolhida é válida
// Parâmetro: opção
// Retorno: opção válida
char validaSN(char opcao)
{
  //Declarações:

  //Instruções:
  opcao = getchar();
  limpabuffer();
  while (opcao != 'S' && opcao != 's' && opcao != 'N' && opcao != 'n')
  {
    puts("\n\n\n\nOpção inválida!(digite s para sim, ou n para não)");
    opcao = getchar();
    limpabuffer();
  }
  return opcao;
}
//Pos-Order
int printPostOrder(arvore *tree){
  if (tree == NULL){
    return -1;
  }
  printPostOrder(tree->filhoEsq);
  printPostOrder(tree->filhoDir);
  printf("%d, ", tree->dado);

  return 0;
}
//Pre-Order
int printPreOrder(arvore *tree)
{
  if (tree == NULL)
  {
    return -1;
  }
  printf("%d, ", tree->dado);
  printPreOrder(tree->filhoEsq);
  printPreOrder(tree->filhoDir);

  return 0;
}


int inOrder(arvore *tree){
  system("clear");
  if(tree!=NULL)
    printInOrder(tree);
  else
    puts("A árvore não foi inicializada!");

  puts("\n\nAperte qualquer coisa para continuar...");
  limpabuffer();
  return 0;
}

int preOrder(arvore *tree){
  system("clear");
  if(tree!=NULL)
    printPreOrder(tree);
  else
    puts("A árvore não foi inicializada!");

  puts("\n\nAperte qualquer coisa para continuar...");
  limpabuffer();
  return 0;
}

int postOrder(arvore *tree){
  system("clear");
  if(tree!=NULL)
    printPostOrder(tree);
  else
    puts("A árvore não foi inicializada!");

  puts("\n\nAperte qualquer coisa para continuar...");
  limpabuffer();
  return 0;
}

//In-Order
int printInOrder(arvore *tree){
  if (tree == NULL)
  {
    return -1;
  }
  printInOrder(tree->filhoEsq);
  printf("%d, ", tree->dado);
  printInOrder(tree->filhoDir);

  return 0;
}
// faz uma rotaçao para direita
void r_direita(arvore *avo, arvore *pai, arvore *filho)
{
  if (avo != NULL)
  {
    if (avo->filhoEsq == pai)
    {
      avo->filhoEsq = filho;
    }
    else
    {
      avo->filhoDir = filho;
    }
  }
  pai->filhoEsq = filho->filhoDir;
  filho->filhoDir = pai;
}
// faz uma rotaçao para esquerda
arvore* r_esquerda(arvore *avo, arvore *pai, arvore *filho)
{
  if (avo != NULL)
  {
    if (avo->filhoEsq == pai)
    {
      avo->filhoEsq = filho;
    }
    else
    {
      avo->filhoDir = filho;
    }
  }
  pai->filhoDir = filho->filhoEsq;
  filho->filhoEsq = pai;
  return filho;
}

// verifica balenceamento da arvore (1> ret, esta  balanceado)
int is_balance(arvore *tree)
{
  int alt_dir;
  int alt_esq;
  if (tree == NULL)
  {
    return 1;
  }
  alt_dir = alturaArvore(tree->filhoDir);
  alt_esq = alturaArvore(tree->filhoEsq);
  if (abs(alt_dir - alt_esq) >= 1)
  {
    return 0;
  }
  return is_balance(tree->filhoEsq) * is_balance(tree->filhoDir);
}

arvore* backbone(arvore *root)
{
  arvore *filho = root;
  arvore *pai = NULL;
  arvore *avo = NULL;

  while (filho != NULL)
  {
    if (filho->filhoEsq != NULL)
    {
      if (filho == root)
      {
        root = filho->filhoEsq;
      }
      pai = filho;
      filho = filho->filhoEsq;
      r_direita(avo, pai, filho);
    }
    else
    {
      avo = filho;
      filho = filho->filhoDir;
    }
  }
  return root;
}
arvore* DSW(arvore *tree)
{
  if (is_balance(tree) >= 1)
  {
    return tree;
  }
  int qtd, m, n;
 tree = backbone(tree);

  qtd = alturaArvore(tree);
  m = (1 << (int)floor(log(qtd + 1) / log(2))) - 1;
  n = qtd - m;
 tree= rotaciona(tree, n);
  while (m > 1)
  {
  }
  {
    m = m / 2;
   tree= rotaciona(tree,m);
  }
  return tree;
}
arvore* rotaciona(arvore *tree, int num)
{
  arvore *avo = NULL, *pai = NULL, *filho = NULL;
  while (num--)
  {
    for (int i = 0; i <= 1; i++)
    {
      avo = pai;
      pai = filho;
      if (filho != NULL)
      {
        filho = filho->filhoDir;
      }
      else if (pai == NULL)
      {
        filho = tree;
      }
    }
    if (pai == tree)
    {
      tree = filho;
      tree =r_esquerda(avo, pai, filho);
    }
  }
  return tree;
}
