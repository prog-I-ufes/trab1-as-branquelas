#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void configknn (int *k, char *d, float *r, FILE *f1){
    int a=0;
    char b;
    float c=0.0;
    fscanf (f1, "%i, %c", &a, &b);
    if (b=='M'){
        fscanf (f1,", %f", &c);
    }
    *k=a;
    *d=b;
    *r=c;
}

void readpaths (char dtreino[], char dteste[], char saida[], FILE *f1){
    FILE *f2;
    fgets (dtreino,50,f1);
    fgets (dteste,50,f1);
    fgets (saida,50,f1);

    f2 = fopen ("saida.txt", "w");
    fprintf (f2, "%s%s%s",dtreino, dteste,saida);
    fclose (f2);
}

int main (){
    FILE *f1;
    f1 = fopen ("entrada.txt", "r");

    char arq_dtr[50],arq_dte[50],arq_s[50];
    readpaths (arq_dtr,arq_dte,arq_s, f1);
    
    int k=0;
    char d;
    float r;
    configknn (&k, &d, &r, f1);
    printf (" %i %c %.2f\n", k, d, r);
    fclose (f1);
}