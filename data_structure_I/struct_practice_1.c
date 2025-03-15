#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*1. a) Crie uma struct "Estudante" com campos nome, matrícula, idade. Instancie 5 estruturas desse tipo na main.
Em seguida, preencha seus dados e apresente-os na tela, sequencialmente.

 b) Permita uma busca (sequencial) nos registros cadastrados pelo nome ou pela matrícula - O usuário fornece o valor
e seu programa busca e apresenta o registro completo.*/

typedef struct estudante
{
    char nome[100];
    char matricula[20];
    int idade;
} Estudante;

int main()
{
    int i = 0;
    char busca[100];
    Estudante* alunos;
    alunos = (Estudante*)malloc(5*sizeof(Estudante));

    for(i=0; i<5; i++)
    {
        strcpy(alunos[i].nome, "Joao");
        strcpy(alunos[i].matricula, "01");
        alunos[i].idade = 11;

    }

    strcpy(alunos[1].nome, "Maria");
    strcpy(alunos[1].matricula, "02");
    alunos[1].idade = 12;
    
    /*
    strcpy(alunos[0].nome, "Joao");
    strcpy(alunos[0].matricula, "01");
    alunos[0].idade = 11;

    strcpy(alunos[1].nome, "Maria");
    strcpy(alunos[1].matricula, "02");
    alunos[1].idade = 12;

    strcpy(alunos[2].nome, "Jose");
    strcpy(alunos[2].matricula, "03");
    alunos[2].idade = 11;

    strcpy(alunos[3].nome, "Jeremias");
    strcpy(alunos[3].matricula, "04");
    alunos[3].idade = 11;

    strcpy(alunos[4].nome, "Rosa");
    strcpy(alunos[4].matricula, "05");
    alunos[4].idade = 13;
*/

    for(i=0; i< 5; i++)
    {
        printf("Nome: %s , Matricula: %s, idade: %d\n", alunos[i].nome,alunos[i].matricula, alunos[i].idade);
        printf("\n");
    }

    printf("insira o nome ou a matricula para a busca: \n");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = 0;

    for(i=0; i< 5; i++)
    {
        if(strcmp(busca,alunos[i].nome)==0) {printf("Nome: %s , Matricula: %s, idade: %d\n", alunos[i].nome,alunos[i].matricula, alunos[i].idade);}
        else if(strcmp(busca,alunos[i].matricula)==0)printf("Nome: %s , Matricula: %s, idade: %d\n", alunos[i].nome,alunos[i].matricula, alunos[i].idade);
    }

    for(i=0; i< 5; i++)
    {
        strcpy(alunos[i].nome, "00000000");
        strcpy(alunos[i].matricula, "0000000");
        alunos[i].idade = 0;
    }

    free(alunos);
    alunos = NULL;

    return 0;
}