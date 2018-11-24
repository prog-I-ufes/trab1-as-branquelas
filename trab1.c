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

    char arq_dtr[50],arq_dte[50],arq_s[50];
    readpaths (arq_dtr,arq_dte,arq_s, f1); //lendo as paths do arquivo config

    
    //Até aqui ta certo!

    mat_te = aloca (arq_dte,lc_te);
    mat_tr = aloca (arq_dtr,lc_tr); 
    

    //Até aqui ta certo!

    int taml_te = lc_te[0], tamc_te = lc_te[1];
    int taml_tr = lc_tr[0], tamc_tr = lc_tr[1];
    
    //Até aqui ta certo!

    float **dist, **du_dist, **kp;
    dist = cria_mat (taml_te,taml_tr);
    du_dist = cria_mat (taml_te,taml_tr);
    kp = cria_mat (taml_te,taml_tr);

    int k[lconf-3];
    char d[lconf-3];
    float r[lconf-3];

    configknn (k,d,r,f1,lconf);
    
    //Até aqui ta certo!
    
    int **rot={0};
    rot = cria_mat_int((lconf-3),taml_te);
    
    
    for (int i =0;i < (lconf-3);i++){
       rot[i]= calc_dists (mat_te, mat_tr, dist, du_dist, kp, taml_te, tamc_te, taml_tr, lconf, k[i], d[i], r[i],rot[i]);

    }

    printmat_int(rot,(lconf-3),taml_te);


    libera_matriz (taml_te,dist);
    libera_matriz (taml_te,du_dist);
    libera_matriz (taml_te,kp);
    libera_matriz (taml_te,mat_te);
    libera_matriz (taml_tr,mat_tr);
    libera_matriz_int((lconf-3),rot);
    fclose (f1);
    return 0;
}