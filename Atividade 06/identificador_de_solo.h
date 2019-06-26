#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define TAMANHO_IMG 1025 * 1025
#define LADO_IMG 1025
#define NUM_IMG 2
#define TAM_VET_FEAT 516
#define DIM_GLCM 256   // dimensao da matriz  gerada pelo glcmint retira_features(double** vet_feat_grama,double** vet_feat_asfalto, double** vet_feat_grama_teste, double** vet_feat_asfalto_teste)
#define TAM_VT_GLCM 24 // tamanho do vetor de ocorrencia glcmint retira_features(double** vet_feat_grama,double** vet_feat_asfalto, double** vet_feat_grama_teste, double** vet_feat_asfalto_teste);
#define TAM_GLCM 24
#define TAM_ILBD 512

//Principal
int retira_features(double** vet_feat_grama,double** vet_feat_asfalto, double** vet_feat_grama_teste, double** vet_feat_asfalto_teste);
//ILBP
int *ilbp(int *imagem);int retira_features(double** vet_feat_grama,double** vet_feat_asfalto, double** vet_feat_grama_teste, double** vet_feat_asfalto_teste);
int calcula_media_viz(int *posicao);
int *cria_matriz_viz(int *posicao_imagem);
void cria_matriz_bin(int *matrizViz, int media);
void desloca_bin(int *binario);
int min_bin(int *binario);
void incrementa_vetor(int *vetor_freq, int min_bin);
//GLCM
double *glcm(int *imagem);
void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm);
double energia(double **m_glcm);
double contraste(double **m_glcm);
double homogeneidade(double **m_glcm);
//Outras funções
void normaliza_vet(double *vetor, int tam);
double calcula_dist_eucl(double *vetor1, double *vetor2, int tam);
double *media_vet_feat(double *vet_feat, int num_img);
void lista_resultado(int acertos, int falsa_rej, int falsa_acei);
int *le_imagem(char asf_gram, int num_img);
void calcula_vet_feat(char asf_gram, int num_img, double *vet_feat);
int gera_num_alea(char zera);
char grama_ou_asfalto(double *vet_feat_teste, double *feat_grama, double *feat_asfalto);
void verifica_aloc_int(int *aloc);
void verifica_aloc_float(float *aloc);
void verifica_aloc_double(double *aloc);