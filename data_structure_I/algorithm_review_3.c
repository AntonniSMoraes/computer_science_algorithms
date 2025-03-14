#include <stdio.h>
#include <stdlib.h>

/*
    3. Crie um programa para escrever 100 números aleatórios em um arquivo.
*/

int main()
{
    FILE* numerosRand;
    numerosRand = fopen("aleatorios.txt", "w");

    if(numerosRand == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int i=0, j=0;

    for(j=0; j<10; j++)
    {
        for(i=0; i<10; i++)
        {
            fprintf(numerosRand, "%d ", rand()%100);
        }
        fprintf(numerosRand, "\n");
    }

    fclose(numerosRand);
    return 0;
}