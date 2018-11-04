#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist_euclidiana (float *p,float *q,int tam ){
     float dist=0;
     int i;
     for (i = 0; i < tam; ++i)
     {
     	dist = dist + pow((p[i]-q[i]),2);
     }
     dist = sqrt(dist);
     return dist;
}

int main(){
	int tam,i;
	printf("Dimensão do vetor:\n");
	scanf(" %d",&tam);
	printf("Vetor 1:\n");
	float p[tam],q[tam],dist;
	for ( i = 0; i < tam; ++i)
	{
		scanf(" %f",&p[i]);
	}
	printf("Vetor 2:\n");
	for ( i = 0; i < tam; ++i)
	{
		scanf(" %f",&q[i]);
	}
	dist = dist_euclidiana(p,q,tam);
	printf("Distancia euclidiana = %f\n",dist );
	return 0;
}