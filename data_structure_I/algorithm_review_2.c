#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
2. Faça um programa para, a partir de um vetor dinâmico de cinco structs Estudante, mostrar os nomes da pessoa mais
    baixa, de mais alta, mais velha e da mais nova. Não esqueça de usar free no final. Obviamente Estudante deve ter
    campos para idade e altura (idade int e altura double).
*/

typedef struct
{
    char nome[100];
    int idade;
    double altura;
} Estudante;

int main()
{
    int i=0, maior = 0, menor = 50;
    double altMaior = 0, altMenor = 10000;
    int idMaior = 0, idMenor = 0, idMaisVelho = 0, idMaisNovo = 0;

    Estudante* estudante;
    estudante = (Estudante*)malloc(5*sizeof(Estudante));
    
    if(estudante == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    strcpy(estudante[0].nome, "Joao");
    estudante[0].idade = 12;
    estudante[0].altura = 1.30;
    strcpy(estudante[1].nome, "Maria");
    estudante[1].idade = 15;
    estudante[1].altura = 1.40;
    strcpy(estudante[2].nome, "Jurema");
    estudante[2].idade = 13;
    estudante[2].altura = 1.24;
    strcpy(estudante[3].nome, "Jose");
    estudante[3].idade = 11;
    estudante[3].altura = 1.35;
    strcpy(estudante[4].nome, "Rosa");
    estudante[4].idade = 13;
    estudante[4].altura = 1.21;

    for (i=0; i<5; i++)
    {
        if(estudante[i].idade>maior)
        {
            maior = estudante[i].idade;
            idMaisVelho = i;
        }
        if(estudante[i].idade<menor)
        {
            menor = estudante[i].idade;
            idMaisNovo = i;
        }
        if(estudante[i].altura>altMaior)
        {
            altMaior = estudante[i].altura;
            idMaior = i;
        }
        if(estudante[i].altura<altMenor)
        {
            altMenor = estudante[i].altura;
            idMenor = i;
        }
    }
    printf("Estudante mais velho: %s\n",estudante[idMaisVelho].nome);
    printf("Estudante mais novo: %s\n",estudante[idMaisNovo].nome);
    printf("Estudante mais alto: %s\n",estudante[idMaior].nome);
    printf("Estudante mais baixo: %s\n",estudante[idMenor].nome);

    free(estudante);
    estudante = NULL;

    return 0;
}