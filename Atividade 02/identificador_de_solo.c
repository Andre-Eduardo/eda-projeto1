// Síntese
// Objetivo: Identificar solo para drone pousar através de imagens
// Entrada: imagens de grama ou asfalto
// Saída: porcentagens de acertos e erros em identificar as imagens

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define TAMANHO_IMG 1025 * 1025
#define LADO_IMG 1025
#define NUM_IMG 50
#define TAM_VET_FEAT 516
<<<<<<< HEAD
#define DIM_GLCM 256   // dimensao da matriz  gerada pelo glcm
#define TAM_VT_GLCM 24 // tamanho do vetor de ocorrencia glcm
=======
#define TAM_GLCM 4
#define TAM_ILBD 512

>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72
//ILBD
int *ilbd(int *imagem);
int calcula_media_viz(int *posicao);
int *cria_matriz_bin(int posicao_im, int media);
int desloca_bin(int binario);
int min_bin(int binario);
void inc_vetor(int *vetor_freq, int min_bin);
//GLCM
int *glcm(int *imagem);
void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm);
int contraste(int *m_glcm);
int energia(int *m_glcm);
int homogeneidade(int *m_glcm);
//Outras funções
void normaliza_vet(float *vetor, int tam);
double calcula_dist_eucl(float *vetor1, float *vetor2, int tam);
float *media_vet_feat(float *vet_feat, int num_img);
void lista_resultado(int acertos, int falsa_rej, int falsa_acei);
int *le_imagem(char asf_gram, int num_img);
void calcula_vet_feat(char asf_gram, int num_img, float *vet_feat);
int gera_num_alea(char zera);
<<<<<<< HEAD
char grama_ou_asfalto(float *vet_feat_teste, float *feat_grama, float *feat_asfalto);
void verifica_aloc_int(int *aloc);
void verifica_aloc_float(float *aloc);
int main()
{
  // Declarações:
  int *imagem;
  int *vet_ilbd;
  int *vet_glcm;
  float *vet_feat_grama;
  float *vet_feat_asfalto;
  float *media_vet_feat_grama;
  float *media_vet_feat_asfalto;
  int i;
  char teste;
  int acertos = 0, falsa_rej = 0, falsa_acei = 0;

  // Instruções:

  vet_feat_grama = (float *)malloc(NUM_IMG * TAM_VET_FEAT * sizeof(float));
  verifica_aloc_float(vet_feat_grama);
  vet_feat_asfalto = (float *)malloc(NUM_IMG * TAM_VET_FEAT * sizeof(float));
  verifica_aloc_float(vet_feat_asfalto);
  vet_feat_grama_teste = (float *)malloc(NUM_IMG * TAM_VET_FEAT * sizeof(float));
  verifica_aloc_float(vet_feat_grama_teste);
  vet_feat_asfalto_teste = (float *)malloc(NUM_IMG * TAM_VET_FEAT * sizeof(float));
  verifica_aloc_float(vet_feat_asfalto_teste);

  for (i = 0; i < NUM_IMG; i++)
  {
    calcula_vet_feat(1, gera_num_alea(0), vet_feat_grama + i * TAM_VET_FEAT);
  }
  for (i = 0; i < NUM_IMG; i++)
  {
    calcula_vet_feat(1, gera_num_alea(0), vet_feat_grama_teste + i * TAM_VET_FEAT);
  }

  gera_num_alea(1);
  for (i = 0; i < NUM_IMG; i++)
  {
    calcula_vet_feat(0, gera_num_alea(0), vet_feat_asfalto + i * TAM_VET_FEAT);
  }
  for (i = 0; i < NUM_IMG; i++)
  {
    calcula_vet_feat(1, gera_num_alea(0), vet_feat_asfalto_teste + i * TAM_VET_FEAT);
  }
  gera_num_alea(1);

  media_vet_feat_grama = media_vet_feat(vet_feat_grama);
  media_vet_feat_asfalto = media_vet_feat(vet_feat_asfalto);
=======
char grama_ou_asfalto(float *vet_feat_teste,float *feat_grama,float *feat_asfalto);

int main(){
    // Declarações:
    int *imagem;
    float *vet_feat_grama;
    float *vet_feat_asfalto;
    float *vet_feat_grama_teste;
    float *vet_feat_asfalto_teste;
    float *media_vet_feat_grama;
    float *media_vet_feat_asfalto;
    int i;
    char teste;
    int acertos=0, falsa_rej=0, falsa_acei=0;


    // Instruções:

    vet_feat_grama=(float*)malloc((NUM_IMG/2)*TAM_VET_FEAT*sizeof(float));
    vet_feat_asfalto=(float*)malloc((NUM_IMG/2)*TAM_VET_FEAT*sizeof(float));
    vet_feat_grama_teste=(float*)malloc((NUM_IMG/2)*TAM_VET_FEAT*sizeof(float));
    vet_feat_asfalto_teste=(float*)malloc((NUM_IMG/2)*TAM_VET_FEAT*sizeof(float));

    for(i=0; i<(NUM_IMG/2); i++){
      calcula_vet_feat(1 , gera_num_alea(0), vet_feat_grama+i*TAM_VET_FEAT);
    }
    for(i=0; i<(NUM_IMG/2); i++){
      calcula_vet_feat(1 , gera_num_alea(0), vet_feat_grama_teste+i*TAM_VET_FEAT);
    }

    gera_num_alea(1);
    for(i=0; i<(NUM_IMG/2); i++){
      calcula_vet_feat(0 , gera_num_alea(0), vet_feat_asfalto+i*TAM_VET_FEAT);
    }
    for(i=0; i<(NUM_IMG/2); i++){
      calcula_vet_feat(0 , gera_num_alea(0), vet_feat_asfalto_teste+i*TAM_VET_FEAT);
    }
    gera_num_alea(1);

    media_vet_feat_grama = media_vet_feat(vet_feat_grama, (NUM_IMG/2));
    media_vet_feat_asfalto = media_vet_feat(vet_feat_asfalto, (NUM_IMG/2));
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72

  free(vet_feat_grama);
  free(vet_feat_asfalto);

<<<<<<< HEAD
  for (i = 0; i < NUM_IMG; i++)
  {
    teste = grama_ou_asfalto(vet_feat_asfalto_teste, media_vet_feat_grama, media_vet_feat_asfalto);
    if (teste)
    {
      acertos++;
=======
    for(i=0; i<(NUM_IMG/2); i++){
      teste=grama_ou_asfalto(vet_feat_asfalto_teste+i*TAM_VET_FEAT, media_vet_feat_grama, media_vet_feat_asfalto);
      if(teste){
        acertos++;
      }else{
        falsa_acei++;
      }
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72
    }
    else
    {
      falsa_acei++;
    }
  }

<<<<<<< HEAD
  for (i = 0; i < NUM_IMG; i++)
  {
    teste = grama_ou_asfalto(vet_feat_asfalto_teste, media_vet_feat_grama, media_vet_feat_asfalto);
    if (!teste)
    {
      acertos++;
=======
    for(i=0; i<(NUM_IMG/2); i++){
      teste=grama_ou_asfalto(vet_feat_grama_teste+i*TAM_VET_FEAT, media_vet_feat_grama, media_vet_feat_asfalto);
      if(!teste){
        acertos++;
      }else{
        falsa_rej++;
      }
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72
    }
    else
    {
      falsa_rej++;
    }
  }

  lista_resultado(acertos, falsa_rej, falsa_acei);

<<<<<<< HEAD
  free(vet_feat_grama_teste);
  free(vet_feat_asfalto_teste);
  free(media_vet_feat_asfalto);
  free(media_feat_asfalto);
=======
    free(vet_feat_grama_teste);
    free(vet_feat_asfalto_teste);
    free(media_vet_feat_asfalto);
    free(media_vet_feat_grama);
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72

  return 0;
}

/////////////////////////////////CÓDIGO ILBD/////////////////////////////

// Objetivo: Função principal para calcular o vetor de frequências do ILBP
// Parâmetro: matriz em tons de cinza de uma imagems
// Retorno: vetor de frequências

int *ilbd(int *imagem)
{
  // Declarações:
  int *vetor_frequencias;
  // Instruções:

  return vetor_frequencias; // vetor de 512 posições com as frequências
}

// Objetivo: Calcula média da vizinhança
// Parâmetro: ponteiro com posição da matriz da imagem
// Retorno: valor da média

int calcula_media_viz(int *posicao)
{
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

int *cria_matriz_bin(int posicao_imagem, int media)
{
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

int calcula_bin(int *p_matriz_bin)
{
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

int desloca_bin(int binario)
{
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

int min_bin(int binario)
{
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

void inc_vetor(int *vetor_freq, int min_bin)
{
  // Declarações:

  // Instruções:

  (*(vetor_freq + min_bin))++;

  return;
}

///////////////////////////////GLCM//////////////////////////////////

// Objetivo: função principal do GLCM
// Parâmetro: matriz da imagem
// Retorno:  vetor de com 24 posições(8 posições para homogeneidade,
//           8 para contraste, e 8 para energia da matriz GLCM)

int *glcm(int *imagem)
{
  // Declarações:
  float vet_glcm[TAM_VT_GLCM];
  int ***mats_glcm
      // Instruções:
      mats_glcm = (int ***)calloc(8 * sizeof(int **));
  verifica_aloc_int(mats_glcm);

  for (int i = 0; i < 8; i++)
  {
    mats_glcm[i] = (int **)calloc(DIM_GLCM * sizeof(int *));
    verifica_aloc_int(mats_glcm[i]);
  }

  for (int j = 0; j < DIM_GLCM; j++)
  {
    mats_glcm[i][j] = (int *)calloc(DIM_GLCM * sizeof(int));
    verifica_aloc_int(mats_glcm[i][j]);
  }

  for (int i = 1; i < TAMANHO_IMG - 1; i++)
  {
    for (int j = 1; j < TAMANHO_IMG - 1; j++)
    {
      mats_glcm[0][image[i][j]][image[i + 1][j + 1]]++;
      mats_glcm[1][image[i][j]][image[i + 1][j]]++;
      mats_glcm[2][image[i][j]][image[i + 1][j - 1]]++;
      mats_glcm[3][image[i][j]][image[i][j + 1]]++;
      mats_glcm[4][image[i][j]][image[i][j - 1]]++;
      mats_glcm[5][image[i][j]][image[i - 1][j + 1]]++;
      mats_glcm[6][image[i][j]][image[i - 1][j]]++;
      mats_glcm[7][image[i][j]][image[i - 1][j - 1]]++;
    }
  }
  for (int n = 0; n < 8; n++)
  {
    vet_glcm[n]=contraste(mats_glcm[n]);
    vet_glcm[n+8]=energia(mats_glcm[n]);
    vet_glcm[n+16]=homogeneidade(mats_glcm[n]);
  }
  // liberando memoria
  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < DIM_GLCM; j++)
    {
      free(mats_glcm[i][j]);
    }
    free(mats_glcm[i]);
  }
  free(mats_glcm);

  //obs.1:matriz glcm é 256x256

  return vet_glcm;
}

// Objetivo: Incrementa a matriz GLCM
// Parâmetro: posição da imagem, posição vizinha, ponteiro para a GLCM
// Retorno:

void inc_glcm(int *posicao_imagem, int *vizinho, int *m_glcm)
{
  // Declarações:

  // Instruções:

  (*(m_glcm + (*posicao_imagem) * 256 + (*vizinho)))++;

  return;
}

// Objetivo: Calcula contraste
// Parâmetro: ponteiro para matriz glcm
// Retorno: contraste da matriz

int *contraste(int *m_glcm)
{
  // Declarações:
  int n_contraste;

  // Instruções:

  for (int i = 0; n < DIM_GLCM; i++)
  {
    for (int j = 0; j < DIM_GLCM; j++)
    {
      n_contraste+= m_glcm[i][j]*pow((i-j),2));
    }
  }

  return n_contraste;
}

// Objetivo: Calcula energia
// Parâmetro: ponteiro para matriz glcm
// Retorno: energia da matriz

int energia(int *m_glcm)
{
  // Declarações:
  int n_energia;
  // Instruções:
  for (int i = 0; n < DIM_GLCM; i++)
  {
    for (int j = 0; j < DIM_GLCM; j++)
    {
      n_energia += pow((m_glcm[i][j]),2));
    }
  }
  return n_energia;
}
// Objetivo: Calcula homogeneidade
// Parâmetro: ponteiro para matriz glcm
// Retorno: homogeneidade da matriz

int homogeneidade(int *m_glcm)
{
  // Declarações:
  int n_homogeneidade;
  // Instruções:

  for (int i = 0; n < DIM_GLCM; i++)
  {
    for (int j = 0; j < DIM_GLCM; j++)
    {
      n_homogeneidade += m_glcm[i][j]/(1 + pow((i-j),2));
    }
  }
  return n_homogeneidade;
}

//////////////////////////////OUTRAS FUNÇÕES//////////////////////////

// Objetivo: Normalizar vetor de features
// Parâmetro: ponteiro para o vetor
// Retorno: vetor normalizado

void normaliza_vet(float *vetor, int tam)
{
  // Declarações:
  float minimo, maximo;
  int i;
  // Instruções:

  minimo = *vetor;
  maximo = *vetor;

  for (i = 0; i < tam; i++)
  {
    if (minimo > *(vetor + i))
      minimo = *(vetor + i);
  }

  for (i = 0; i < tam; i++)
  {
    if (maximo < *(vetor + i))
      maximo = *(vetor + i);
  }

  for (i = 0; i < tam; i++)
  {
    *(vetor + i) = (*(vetor + i) - minimo) / (maximo - minimo);
  }

  return;
}

// Objetivo: Calcular a distância euclidiana entre 2 vetores de features
// Parâmetro: ponteiro para vetor 1, e vetor 2
// Retorno: distância euclidianda

double calcula_dist_eucl(float *vetor1, float *vetor2, int tam)
{
  // Declarações:
  double dist_eucl = 0;
  int i;
  // Instruções:

  for (i = 0; i < tam; i++)
  {
    dist_eucl += (double)((*(vetor1 + i) - *(vetor2 + i)) * (*(vetor1 + i) - *(vetor2 + i)));
  }

<<<<<<< HEAD
  dist_eucl = sqrt(dist_eucl);
  printf("%f\n", dist_eucl);
=======
    dist_eucl= sqrt(dist_eucl);
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72

  return dist_eucl;
}

// Objetivo: tirar média dos vetores de features usados no treinamento
// Parâmetro: ponteiro para matriz de features
// Retorno: ponteiro para vetor da média

float *media_vet_feat(float *vet_feat, int num_img)
{
  // Declarações:
  float *p_media_feat;
  int i, aux;
  // Instruções:
  p_media_feat = (float *)calloc(TAM_VET_FEAT, sizeof(float));

  for (i = 0; i < num_img; i++)
  {
    for (aux = 0; aux < TAM_VET_FEAT; aux++)
    {
      *(p_media_feat + aux) += *(vet_feat + i * TAM_VET_FEAT + aux);
    }
  }

  for (i = 0; i < TAM_VET_FEAT; i++)
  {
    *(p_media_feat + i) /= num_img;
  }

  return p_media_feat;
}

// Objetivo: Mostrar resultados finais
// Parâmetro: Número de acertos, número de falsas aceitações, número
//            de falsas rejeições
// Retorno:

void lista_resultado(int acertos, int falsa_rej, int falsa_acei)
{
  // Declarações:
  float taxa_acer;
  float taxa_fals_acei;
  float taxa_fals_rej;
  // Instruções:

<<<<<<< HEAD
  taxa_acer = 100 * ((float)acertos) / 50;
  taxa_fals_rej = 100 * ((float)falsa_rej) / 50;
  taxa_fals_acei = 100 * ((float)falsa_acei) / 50;
=======
    taxa_acer= 100*((float)acertos)/NUM_IMG;
    taxa_fals_rej= 100*((float)falsa_rej)/NUM_IMG;
    taxa_fals_acei= 100*((float)falsa_acei)/NUM_IMG;
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72

  printf("taxa de acerto: %2f\n", taxa_acer);
  printf("taxa de falsa rejeição: %2f\n", taxa_fals_rej);
  printf("taxa de falsa aceitação: %2f\n", taxa_fals_acei);

<<<<<<< HEAD
  return;
=======
    printf("taxa de acerto: %.2f%%\n", taxa_acer);
    printf("taxa de falsa rejeição: %.2f%%\n", taxa_fals_rej);
    printf("taxa de falsa aceitação: %.2f%%\n", taxa_fals_acei);

    return;
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72
}
// Objetivo: Ler txt que contém imagem
// Parâmetro: byte se for asfalto(0) ou grama(1), numero da imagem a ser lida
// Retorno:  matriz em tons de cinza
int *le_imagem(char asf_gram, int num_img)
{
  // Declarações:
  int *imagem;
  int i = 0, cont_img = 0;
  char numero[4];
  char nome_arq[31];
  FILE *arq_imagem;
  // Instruções:
  imagem = (int *)malloc(TAMANHO_IMG * sizeof(int));
  if (asf_gram)
  {
    strcpy(nome_arq, "DataSet/grass/grass_01.txt");
    nome_arq[20] = '0' + num_img / 10;
    nome_arq[21] = '0' + num_img % 10;
  }
  else
  {
    strcpy(nome_arq, "DataSet/asphalt/asphalt_01.txt");
    nome_arq[24] = '0' + num_img / 10;
    nome_arq[25] = '0' + num_img % 10;
  }
  arq_imagem = fopen(nome_arq, "r");

  while (!feof(arq_imagem))
  {
    if (!fread(numero + i, sizeof(char), 1, arq_imagem))
      break;
    if (numero[i] == ';' || numero[i] == '\n')
    {
      numero[i] = '\0';
      *(imagem + cont_img) = atoi(numero);
      cont_img++;
      i = 0;
    }
    else
      i++;
  }

  fclose(arq_imagem);

  return imagem;
}

// Objetivo: Calcular vetor de features
// Parâmetro: byte se for asfalto(0) ou grama(1), numero da imagem a ser lida, e ponteiro para vetor de features
// Retorno:  vetor de features calculado

<<<<<<< HEAD
void calcula_vet_feat(char asf_gram, int num_img, float *vet_feat)
{
  // Declarações:
  int *imagem;
  int *vet_ilbd;
  int *vet_glcm;
  int i;

  // Instruções:
  imagem = le_imagem(asf_gram, num_img);
  vet_ilbd = ilbd(imagem);
  vet_glcm = glcm(imagem);

  for (i = 0; i < 512; i++)
  {
    *(vet_feat + i) = (float)(*(vet_ilbd + i));
  }

  for (i = 0; i < 4; i++)
  {
    *(vet_feat + 512 + i) = (float)(*(vet_glcm + i));
  }
=======
void calcula_vet_feat(char asf_gram, int num_img, float* vet_feat){
    // Declarações:
    int *imagem;
    int *vet_ilbd;
    int *vet_glcm;
    int i;

    // Instruções:
    imagem = le_imagem(asf_gram, num_img);
    vet_ilbd = ilbd(imagem);
    vet_glcm = glcm(imagem);

    for(i=0; i<TAM_ILBD; i++){
        *(vet_feat+i)=(float)(*(vet_ilbd+i));
    }

    for(i=0; i<4; i++){
        *(vet_feat+TAM_ILBD+i)=(float)(*(vet_glcm+i));
    }
>>>>>>> 9a66df01ccc4440aa4f15e2422c5b5dc2ef42e72

  normaliza_vet(vet_feat, TAM_VET_FEAT);

  free(vet_ilbd);
  free(vet_glcm);
  free(imagem);

  return;
}

// Objetivo: Gerar números aleatórios
// Parâmetro: byte pra zerar números usados ou não
// Retorno:  número aleatório

int gera_num_alea(char zera)
{
  // Declarações:
  int num_alea, i;
  static char num_usados[NUM_IMG] = {0};

  // Instruções:
  if (zera)
  {
    for (i = 0; i < NUM_IMG; i++)
    {
      num_usados[i] = 0;
    }
    return 0;
  }
  else
  {
    do
    {
      num_alea = rand() % NUM_IMG;
    } while (num_usados[num_alea]);

    num_usados[num_alea] = 1;

    return num_alea + 1;
  }
}

// Objetivo: Decidir a partir de vetor de features, se o vetor testado é grama ou asfalto
// Parâmetro: vetores de features de teste, de treinamento da grama, e de treinamento de asfalto
// Retorno:  byte se for grama (0), ou asfalto (1)

char grama_ou_asfalto(float *vet_feat_teste, float *feat_grama, float *feat_asfalto)
{
  // Declarações:
  int dist_grama, dist_asfalto;
  // Instruções:
  dist_grama = calcula_dist_eucl(vet_feat_teste, feat_grama, TAM_VET_FEAT);
  dist_asfalto = calcula_dist_eucl(vet_feat_teste, feat_asfalto, TAM_VET_FEAT);

  if (dist_grama < dist_asfalto)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
void verifica_aloc_float(float *aloc)
{
  if (aloc == NULL)
  {
    print("alocaçao falhou!");
  }
}
void verifica_aloc_int(int *aloc)
{
  if (aloc == NULL)
  {
    print("alocaçao falhou!");
  }
}