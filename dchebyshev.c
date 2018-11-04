#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//P e Q são dois pontos n-dimensionais
//tam é a dimensão de p e q;
//Dist é a distancia entre os dois vetores.
//aux é um vetor auxiliar que contem |pi-qi|.
//Nessa função a maior diferença entra os |pi-q1| é a distancia maxima.
float dist_chebyshev(float *p, float *q,int tam){
	float dist,aux[tam];
	int i;
    for (i = 0; i < tam; ++i)
    {
    	aux[i]=sqrt(pow(p[i]-q[i],2));
    	//Essa expressão(sqrt(pow(p[i]-q[i],2))) = |p[i]-q[i]|
    }
    dist = aux[0];
    for (i = 0; i < tam; ++i)
    {
    	if (dist < aux[i])
    	{
    		dist = aux[i];
    	}
    }
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
    dist = dist_chebyshev(p,q,tam);
    printf("Distacia=%f\n",dist );
    return 0;
}