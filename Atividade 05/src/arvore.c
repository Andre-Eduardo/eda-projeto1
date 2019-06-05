/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/


//Objetivo: mostrar menu na tela
void imprimeMenu(){
  system("clear");
  puts("Selecione a ferramenta desejada digitando o No correpondente...");
  puts("1. Load Tree From File");   //Hugo
  puts("2. Show Tree");             //Hugo
  puts("3. Is Full");
  puts("4. Search Value");
  puts("5. Get Height");
  puts("6. Remove Value");
  puts("7. Print In Order");        //Hugo
  puts("8. Print Pre-Order");
  puts("9. Print Post-Order");
  puts("10. Balance Tree");
  puts("11. Sair");                 //Hercules

  return;
}

//Objetivo: receber a opcao do menu digitada pelo usuario
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
                //isFull();
                break;
            case '4':
                //searchValue();
                break;
            case '5':
                //getHeight();
                break;
            case '6':
                //removeValue();
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

//Objetivo: validar opcao do menu
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