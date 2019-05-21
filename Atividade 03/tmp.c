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
void visualizaRegistro(contato *lista);
void novoRegistro();
void sair();

int main(){
  //Declarações:
  int sent =1;
  char opcao;
  contato *lista;
  //Instruções:
  while(sent){
    imprimeMenu();
    opcao=validaOpcao(opcao);

    switch(opcao){
      case '1':
        novoRegistro();
        break;
      case '2':
        //removeRegistro();
        break;
      case '3':
        //visualizaRegistro(lista);
        break;
      case '4':
        //visualizaTodos();
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

//void visualizaRegistro(contato *lista){
  //Declarações:

  //Instruções:
//  system("clear");
//  printLista(lista);
//  puts("\n\n\n\nAperte qualquer coisa para continuar...\n");

//  getchar();
//  limpabuffer();
//
//  return;
//}

void novoRegistro(){
  elemento dado;

  puts("Digite o nome: ");
  fgets(dado.nome, 100, stdin);
  
  puts("Digite o telefone: ");
  fgets(dado.telefone, 10, stdin);
  
  puts("Digite o endereco: ");
  fgets(dado.endereco, 100, stdin);
  //puts("Digite o cep: ");
  //scanf("%d", dado.cep);
  puts("Digite a data de nascimento: ");
  fgets(dado.nascimento, 10, stdin);

  printf("Nome:%s\n", dado.nome);
  printf("Telefone:%s\n",dado.telefone);
  printf("Endereço:%s\n",dado.endereco);
  //printf("CEP:%\n",dado.cep);
  printf("Nascimento:%s\n\n",dado.nascimento);

}