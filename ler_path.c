#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_path(FILE *path, float **mat){
	path = fopen("iris/dataset/iris_treino.csv","r");
	if(path==NULL){
    printf("Erro ao abrir o arquivo\n");
    exit(1);
  }
  for (int i = 0; i < 3; ++i)
   {
   	for (int j = 0; j < 3; ++j)
   	{
   		fscanf(path,"%f,",&mat[i][j]);
   	    printf("%f\n",mat[i][j]);
   	}
   }
   fclose(path);
}

int main(){
    FILE *path;
    float **mat;
    mat = (float**)malloc(3*sizeof(float*));
    for (int i = 0; i < 3; ++i)
    {
    	mat[i]=(float*)malloc(3*sizeof(float));
    }
    ler_path(path,mat);
    free(mat);
	return 0;
}
