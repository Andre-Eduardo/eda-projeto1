// Síntese
// Objetivo: Biblioteca com funções para o uso de uma lista de contatos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContatos.h"

void limpabuffer(void);
void imprimeMenu();
char validaOpcao(char opcao);
char validaSN(char opcao);
void sair();

int main(){
  int sent =1;
  char opcao;

    while(sent){
      imprimeMenu();
      opcao=validaOpcao(opcao);

      switch(opcao){
        case '1':
          // novoRegistro();
          break;
        case '2':
          //removeRegistro();
          break;
        case '3':
          //visualizaRegistro();
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

void limpabuffer(void) // Funçao utilitária para limpar o buffer do teclado
{
char c;
while ((c = getchar()) != '\n' && c != EOF);
}

void imprimeMenu(){
  system("clear");
  puts("1. Inserir novo registro");
  puts("2. Remover registros que contenham certa string no nome");
  puts("3. Visualizar registros que contenham certa string no nome");
  puts("4. Visualizar todos os registros em ordem alfabética de acordo com o nome");
  puts("5. Sair");
  puts("\n\n\n\nEscolha uma opção para continuar:");

  return;
}

char validaOpcao(char opcao){
  opcao=getchar();
  limpabuffer();
  while(opcao!='1' && opcao!='2' && opcao!='3' && opcao!='4' && opcao!='5'){
    puts("\n\n\n\nOpção inválida!(digite um número entre 1 e 5)");
    opcao=getchar();
    limpabuffer();
  }
  return opcao;
}

void sair(){
  char opcao;
  system("clear");
  puts("Tem certeza que deseja sair?(S/N)");
  opcao= validaSN(opcao);

  if(opcao=='S' || opcao=='s'){
    exit(0);
  }

  return;
}

char validaSN(char opcao){
  opcao=getchar();
  limpabuffer();
  while(opcao!='S' && opcao!='s' && opcao!='N' && opcao!='n'){
    puts("\n\n\n\nOpção inválida!(digite s para sim, ou n para não)");
    opcao=getchar();
    limpabuffer();
  }
  return opcao;
}
