// Síntese
// Objetivo: Identificar solo para drone pousar através de imagens
// Entrada: imagens de grama ou asfalto
// Saída: porcentagens de acertos e erros em identificar as imagens

#include <stdio.h>
#include <math.h>

int* ilbd(int *imagem);
int calcula_media_viz(int *posicao);
int *cria_matriz_bin(int posicao_imagem, int media);
int desloca_bin(int binario);
int min_bin(int binario);
void inc_vetor(int *vetor_freq, int min_bin);
int *glcm(int *imagem);
void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm);
int contraste(int *m_glcm);
int energia(int *m_glcm);
int homogeneidade(int *m_glcm);
void normaliza_vet(float *vetor, int tam);
double calcula_dist_eucl(int *vetor1, int *vetor2, int tam);
int *media_vet_feat();
void lista_resultado(int acertos, int falsa_rej, int falsa_ace);
int *le_imagem();

int main(){
    // Declarações:
    
    // Instruções:



    return 0;
}

/////////////////////////////////CÓDIGO ILBD/////////////////////////////

// Objetivo: Função principal para calcular o vetor de frequências do ILBP
// Parâmetro: matriz em tons de cinza de uma imagems
// Retorno: vetor de frequências

int* ilbd(int *imagem){
    // Declarações:
    int *vetor_frequencias;
    // Instruções:

    return vetor_frequencias; // vetor de 512 posições com as frequências
}

// Objetivo: Calcula média da vizinhança
// Parâmetro: ponteiro com posição da matriz da imagem
// Retorno: valor da média

int calcula_media_viz(int *posicao){
    // Declarações:
    int media;
    // Instruções:

    //obs: aqui tu pega uma posição da imagem, e calcula a média entre
    //     os 8 elementos vizinhos e o próprio elemento que foi recebido

    return media;
}

// Objetivo: Cria matriz binária
// Parâmetro: posição da imagem, média da vizinhança
// Retorno: matriz binária

int *cria_matriz_bin(int posicao_imagem, int media){
    // Declarações:
    int *p_matriz_bin;
    // Instruções:

    //obs.: aqui temos que pegar cada elemento da vizinhança e
    //      comparar com a média, se o resultado for >= media, então
    //      o elemento na nova matriz será 1, e se for menor será 0
    //      ou seja criaremos uma matriz de 9 elementos com 0's e 1's

    return p_matriz_bin;
}

// Objetivo: Transformar matriz em um número binário
// Parâmetro: matriz binária
// Retorno: número binário de 9 bits

int calcula_bin(int *p_matriz_bin){
    // Declarações:
    int binario;
    // Instruções:

    //obs.: deve-se pegar a matriz binária, e formar com os 0's e 1's
    //      um único número binário. A direção que se escolhe para
    //      colocar os bits não importa, contanto que seja mantida.

    return binario;
}

// Objetivo: Desloca número binário
// Parâmetro: número binário
// Retorno: número binário deslocado

int desloca_bin(int binario){
    // Declarações:
    int des_bin;
    // Instruções:

    //obs.: O deslocamento aqui acontece de um lado a outro colocando
    //      o último bit na primeira posição e deslocando os bits
    //      restantes (que dá pra fazer multiplicando por "2")

    return des_bin;
}

// Objetivo: Encontra o arranjo binário com valor mínimo
// Parâmetro: número binário
// Retorno:  valor mínimo

int min_bin(int binario){
    // Declarações:
    int min_binario;
    // Instruções:

    //obs.: aqui deve-se deslocar o número binário até conseguir todos
    //      os deslocamentos possíveis, e retornar o deslocamento com
    //      menor valor.

    return min_binario;
}

// Objetivo: Incrementa o vetor de frequências
// Parâmetro: ponteiro com vetor de frequências, binário mínimo
// Retorno:

void inc_vetor(int *vetor_freq, int min_bin){
    // Declarações:

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

    //obs.1:matriz glcm é 256x256

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

    return;
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

void lista_resultado(int acertos, int falsa_rej, int falsa_ace){
    // Declarações:

    // Instruções:
    return;
}
// Objetivo: Ler txt que contém imagem
// Parâmetro: Nome do arquivo
// Retorno:  matriz em tons de cinza
int *le_imagem(){
    // Declarações:
    int *imagem;
    // Instruções:

    return imagem;
}
