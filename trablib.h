#ifndef TRABLIB_H
#define TRABLIB_H

void ler_path(FILE *path, float **mat,int taml,int tamc);

int tam_coluna(char *l1);

int tam_linha(FILE *path);

void libera_matriz(int l,float **mat);

void libera_matriz_int(int l,int **mat);

int tam_str(FILE *path);

void dist_euclidiana (float **mat_te,float **mat_tr,float **dist,int taml_te,int tamc,int taml_tr );

void dist_minkosky (float **mat_te,float **mat_tr,float **dist,int taml_te,int tamc,int taml_tr,float r );

void dist_chebyshev(float **mat_te, float **mat_tr,float **dist,int taml_te,int tamc,int taml_tr);

void duplica_mat(float **dist, float **du_dist,int taml_te,int taml_tr);

void insertionSort(float *vet, int tam );

void k_proximos(float **du_dist,int k,float **kp,int taml_te,int taml_tr);

void busca(float *dist,float *kp,int *pos,int taml_tr,int k);

void rotulo(float **mat_tr,float **dist,float **kp,int **pos,int taml_te,int taml_tr,int tamc,int k);

int quant_rotulo(float **mat_tr,int taml_tr,int tamc);

int* rotulo_final(int **pos, int *rot,int num_rot,int taml_te, int k);

void printmat (float **mat, int nl, int nc);

void printmat_int (int **mat, int nl, int nc);

void configknn (int k[], char d[], float r[], FILE *f1, int lconf);

void treatstr (char s[]);

void readpaths (char dtreino[], char dteste[], char saida[], FILE *f1);

void openfile (char name[]);

float** aloca (char arq[],int v[2]);

float** cria_mat (int l, int c);

int** cria_mat_int (int l, int c);

int* rotula (int taml_te, int taml_tr, int k, int tamc, float **mat_tr, float **dist, float **kp,int*rot);

int* calc_dists (float **mat_te, float **mat_tr, float **dist, float **du_dist, float **kp, int taml_te,int tamc,int taml_tr, int lconf, int k, char d, float r,int* rot);

#endif