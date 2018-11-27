#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trablib.h"

int main (){
    FILE *f1;
    f1 = fopen ("config.txt", "r");
    
    int lconf=0;
    lconf = tam_linha (f1);
    lconf--;
    rewind (f1);

    float **mat_te,**mat_tr;
    int lc_te[2],lc_tr[2];

    char *arq_dtr,*arq_dte,*arq_s;
    arq_dtr = readpaths (arq_dtr,f1);
    arq_dte = readpaths (arq_dte, f1);
    arq_s = readpaths (arq_s, f1); 


    //lendo as paths do arquivo config
    
    printf("Lendo os arquivos \n \n");
    
    //Até aqui ta certo!

    mat_te = aloca (arq_dte,lc_te);
    mat_tr = aloca (arq_dtr,lc_tr); 

    
    printf("Alocando os valores do treino e teste nas matrizes \n \n");
    //Até aqui ta certo!

    int taml_te = lc_te[0], tamc_te = lc_te[1];
    int taml_tr = lc_tr[0], tamc_tr = lc_tr[1];
    

    //Até aqui ta certo!

    Distancias **teste;
    teste = cria_mat_dist(taml_te,taml_tr);
    for(int i=0;i < taml_te;i++){
        for(int j=0;j < taml_tr;j++){
            teste[i][j].dt = 0;
        }
    }
    
    int  **kp;
    kp = cria_mat_int (taml_te,taml_tr);

    int k[lconf-3];
    char d[lconf-3];
    float r[lconf-3];

    configknn (k,d,r,f1,lconf);

    printf("Pegando os valores do config knn \n \n");
    
    //Até aqui ta certo!
    
    int **rot={0};
    rot = cria_mat_int((lconf-3),taml_te);
    
    printf("Calculando as distancias \n \n");
    for (int i =0;i < (lconf-3);i++){
       calc_dists (mat_te, mat_tr,teste, kp, taml_te, tamc_te, taml_tr, lconf, k[i], d[i], r[i],rot[i]);

    }

    //Criando os arquivos prediçoes
    
    printf("Criando os arquivos das prediçoes \n \n");

    char **pred;
    pred = cria_mat_char((lconf-3),(8 + taml_te));
    cria_pred((lconf-3),pred,arq_s);

    printf("Colocando/calculando os valores e printando nas prediçoes \n \n");
    predicoes (mat_te,taml_te,tamc_te,rot,lconf,arq_s,pred);



    libera_matriz_int (taml_te,kp);
    libera_matriz (taml_te,mat_te);
    libera_matriz (taml_tr,mat_tr);
    libera_matriz_int((lconf-3),rot);
    libera_matriz_char((lconf-3),pred);
    libera_matriz_dist(taml_te,teste);
    free(arq_dte);
    free(arq_dtr);
    free(arq_s);
    fclose (f1);
    return 0;
}