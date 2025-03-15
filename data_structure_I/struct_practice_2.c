#include <stdio.h>
#include <stdlib.h>

/*
2) a) Crie uma struct "Pixel" com os campos int ou unsigned char R, G e B. Em seguida, crie um vetor dinâmico de Pixel na memória (usando malloc)
    para 384 x 216 (82944 posições). Varra o vetor de structs e preencha os campos de cada uma com os valores: 255, 0, 128.

   b) Inclua um comando printf para mostrar na tela o seguinte :"P3\n384 216\n255\n" Em seguida, imprima em sequência os valores de todos os campos
    R G B separados por espaços.  Ao final, utilize o comando free para liberar a memória utilizada.
*/

typedef struct pixel
{
    int r;
    int g;
    int b;
}Pixel;

int main()
{
    int i = 0, j=0;
    Pixel* p1;

    p1 = (Pixel*) malloc(82944*sizeof(Pixel));

    printf("P3\n384 216\n255\n");
    
    for(i=0; i<82944; i++)
    {
            p1[i].r = 255;
            p1[i].g = 0;
            p1[i].b = 128;
    }

    // for(i=0; i<82944; i++)
    // {
    //         p1[i].r = rand()%255;
    //         p1[i].g = rand()%255;
    //         p1[i].b = rand()%255;
    // }

    for(i=0; i<82944; i++)
    {
            printf("%d %d %d ",p1[i].r, p1[i].g, p1[i].b);
    }

    free(p1);
    p1 = NULL;

    return 0;
}