#ifndef TRABLIB_H
#define TRABLIB_H

struct distancias{
    float dt;
    int pos;
};

typedef struct distancias Distancias;

void ler_path(FILE *path, float **mat,int taml,int tamc);

int tam_coluna(FILE *path);

int tam_linha(FILE *path);

void libera_matriz(int l,float **mat);

void libera_matriz_int(int l,int **mat);

void libera_matriz_char(int l,char **mat);

void libera_matriz_dist(int l, Distancias **mat);

void dist_euclidiana (float **mat_te,float **mat_tr,Distancias **dist,int taml_te,int tamc,int taml_tr );

void dist_minkosky (float **mat_te,float **mat_tr,Distancias **dist,int taml_te,int tamc,int taml_tr,float r );

void dist_chebyshev(float **mat_te, float **mat_tr,Distancias **dist,int taml_te,int tamc,int taml_tr);

void insertionSort(float *vet, int tam );

void insertionSort_te(Distancias *vet, int tam );

void k_proximos(Distancias **dist,int k,int **kp,int taml_te,int taml_tr);

int quant_rotulo(float **mat_tr,int taml_tr,int tamc);

int* rotulo_final(int **pos, int *rot,int num_rot,int taml_te, int k);

void printmat (float **mat, int nl, int nc);

void printmat_int (int **mat, int nl, int nc);

void configknn (int k[], char d[], float r[], FILE *f1, int lconf);

void treatstr (char s[]);

char* readpaths (char *dtreino, FILE *f1);

void openfile (char name[]);

float** aloca (char arq[],int v[2]);

float** cria_mat (int l, int c);

int** cria_mat_int (int l, int c);

char** cria_mat_char (int l, int c);

Distancias** cria_mat_dist(int l, int c);

void calc_dists (float **mat_te, float **mat_tr, Distancias **dist, int **kp, int taml_te,int tamc,int taml_tr, int lconf, int k, char d, float r,int *rot);

int soma_dp (int n, int mat[n][n]);

void inicializamat (int nl, int nc, int mat[nl][nc]);

void printmatestat (int nl, int nc, int mat[nl][nc],FILE *pr);

int* lastc (float **mat, int tamc, int taml);

void cria_pred(int taml,char **pred,char *arq_s);  

void printv (int *v, int tamv,FILE *pr);

void predicoes (float **mat_te, int taml_te, int tamc_te,int **rot, int lconf, char saida[],char **pred);

void rotula_te (int taml_te, int taml_tr, int k, int tamc, float **mat_tr,  int **kp,int *rot);
#endif