#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//P e Q são dois pontos n-dimensionais
//tam é a dimensão de p e q;
//raio de distância escolhido
//Dist é a distancia entre os dois vetores tendo como referencia um raio r.
float dist_minkowsky (float *p, float *q,int tam,float r){
	float dist=0;
	int i;
	for (i = 0; i < tam; ++i)
	{
		dist = dist + pow((sqrt(pow(p[i]-q[i],2))),r); 
		//Essa expressão(sqrt(pow(p[i]-q[i],2))) = |p[i]-q[i]|;
	}
	dist = pow(dist,1/r);
	return dist;
}
 int main(){
 	int tam,i;
 	printf("Dimensão do vetor:\n");
 	scanf(" %d",&tam);
 	float p[tam],q[tam],r,dist;
 	printf("Vetor 1:\n");
 	for ( i = 0; i < tam; ++i)
 	{
 		scanf(" %f",&p[i]);
 	}
    printf("Vetor 2:\n");
    for (i = 0; i < tam; ++i)
    {
    	scanf(" %f",&q[i]);
    }
    printf("Raio: \n");
    scanf(" %f",&r);
    dist = dist_minkowsky(p,q,tam,r);
    printf("Distancia = %f\n",dist );
 }