// Síntese
// Objetivo: Manipular lista de contatos
// Entrada: Comandos, e arquivo com lista de contatos
// Saída: lista manipulada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContatos.h"

void limpabuffer(void);
void imprimeMenu();
char validaOpcao(char opcao);
char validaSN(char opcao);
void visualizaTodos(contato *lista);
void visualizaRegistro(contato *lista);
void removeRegistro(contato *lista);
contato *novoRegistro(contato *lista);
void verificaNome(char *);
unsigned int verificaCep(unsigned int);
void verificaTelefone(char *);
void verificaNascimento(char *);
void verificaEndereco(char *);
void sair();

int main(){
  //Declarações:
  int sent =1;
  char opcao;
  contato *lista;
  //Instruções:
  contato *elem;
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

  lista=criaListaVazia();
  lista=appendContato(lista, hugo[0]);
  lista=appendContato(lista, hugo[1]);
  lista=appendContato(lista, hugo[2]);

  salva_arq(lista);

  while(sent){
    imprimeMenu();
    opcao=validaOpcao(opcao);

    switch(opcao){
      case '1':
        novoRegistro(lista);
        break;
      case '2':
        removeRegistro(lista);
        break;
      case '3':
        visualizaRegistro(lista);
        break;
      case '4':
        visualizaTodos(lista);
        break;
      case '5':
        sair();
        break;
      default:
        fprintf(stderr, "Um erro inesperado aconteceu...\n\n\nO programa será desligado\n");
        exit(-1);
    }
  }



  return 0;
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

// Objetivo: Imprimir menu principal
// Parâmetro:
// Retorno:
void imprimeMenu(){
  //Declarações:

  //Instruções:
  system("clear");
  puts("1. Inserir novo registro");
  puts("2. Remover registros que contenham certa string no nome");
  puts("3. Visualizar registros que contenham certa string no nome");
  puts("4. Visualizar todos os registros em ordem alfabética de acordo com o nome");
  puts("5. Sair");
  puts("\n\n\n\nEscolha uma opção para continuar:");

  return;
}

// Objetivo: Verificar se a opção escolhida consta no menu
// Parâmetro: opção
// Retorno: opção válida
char validaOpcao(char opcao){
  //Declarações:

  //Instruções:
  opcao=getchar();
  limpabuffer();
  while(opcao!='1' && opcao!='2' && opcao!='3' && opcao!='4' && opcao!='5'){
    puts("\n\n\n\nOpção inválida!(digite um número entre 1 e 5)");
    opcao=getchar();
    limpabuffer();
  }
  return opcao;
}

// Objetivo: Fechar o programa
// Parâmetro:
// Retorno:
void sair(){
  //Declarações:
  char opcao;
  //Instruções:
  system("clear");
  puts("Tem certeza que deseja sair?(S/N)");
  opcao= validaSN(opcao);

  if(opcao=='S' || opcao=='s'){
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

// Objetivo: Visualizar todos os contatos cadastrados
// Parâmetro: lista
// Retorno:
void visualizaTodos(contato *lista){
  //Declarações:

  //Instruções:
  system("clear");
  printLista(lista);
  puts("\n\n\n\nAperte qualquer coisa para continuar...\n");

  getchar();
  limpabuffer();

  return;
}

// Objetivo: Visualizar todos os contatos com determinada string
// Parâmetro: lista
// Retorno:
void visualizaRegistro(contato *lista){
  //Declarações:
  char palavra[100];
  contato *contatoAtual;
  //Instruções:
  system("clear");

  puts("Digite o nome a ser buscado:");
  fgets(palavra, 100, stdin);
  palavra[strlen(palavra)-1]='\0';

  contatoAtual=lista;
  contatoAtual=procuraElemento(contatoAtual, palavra);
  if(contatoAtual==NULL){
    printf("Não foi encontrado nenhum contato com o nome %s\n", palavra);
    getchar();
    limpabuffer();
    return;
  }
  while(contatoAtual!=NULL){
    printElemento(contatoAtual, 0);
    contatoAtual=procuraElemento(contatoAtual->prox, palavra);
  }

  puts("\n\n\n\nAperte qualquer coisa para continuar...\n");

  getchar();
  limpabuffer();

  return;
}
// Objetivo: Reomove todos os contatos com determinada string
// Parâmetro: lista
// Retorno:
void removeRegistro(contato *lista){
  //Declarações:
  char palavra[100];
  contato *contatoAtual;
  //Instruções:
  system("clear");

  puts("Digite o nome do registro a ser deletado:");
  fgets(palavra, 100, stdin);
  palavra[strlen(palavra)-1]='\0';

  contatoAtual=procuraElemento(lista, palavra);
  if(contatoAtual==NULL){
    printf("Não foi encontrado nenhum contato com o nome %s\n", palavra);
    getchar();
    limpabuffer();
    return;
  }
  while(contatoAtual!=NULL){
    contatoAtual=deletaElemento(contatoAtual, 0);
    contatoAtual=procuraElemento(contatoAtual, palavra);
  }

  puts("\n\n\n\nRegistros excluídos com sucesso!!!\nAperte qualquer coisa para continuar...\n");

  getchar();
  limpabuffer();

  return;
}

//objetivo: adicionar um novo registro de contato
contato *novoRegistro(contato *lista){
  elemento dado;

  
  puts("Digite o nome: ");
  fgets(dado.nome, 100, stdin);
  verificaNome(dado.nome);
  limpabuffer();
  
  puts("Digite o telefone celular no formato (xxxxx-xxxx): ");
  fgets(dado.telefone, 11, stdin);
  verificaTelefone(dado.telefone);
  limpabuffer();
  
  puts("Digite o endereco: ");
  fgets(dado.endereco, 100, stdin);
  verificaEndereco(dado.endereco);
  limpabuffer();
  
  puts("Digite os 8 digitos do CEP: ");
  scanf("%u", &dado.cep);
  verificaCep(dado.cep);
  limpabuffer();
  
  
  puts("Digite a data de nascimento: ");
  fgets(dado.nascimento, 11, stdin);
  verificaNascimento(dado.nascimento);
  limpabuffer();

  getchar();
  limpabuffer();

  return lista;
}

//objetivo: verificar se o nome eh valido
void verificaNome(char *nome){
  int sentinela;

  while(sentinela){
    sentinela = 0;

    for(int i = 0; nome[i] != '\0'; i++){
      if(nome[i] >= '0' && nome[i] <= '9'){
        puts("Nome invalido!");
        sentinela = 1;
        break;
      }
    }
    if(sentinela == 1){
      puts("Tente novamente, use apenas letras...");
      fgets(nome, 101, stdin);
    }      
  }
  

}

// objetivo: verificar se o telefone eh valido
void verificaTelefone(char *telefone){
  int tamanho, sentinela = 1;
  tamanho = strlen(telefone);
  telefone[strlen(telefone)-1]='\0';

  while(sentinela){
    sentinela = 0;
    if(tamanho < 10 || tamanho > 10){
      puts("Numero do telefone invalido!");
      sentinela = 1;
    }
    for(int i = 0; telefone[i] != '\0'; i++){
      if(!(telefone[i] >= '0' || telefone[i] <= '9' || telefone[i] != '-')){
        puts("O telefone nao pode conter letras ou caracteres especiais!");
        sentinela = 1;
        break;
      }
    }
    if(sentinela == 1){
      puts("Tente novamente, evite letras e use o formato (XXXXX-XXXX)!");
      fgets(telefone, 11, stdin);
      limpabuffer();
      telefone[strlen(telefone)-1] = '\0';
    }
  }

}

//objetivo: verificar se o cep eh valido
unsigned int verificaCep(unsigned int cep){
  int totalDigitos = 0, sentinela;

  while(sentinela){
    sentinela=0;
    totalDigitos = 0;
    while(cep != 0){
      totalDigitos = totalDigitos + 1;
      cep = cep / 10;
    }
    
    if(totalDigitos != 8){
      puts("CEP invalido! Tente novamente!");
      scanf("%u", &cep);
      sentinela=1;
    }
  }
  
  return cep;
}

//objetivo: verificar se a data de nascimento eh valida
void verificaNascimento(char *nascimento){
  int tamanho = strlen(nascimento), sentinela = 1;
  if(nascimento[strlen(nascimento)-1]=='\n')
    nascimento[strlen(nascimento)-1]='\0';

  while(sentinela){
    sentinela = 0;

      if(nascimento[2] != '/' || nascimento[5] != '/'){
        puts("Data invalida, o formato deve ser (dd/mm/aaaa) contendo o caractere '/' !");
        fgets(nascimento, 11, stdin);
        if(nascimento[strlen(nascimento)-1]=='\n')
          nascimento[strlen(nascimento)-1]='\0';
        sentinela = 1;
      }
    
    for(int i = 0; nascimento[i] != '\0'; i++){
      if(nascimento[i] >= 'a' && nascimento[i] <='z'){
        puts("A data de nascimento nao pode conter letras!");
        fgets(nascimento, 11, stdin);
        if(nascimento[strlen(nascimento)-1]=='\n')
          nascimento[strlen(nascimento)-1]='\0'; 
        sentinela = 1;
        break;
      }
    }
  } 

}

void verificaEndereco(char *endereco){
  int tamanho, sentinela = 1;
  endereco[strlen(endereco)-1]='\0';

  while(sentinela){
    tamanho = strlen(endereco);
    sentinela = 0;
    if(tamanho == 0){
      puts("Digite um endereco!");
      sentinela = 1;
      fgets(endereco, 101, stdin);
    }
  }  
}
