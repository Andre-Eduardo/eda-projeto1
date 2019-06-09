/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

#include "arvore.h"

//Objetivo: mostrar menu na tela
void imprimeMenu(){
  system("clear");
  puts("Selecione a ferramenta desejada digitando o No correpondente...");
  puts("1. Load Tree From File");   //Hugo
  puts("2. Show Tree");             //Hugo
  puts("3. Is Full");
  puts("4. Search Value");
  puts("5. Get Height");
  puts("6. Remove Value");          //Hércules
  puts("7. Print In Order");        //Hugo
  puts("8. Print Pre-Order");
  puts("9. Print Post-Order");
  puts("10. Balance Tree");
  puts("11. Sair");                 //Hercules

  return;
}

// //Objetivo: receber a opcao do menu digitada pelo usuario
void opcaoMenu(){
    int sent = 1;
    char opcao;

            while(sent){
            imprimeMenu();
            opcao = validaOpcao(opcao);

            switch(opcao){
            case '1':
                //loadTreeFromFile();
                break;
            case '2':
                //showTree();
                break;
            case '3':
                isFull(tree);
                break;
            case '4':
                searchValue(tree);
                break;
            case '5':
                getHeight(tree);
                break;
            case '6':
                tree=removeValue(tree);
                break;
            case '7':
                //printInOrder();
                break;
            case '8':
                //printPreOrder();
                break;
            case '9':
                //printPostOrder();
                break;
            case '10':
                //balanceTree();
                break;
            case '11':
                sair();
                break;
            default:        //WARNING => 'stderr' deve ser declarado
                fprintf(stderr, "Um erro inesperado aconteceu...\n\n\nO programa será desligado\n");
                exit(-1);
            }
        }


  }
//
// //Objetivo: validar opcao do menu
char validaOpcao(char opcao){
        opcao = getchar();

        limpabuffer();
        //WARNING => esse While deve ser atualizado (opcao != '1' a '11')
        while(opcao!='1' && opcao!='2' && opcao!='3' && opcao!='4' && opcao!='5'){
                puts("\n\n\n\nOpção inválida!(digite um número entre 1 e 11)");
                opcao = sgetchar();
                limpabuffer();
        }
        return opcao;
}

// Objetivo: Cria árvore vazia
// Parâmetro:
// Retorno: ponteiro nulo
arvore *criaArvoreVazia(){
  //Declarações:

  //Instruções:

  return NULL;
}

// Objetivo: Inserir um elemento na árvore
// Parâmetro: árvore, dado ser adicionado
// Retorno: árvore
arvore *insereArvore(arvore *tree, int dado){
  //Declarações:
  arvore *novoElem;
  arvore *elemAtual;
  arvore *prox;
  int sent=1, esqDir;
  //Instruções:

  novoElem = (arvore *)malloc(sizeof(arvore));
  if(novoElem==NULL){
    fprintf(stderr,"Erro ao alocar novo elemento na árvore\n");
    return NULL;
  }

  novoElem->dado=dado;
  novoElem->filhoEsq=NULL;
  novoElem->filhoDir=NULL;

  if(tree==NULL){
    novoElem->pai=NULL;
    return novoElem;
  }else{
    elemAtual=tree;
    while(sent){
      if(novoElem->dado>elemAtual->dado){
        esqDir=1;
        prox=elemAtual->filhoDir;
      }else{
        esqDir=0;
        prox=elemAtual->filhoEsq;
      }

      if(prox==NULL){
        if(esqDir){
          elemAtual->filhoDir=novoElem;
          novoElem->pai=elemAtual;
        }else{
          elemAtual->filhoEsq=novoElem;
          novoElem->pai=elemAtual;
        }

        sent=0;
      }else{
        elemAtual=prox;
      }
    }
  }

  return tree;
}


// Objetivo: Busca elemento na árvore
// Parâmetro: árvore, e elemento a ser buscado
// Retorno: ponteiro para o elemento da árvore com o valor buscado(se não achar retorna NULL)
arvore *buscaArvore(arvore *tree, int busca){
  //Declarações:
  arvore *elemAtual;
  int sent=1;
  //Instruções:
  if(tree==NULL){
    return NULL;
  }

  elemAtual=tree;

  while(elemAtual!=NULL){
    if(busca<elemAtual->dado){
      elemAtual=elemAtual->filhoEsq;
    }else if(busca> elemAtual->dado){
      elemAtual=elemAtual->filhoDir;
    }else{
      return elemAtual;
    }
  }


  return NULL;
}


// Objetivo: remove elemento na árvore
// Parâmetro: árvore, e elemento a ser removido
// Retorno: ponteiro para o elemento da árvore com o valor removido
arvore *removeArvore(arvore *tree, int busca){
  //Declarações:
  arvore *elemAtual;
  arvore *aux;
  int herdeiro;
  //Instruções:
  elemAtual=buscaArvore(tree, busca);

  if(FOLHA){
    aux=elemAtual->pai;
    if(aux!=NULL){
      if(aux->filhoDir==elemAtual)
        aux->filhoDir=NULL;
      else
        aux->filhoEsq=NULL;
    }else{
      tree=NULL;
    }
    free(elemAtual);
  }else if(TEM_1_FILHO){
    aux=elemAtual->pai;
    if(aux!=NULL){
      if(aux->filhoDir==elemAtual){
        if(elemAtual->filhoDir==NULL){
          aux->filhoDir=elemAtual->filhoEsq;
          elemAtual->filhoEsq->pai=aux;
        }
        else{
          aux->filhoDir=elemAtual->filhoDir;
          elemAtual->filhoDir->pai=aux;
        }
      }else{
        if(elemAtual->filhoDir==NULL){
          aux->filhoEsq=elemAtual->filhoEsq;
          elemAtual->filhoEsq->pai=aux;
        }
        else{
          aux->filhoEsq=elemAtual->filhoDir;
          elemAtual->filhoDir->pai=aux;
        }
      }
    }else{
      if(elemAtual->filhoDir==NULL){
        elemAtual->filhoEsq->pai=NULL;
        tree=elemAtual->filhoEsq;
      }else{
        elemAtual->filhoDir->pai=NULL;
        tree=elemAtual->filhoDir;
      }
    }
    free(elemAtual);
  }else{ // tem 2 filhos
    aux=elemAtual->filhoDir;

    while(aux->filhoEsq!=NULL){
      aux=aux->filhoEsq;
    }

    herdeiro=aux->dado;
    tree=removeArvore(tree, herdeiro);
    elemAtual->dado=herdeiro;
  }

  return tree;
}

// Objetivo: libera árvore
// Parâmetro: árvor
// Retorno: 0 se for bem sucedido, -1 se ocorrer algum erro
int liberaArvore(arvore *tree){
  //Declarações:
  arvore *elemAtual;
  arvore *aux;
  //Instruções:

  if(tree==NULL){
    fprintf(stderr, "\n\nOcorreu um erro ao tentar liberar a árvore...\n\nÁrvore não foi inicializada!");
    return -1;
  }

  elemAtual=tree;
  while(elemAtual!=NULL){
    while(elemAtual->filhoEsq!=NULL){
      elemAtual=elemAtual->filhoEsq;
    }

    if(FOLHA){
      aux=elemAtual->pai;
      tree=removeArvore(tree, elemAtual->dado);
      elemAtual=aux;
    }else if(TEM_FILHO_DIR){
      elemAtual=elemAtual->filhoDir;
    }
  }



  return 0;
}

// Objetivo: Calcular o nível do no
// Parâmetro: nó da árvore
// Retorno: retorna o nível do nó
int nivelNo(arvore *tree){
  //Declarações:
  int nivel=0;
  //Instruções:
  while(tree!=NULL){
    tree=tree->pai;
    nivel++;
  }

  return nivel;
}

// Objetivo: procurar um valor na árvore
// Parâmetro: raiz da árvore, e número a ser buscado
// Retorno: Imprime na tela o que achou
void searchValue(arvore *tree){
  //Declarações:
  int busca;
  arvore *noArvore;
  arvore *irmao;
  //Instruções:
  system("clear");

  if(tree==NULL){
    puts("A lista não foi inicializada, portanto não há valores a serem buscados...");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return;
  }

  puts("Digite o valor a ser procurado:");
  scanf("%d", &busca);
  limpabuffer();
  noArvore=buscaArvore(tree, busca);
  if(noArvore==NULL){
    puts("\n\nO valor solicitado não foi encontrado.");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return;
  }
  printf("\n\nNível do nó: %d\n", nivelNo(noArvore));
  if(noArvore->pai!=NULL)
    printf("Valor do Pai: %d\n", noArvore->pai->dado);
  else
    printf("Valor do Pai: Nó não tem pai...\n");

  if(noArvore->pai!=NULL){
    if(noArvore->pai->filhoEsq==noArvore){
      irmao=noArvore->pai->filhoDir;
    }else{
      irmao=noArvore->pai->filhoEsq;
    }

    if(irmao==NULL)
      printf("Valor do Irmão: Não tem irmão\n");
    else
      printf("Valor do Irmão: %d\n", irmao->dado);
  }else{
    printf("Valor do Irmão: Não tem irmão...\n");
  }

  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return;
}
// Objetivo: Remover um valor da árvore
// Parâmetro: raiz da árvore
// Retorno: ponteiro para árvore com valor removido
arvore *removeValue(arvore *tree){
  //Declarações:
  int busca;
  arvore *noArvore;
  //Instruções:
  system("clear");

  if(tree==NULL){
    puts("A lista não foi inicializada, portanto não há valores a serem removidos...");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return tree;
  }

  puts("Digite o valor a ser excluído:");
  scanf("%d", &busca);
  limpabuffer();
  noArvore=buscaArvore(tree, busca);
  if(noArvore==NULL){
    puts("\n\nO valor solicitado não foi encontrado.");
    puts("\n\n\nPressione ENTER para continuar...");
    limpabuffer();
    return tree;
  }

  tree= removeArvore(tree, busca);
  puts("\n\nElemento removido com sucesso");
  puts("\n\n\nPressione ENTER para continuar...");
  limpabuffer();

  return tree;
}

// Objetivo: Calcular a altura da árvore
// Parâmetro: árvore
// Retorno: Imprime na tela a altura da árvore
void getHeight(arvore *tree){
  //Declarações:

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
void isFull(arvore *tree){
  //Declarações:

  //Instruções:
  system("clear");
  if(arvoreCheia(tree)==1)
    puts("A árvore é cheia");
  else if(arvoreCheia(tree)==0)
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
void limpabuffer(void){
  //Declarações:
  char c;
  //Instruções:
  while ((c = getchar()) != '\n' && c != EOF);
}

// Objetivo: calcula altura da arvore
// Parâmetro: árvore
// Retorno: altura da árvore
int alturaArvore(arvore *tree){
  //Declarações:
  arvore *elemAtual;
  int altura=0;
  int cont=0;
  int voltaEsqDir=0; // Lado de volta, 1= esquerda ou 0= direita
  int volta=0;
  //Instruções:
  if(tree!=NULL){
    cont++;
    altura++;
    elemAtual=tree;
    while(elemAtual!=NULL){
      if(!volta){
        while(elemAtual->filhoEsq!=NULL){
          elemAtual=elemAtual->filhoEsq;
          volta=0;
          cont++;
          voltaEsqDir=0;
          if(cont>altura){
            altura=cont;
          }
        }
      }

      if((volta && !voltaEsqDir && elemAtual->filhoDir!=NULL) || (TEM_FILHO_DIR && elemAtual->filhoEsq==NULL && !volta)){
        elemAtual=elemAtual->filhoDir;
        volta=0;
        cont++;
        voltaEsqDir=1;
        if(cont>altura){
          altura=cont;
        }
      }else if(FOLHA || (volta && voltaEsqDir) || (volta && elemAtual->filhoDir==NULL)){
        if(elemAtual->pai!=NULL){
          if(elemAtual->pai->filhoEsq==elemAtual)
            voltaEsqDir=0;
          else
            voltaEsqDir=1;
        }

        elemAtual=elemAtual->pai;
        cont--;
        volta=1;
      }
    }
  }

  return altura;
}

// Objetivo: Testa se a árvore é cheia ou não
// Parâmetro: árvore
// Retorno: 1=árvore cheia, 0= árvore não é cheia, -1=árvore não inicializada
int arvoreCheia(arvore* tree){
  //Declarações:
  arvore *elemAtual;
  int voltaEsqDir=0; // Lado de volta, 1= esquerda ou 0= direita
  int volta=0;
  int cheia=1;
  //Instruções:
  if(tree!=NULL){
    elemAtual=tree;
    while(elemAtual!=NULL){
      if(TEM_1_FILHO)
        cheia=0;

      if(!volta){
        while(elemAtual->filhoEsq!=NULL){
          elemAtual=elemAtual->filhoEsq;
          volta=0;
          voltaEsqDir=0;
          if(TEM_1_FILHO)
            cheia=0;
        }
      }

      if((volta && !voltaEsqDir && elemAtual->filhoDir!=NULL) || (TEM_FILHO_DIR && elemAtual->filhoEsq==NULL && !volta)){
        elemAtual=elemAtual->filhoDir;
        volta=0;
        voltaEsqDir=1;
      }else if(FOLHA || (volta && voltaEsqDir) || (volta && elemAtual->filhoDir==NULL)){
        if(elemAtual->pai!=NULL){
          if(elemAtual->pai->filhoEsq==elemAtual)
            voltaEsqDir=0;
          else
            voltaEsqDir=1;
        }

        elemAtual=elemAtual->pai;
        volta=1;
      }
    }
  }else{
    return -1;
  }

  return cheia;
}

// Objetivo: Função para sair do programa
// Parâmetro: árvore
// Retorno:
void sair(arvore *tree){
  //Declarações:
  char opcao;
  //Instruções:
  system("clear");
  puts("Tem certeza que deseja sair?(S/N)");
  opcao= validaSN(opcao);

  if(opcao=='S' || opcao=='s'){
    liberaArvore(tree);
    exit(0);
  }

  return;
}

// Objetivo: Verificar se a opção escolhida é válida
// Parâmetro: opção
// Retorno: opção válida
char validaSN(char opcao){
  //Declarações:

  //Instruções:
  opcao=getchar();
  limpabuffer();
  while(opcao!='S' && opcao!='s' && opcao!='N' && opcao!='n'){
    puts("\n\n\n\nOpção inválida!(digite s para sim, ou n para não)");
    opcao=getchar();
    limpabuffer();
  }
  return opcao;
}
