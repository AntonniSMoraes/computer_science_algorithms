#include <stdio.h>
#include <stdlib.h>

/*
    4. Faça um programa para ler 100 números inteiros de um arquivo e imprimir o maior e o menor na tela.
*/

int main()
{
    FILE* numerosRand;
    int valores[100];
    numerosRand = fopen("aleatorios.txt", "r");

    if(numerosRand == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    int i=0;
    int maior = 0, menor = 100;
    
    for (i=0; i<100; i++)
    {
        fscanf(numerosRand, "%d ", &valores[i]);
    }
    
    for (i=0; i<100; i++)
    {
        if(valores[i]>maior) maior = valores[i];
        if(valores[i]<menor) menor = valores[i];
    }

    printf("maior valor: %d \nmenor valor: %d\n", maior, menor);
    fclose(numerosRand);
    return 0;
}
