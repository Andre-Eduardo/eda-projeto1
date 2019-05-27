/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Manipular lista de contatos
// Entrada: Comandos, e arquivo com lista de contatos
// Saída: lista manipulada

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaContatos.h"

void imprimeMenu();
char validaOpcao(char opcao);
char validaSN(char opcao);
void visualizaTodos(contato *lista);
void visualizaRegistro(contato *lista);
contato *removeRegistro(contato *lista);
contato *novoRegistro(contato *lista);
void verificaNome(char *);
unsigned int verificaCep(unsigned int);
void verificaTelefone(char *);
void verificaNascimento(char *);
void verificaEndereco(char *);
void sair(contato *lista);

int main(){
  //Declarações:
  int sent =1;
  char opcao;
  contato *lista;
  //Instruções:
  lista=ler_arq(lista);


  while(sent){
    imprimeMenu();
    opcao=validaOpcao(opcao);

    switch(opcao){
      case '1':
        lista=novoRegistro(lista);
        break;
      case '2':
        lista=removeRegistro(lista);
        break;
      case '3':
        visualizaRegistro(lista);
        break;
      case '4':
        visualizaTodos(lista);
        break;
      case '5':
        sair(lista);
        break;
      default:
        fprintf(stderr, "Um erro inesperado aconteceu...\n\n\nO programa será desligado\n");
        exit(-1);
    }
  }



  return 0;
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
void sair(contato *lista){
  //Declarações:
  char opcao;
  //Instruções:
  system("clear");
  puts("Tem certeza que deseja sair?(S/N)");
  opcao= validaSN(opcao);

  if(opcao=='S' || opcao=='s'){
    salva_arq(lista);
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
  tiraBarraN(palavra);

  contatoAtual=lista;
  contatoAtual=procuraElemento(contatoAtual, palavra);
  if(contatoAtual==NULL){
    printf("Não foi encontrado nenhum contato com o nome %s\n", palavra);
    limpabuffer();
    return;
  }
  system("clear");
  printf("Resultado da pesquisa:\t'%s'\n\n", palavra);
  while(contatoAtual!=NULL){
    printElemento(contatoAtual, 0);
    contatoAtual=procuraElemento(contatoAtual->prox, palavra);
  }

  puts("\n\n\n\nAperte qualquer coisa para continuar...\n");

  limpabuffer();

  return;
}
// Objetivo: Reomove todos os contatos com determinada string
// Parâmetro: lista
// Retorno:
contato *removeRegistro(contato *lista){
  //Declarações:
  char palavra[100];
  contato *contatoAtual;
  //Instruções:
  system("clear");

  puts("Digite o nome do registro a ser deletado:");
  fgets(palavra, 100, stdin);
  tiraBarraN(palavra);

  contatoAtual=procuraElemento(lista, palavra);
  if(contatoAtual==NULL){
    printf("\n\n\n\nNão foi encontrado nenhum contato com o nome %s\n", palavra);
    limpabuffer();
    return lista;
  }

  while(contatoAtual!=NULL){
    contatoAtual=deletaElemento(contatoAtual, 0);
    lista=contatoAtual;
    contatoAtual=procuraElemento(contatoAtual, palavra);
  }

  puts("\n\n\n\nRegistros excluídos com sucesso!!!\nAperte qualquer coisa para continuar...\n");

  limpabuffer();

  return lista;
}

// Objetivo: adicionar um novo registro de contato
// Parâmetro: lista
// Retorno: lista
contato *novoRegistro(contato *lista){
  //Declarações:
  elemento dado;
  //Instruções:

  system("clear");
  puts("Digite o nome: ");
  fgets(dado.nome, 100, stdin);
  verificaNome(dado.nome);

  system("clear");
  puts("Digite o telefone celular no formato (xxxxx-xxxx): ");
  fgets(dado.telefone, 11, stdin);
  verificaTelefone(dado.telefone);

  system("clear");
  puts("Digite o endereco: ");
  fgets(dado.endereco, 100, stdin);
  verificaEndereco(dado.endereco);

  system("clear");
  puts("Digite os 8 digitos do CEP: ");
  scanf("%u", &dado.cep);
  verificaCep(dado.cep);

  system("clear");
  puts("Digite a data de nascimento: ");
  fgets(dado.nascimento, 11, stdin);
  verificaNascimento(dado.nascimento);

  lista=insereOrdenado(lista, dado);

  system("clear");
  puts("Aperte qualquer coisa para continuar...");
  limpabuffer();

  return lista;
}

// Objetivo: verificar se o nome eh valido
// Parâmetro: string do nome
// Retorno:
void verificaNome(char *nome){
  //Declarações:
  int sentinela;
  //Instruções:

  tiraBarraN(nome);

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
      tiraBarraN(nome);
    }
  }
}

// Objetivo: verificar se o telefone eh valido
// Parâmetro: string do telefone
// Retorno:
void verificaTelefone(char *telefone){
  //Declarações:
  int tamanho, sentinela = 1;
  //Instruções:

  tamanho = strlen(telefone);
  tiraBarraN(telefone);

  while(sentinela){
    sentinela = 0;
    if(tamanho < 10){
      puts("Numero do telefone invalido!");
      sentinela = 1;
    }


    for(int i = 0; telefone[i] != '\0'; i++){
      if(i==5){
        if(telefone[i]!='-'){
          puts("O telefone deve conter o travessão '-' entre os números!");
          sentinela = 1;
          break;
        }
      }else if(!(telefone[i] >= '0' && telefone[i] <= '9')){
        puts("O telefone nao pode conter letras ou caracteres especiais!");
        sentinela = 1;
        break;
      }
    }
    if(sentinela == 1){
      puts("Tente novamente, evite letras e use o formato (XXXXX-XXXX)!");
      fgets(telefone, 11, stdin);
      tiraBarraN(telefone);
    }
  }

}

// Objetivo: verificar se o cep eh valido
// Parâmetro: número do cep
// Retorno: número verificado de cep
unsigned int verificaCep(unsigned int cep){
  //Declarações:
  int totalDigitos = 0, sentinela;
  //Instruções:

  limpabuffer();
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
      limpabuffer();
      sentinela=1;
    }
  }

  return cep;
}

// Objetivo: verificar se a data de nascimento eh valida
// Parâmetro: string da data de nascimento
// Retorno:
void verificaNascimento(char *nascimento){
  //Declarações:
  int tamanho = strlen(nascimento), sentinela = 1;
  //Instruções:
  tiraBarraN(nascimento);

  while(sentinela){
    sentinela = 0;

      if(nascimento[2] != '/' || nascimento[5] != '/'){
        puts("Data invalida, o formato deve ser (dd/mm/aaaa) contendo o caractere '/' !");
        fgets(nascimento, 11, stdin);
        tiraBarraN(nascimento);
        sentinela = 1;
      }

    for(int i = 0; nascimento[i] != '\0'; i++){
      if(nascimento[i] >= 'a' && nascimento[i] <='z'){
        puts("A data de nascimento nao pode conter letras!");
        fgets(nascimento, 11, stdin);
        tiraBarraN(nascimento);
        sentinela = 1;
        break;
      }
    }
  }

}

// Objetivo: verificar se o endereço eh valido
// Parâmetro: string do endereço
// Retorno:
void verificaEndereco(char *endereco){
  //Declarações:
  int tamanho, sentinela = 1;
  //Instruções:

  tiraBarraN(endereco);

  while(sentinela){
    tamanho = strlen(endereco);
    sentinela = 0;
    if(tamanho == 0){
      puts("Digite um endereco!");
      sentinela = 1;
      fgets(endereco, 101, stdin);
      tiraBarraN(endereco);
    }
  }
}
