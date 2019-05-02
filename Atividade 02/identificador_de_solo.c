// Síntese
// Objetivo: Identificar solo para drone pousar através de imagens
// Entrada: imagens de grama ou asfalto
// Saída: porcentagens de acertos e erros em identificar as imagens

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define TAMANHO_IMG 9
#define LADO_IMG 3

int* ilbp(int *imagem);
int calcula_media_viz(int *posicao);
int *cria_matriz_viz(int *posicao_imagem);
void *cria_matriz_bin(int *matrizViz, int media);
void desloca_bin(int *binario);
int min_bin(int *binario);
void incrementa_vetor(int *vetor_freq, int min_bin);
int *glcm(int *imagem);
void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm);
int contraste(int *m_glcm);
int energia(int *m_glcm);
int homogeneidade(int *m_glcm);
void normaliza_vet(float *vetor, int tam);
double calcula_dist_eucl(int *vetor1, int *vetor2, int tam);
int *media_vet_feat();
void lista_resultado(int acertos, int falsa_rej, int falsa_acei);
int *le_imagem();
int calcula_decimal(int *);

///////////////////////////// MAIN ////////////////////////////////////////////////////////////

int main(){
    // Declarações:
    int oi[9]={1, 1, 1, 2, 2, 2, 3, 3, 3};
    int *mat;
    int *vet_freq;
    // Instruções:

    vet_freq=ilbp(oi);
    printf("%d", *(vet_freq+63));
    return 0;
}

/////////////////////////////////CÓDIGO ILBP/////////////////////////////

// Objetivo: Função principal para calcular o vetor de frequências do ILBP
// Parâmetro: matriz em tons de cinza de uma imagems
// Retorno: vetor de frequências
int* ilbp(int *imagem){
    // Declarações:
    int *matrizViz, mediaViz = 0; 
    int minimo;
    int *vetor_frequencias;
    vetor_frequencias = (int *) calloc(512, sizeof(int));
    
    // Instruções:

    for(int i = LADO_IMG + 1; i < TAMANHO_IMG-LADO_IMG-1; i++){
        matrizViz = cria_matriz_viz(imagem + i);
        mediaViz = calcula_media_viz(matrizViz);
        cria_matriz_bin(matrizViz, mediaViz);
        minimo = min_bin(matrizViz);
        incrementa_vetor(vetor_frequencias, minimo);        
    }       
    
    


    return vetor_frequencias; // vetor de 512 posições com as frequências
}

// Objetivo: Calcula média da vizinhança
// Parâmetro: ponteiro com posição da matriz da imagem
// Retorno: valor da média

int calcula_media_viz(int *posicao){
    // Declarações:
    int soma=0;
    int media;
    // Instruções:
    for(int i = 0; i < 9; i++){
        soma += posicao[i];        
    }
    
    media = soma / 9;

    //obs: aqui tu pega uma posição da imagem, e calcula a média entre
    //     os 8 elementos vizinhos e o próprio elemento que foi recebido

    return media;
}

// Objetivo: Cria matriz binária
// Parâmetro: posição da imagem, média da vizinhança
// Retorno: matriz binária

int *cria_matriz_viz(int *posicao_imagem){
    // Declarações:
    int *matriz;
    int i;

    matriz = (int*) malloc(3*3 * sizeof(int));
    
    // Instruções:

    for(i=0;i<3;i++){
        *(matriz+i)=*(posicao_imagem-LADO_IMG+(i-1));
    }

    for(i=0;i<3;i++){
        *(matriz+3+i)=*(posicao_imagem+(i-1));
    }

    for(i=0;i<3;i++){
        *(matriz+6+i)=*(posicao_imagem+LADO_IMG+(i-1));
    }
    
    return matriz;
}

void *cria_matriz_bin(int *matrizViz, int media){
    // Declarações:
    int i;
    
    // Instruções:

    for(i=0; i<9; i++){
       if(*(matrizViz+i)<media){
           *(matrizViz+i)=0;
       }else{
           *(matrizViz+i)=1;
       }
    }
}

// Objetivo: Transformar matriz em um número binário
// Parâmetro: matriz binária
// Retorno: número binário de 9 bits

int calcula_decimal(int *p_matriz_bin){
    // Declarações:   
    int binario, decimal=0;
    
    // Instruções:
    for(int i = 0; i < 9; ++i){
        decimal += pow(2, (8-i))*(*(p_matriz_bin+i));
    }

    //obs.: deve-se pegar a matriz binária, e formar com os 0's e 1's
    //      um único número binário. A direção que se escolhe para
    //      colocar os bits não importa, contanto que seja mantida.

    return decimal;
}

// Objetivo: Desloca número binário
// Parâmetro: número binário
// Retorno: número binário deslocado

void desloca_bin(int *binario){
    // Declarações:
    int aux[3][3];
    // Instruções:

    for(int i = 0; i < 8; i++){
        *(&aux[0][0]+i) = *(binario + (i+1));
    }
    aux[2][2]=*(binario);

    for(int i = 0; i < 9; i++){
        *(binario + i) = *(&aux[0][0]+i) ;
    }
    //obs.: O deslocamento aqui acontece de um lado a outro colocando
    //      o último bit na primeira posição e deslocando os bits
    //      restantes (que dá pra fazer multiplicando por "2")
}

// Objetivo: Encontra o arranjo binário com valor mínimo
// Parâmetro: número binário
// Retorno:  valor mínimo

int min_bin(int *binario){
    // Declarações:
    int minimo = calcula_decimal(binario);
    int aux = 0;

    // Instruções:
    for(int i = 0; i <= 9; i++){
       aux = calcula_decimal(binario);
       
       if(minimo > aux){
           minimo = aux;
       }

       desloca_bin(binario);
    }
    

    //obs.: aqui deve-se deslocar o número binário até conseguir todos
    //      os deslocamentos possíveis, e retornar o deslocamento com
    //      menor valor.

    return minimo;
}

// Objetivo: Incrementa o vetor de frequências
// Parâmetro: ponteiro com vetor de frequências, binário mínimo
// Retorno:

void incrementa_vetor(int *vetor_freq, int min_bin){
    // Instruções:
    (*(vetor_freq+min_bin))++;

    return;
}

///////////////////////////////GLCM//////////////////////////////////

// Objetivo: função principal do GLCM
// Parâmetro: matriz da imagem
// Retorno:  vetor de com 24 posições(8 posições para homogeneidade,
//           8 para contraste, e 8 para energia da matriz GLCM)

int *glcm(int *imagem){
    // Declarações:
    int *vet_glcm;
    // Instruções:

    return vet_glcm;
}

// Objetivo: Incrementa a matriz GLCM
// Parâmetro: posição da imagem, posição vizinha, ponteiro para a GLCM
// Retorno:

void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm){
    // Declarações:

    // Instruções:

    (*(m_glcm+(*posicao_imagem)*256+(*vizinho)))++;

    return;
}

// Objetivo: Calcula contraste
// Parâmetro: ponteiro para matriz glcm
// Retorno: contraste da matriz

int contraste(int *m_glcm){
    // Declarações:
    int n_contraste;
    // Instruções:

    return n_contraste;
}

// Objetivo: Calcula energia
// Parâmetro: ponteiro para matriz glcm
// Retorno: energia da matriz

int energia(int *m_glcm){
    // Declarações:
    int n_energia;
    // Instruções:

    return n_energia;
}
// Objetivo: Calcula homogeneidade
// Parâmetro: ponteiro para matriz glcm
// Retorno: homogeneidade da matriz

int homogeneidade(int *m_glcm){
    // Declarações:
    int n_homogeneidade;
    // Instruções:

    return n_homogeneidade;
}

//////////////////////////////OUTRAS FUNÇÕES//////////////////////////


// Objetivo: Normalizar vetor de features
// Parâmetro: ponteiro para o vetor
// Retorno: vetor normalizado

void normaliza_vet(float *vetor, int tam){
    // Declarações:
	float minimo, maximo;
	int i;
    // Instruções:


	minimo= *vetor;
	maximo= *vetor;

	for(i=0; i<tam; i++){
		if(minimo>*(vetor+i))
			minimo=*(vetor+i);
	}

	for(i=0; i<tam; i++){
    if(maximo<*(vetor+i))
      maximo=*(vetor+i);
  }

	for(i=0; i<tam; i++){
		*(vetor+i)= (*(vetor+i)-minimo)/(maximo-minimo);
	}

}

// Objetivo: Calcular a distância euclidiana entre 2 vetores de features
// Parâmetro: ponteiro para vetor 1, e vetor 2
// Retorno: distância euclidianda

double calcula_dist_eucl(int *vetor1, int *vetor2, int tam){
    // Declarações:
    double dist_eucl=0;
    int i;
    // Instruções:

    for(i=0; i<tam; i++){
      dist_eucl+= (double)((*(vetor1+i)-*(vetor2+i))*(*(vetor1+i)-*(vetor2+i)));
    }

    dist_eucl= sqrt(dist_eucl);

    return dist_eucl;
}

// Objetivo: tirar média dos vetores de features usados no treinamento
// Parâmetro: ponteiro para matriz de features
// Retorno: ponteiro para vetor da média

int *media_vet_feat(){
    // Declarações:
    int *p_media_feat;
    // Instruções:


    return p_media_feat;
}

// Objetivo: Mostrar resultados finais
// Parâmetro: Número de acertos, número de falsas aceitações, número
//            de falsas rejeições
// Retorno:

void lista_resultado(int acertos, int falsa_rej, int falsa_acei){
    // Declarações:
    float taxa_acer;
    float taxa_fals_acei;
    float taxa_fals_rej;
    // Instruções:

    taxa_acer= 100*((float)acertos)/50;
    taxa_fals_rej= 100*((float)falsa_rej)/50;
    taxa_fals_acei= 100*((float)falsa_acei)/50;


    printf("taxa de acerto: %2f\n", taxa_acer);
    printf("taxa de falsa rejeição: %2f\n", taxa_fals_rej);
    printf("taxa de falsa aceitação: %2f\n", taxa_fals_acei);

    return;
}
// Objetivo: Ler txt que contém imagem
// Parâmetro: Nome do arquivo
// Retorno:  matriz em tons de cinza
int *le_imagem(){
    // Declarações:
    int *imagem;
    int i=0, cont_img=0;
    char numero[4];

    imagem = (int*)malloc(TAMANHO_IMG*sizeof(int));

    FILE *arq_imagem;
    // Instruções:
    arq_imagem = fopen("asphalt_01.txt","r");

    while(!feof(arq_imagem)){
      if(!fread(numero+i, sizeof(char), 1, arq_imagem))
        break;
      if(numero[i]==';'||numero[i]=='\n'){
        numero[i]='\0';
        *(imagem+cont_img)=atoi(numero);
        cont_img++;
        i=0;
      }else
        i++;
    }

    fclose(arq_imagem);

    return imagem;
}
