#include <stdio.h>
#include <stdlib.h>

/*
5. Corrija os erros no programa abaixo, que deveria criar uma imagem e imprimir
    os valores dos pixels no terminal.

#include <studio.h>
#include <stdlib.h>

struct imagem{  // struct para uma imagem em tons de cinza
   int largura;
   int altura;
   int pixel[altura][largura];
};
int main(void){
 int i,j;
 imagem fig1;
 
 for (i=0;i<largura;i++)
   for (j=0;j<altura;j++)
      fig1.pixel[i][j]=rand()%256;
 
 for (i=0;i<largura;i++)
   for (j=0;j<altura;j++)
      printf("%d ",fig1.pixel[i][j]);
 
  return 0;
 }

*/

#define LARGURA 640
#define ALTURA 480

typedef struct imagem{  // struct para uma imagem em tons de cinza
   int pixel[LARGURA][ALTURA];
}Img;

void criaImg(Img* img) {
    FILE* imgFile;
    imgFile = fopen("imagem.ppm", "w");

    if(imgFile == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fprintf(imgFile, "P3\n%d %d\n255\n", LARGURA, ALTURA);

    for (int i=0;i<LARGURA;i++)
        for (int j=0;j<ALTURA;j++)
            fprintf(imgFile, "%d ", img->pixel[i][j]);
    
    fclose(imgFile);
}

void printImg(Img* img){
    for (int i=0;i<LARGURA;i++)
        for (int j=0;j<ALTURA;j++)
            printf("%d ",img->pixel[i][j]);
}

int main(void){
    int i,j;
    Img* fig1;

    fig1 = (Img*) malloc (sizeof(Img));

    for (i=0;i<LARGURA;i++)
    for (j=0;j<ALTURA;j++)
        fig1->pixel[i][j]=rand()%256;

    printf("P3\n%d %d\n255\n", LARGURA, ALTURA);

    printImg(fig1);
    criaImg(fig1);

    for (i=0;i<LARGURA;i++)
    for (j=0;j<ALTURA;j++)
        fig1->pixel[i][j]=0000;

    free(fig1);
    fig1 = NULL;
return 0;
 }
