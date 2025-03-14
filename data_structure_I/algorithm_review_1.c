#include <stdio.h>
#include <stdlib.h>

/*
1. Crie uma struct Teste, com três campos inteiros Dado1, Dado2 e Dado3. Instancie duas váriaveis do tipo Teste
    na main, uma estática e outra dinâmica. Implemente um algoritmo para intercambiar os conteúdos de ambas.
    Imprima os dados antes e depois da troca.
*/
typedef struct
{
    int dado1, dado2, dado3;
} Teste;

void PrintaDados(Teste t1, Teste* t2)
{
    printf("estatico 1 : %d, estatico 2 : %d, estatico 3 : %d\n", t1.dado1,t1.dado2,t1.dado3);
    printf("dinamico 1 : %d, dinamico 2 : %d, dinamico 3 : %d\n\n", t2->dado1,t2->dado2,t2->dado3);
}

void TrocaDados(Teste* t1, Teste* t2)
{
    int a,b,c;
    a = t2->dado1;
    b = t2->dado2;
    c = t2->dado3;

    t2->dado1 = t1->dado1;
    t2->dado2 = t1->dado2;
    t2->dado3 = t1->dado3;

    t1->dado1 = a;
    t1->dado2 = b;
    t1->dado3 = c;
    printf("Mudancas foram feitas!\n");
}

int main()
{
    Teste t1;
    Teste* t2;
    t2 = (Teste*)malloc(sizeof(Teste));

    t1.dado1 = 10;
    t1.dado2 = 20;
    t1.dado3 = 30;
    t2->dado1 = 50;
    t2->dado2 = 40;
    t2->dado3 = 5;

    PrintaDados(t1, t2);
    TrocaDados(&t1, t2);
    PrintaDados(t1, t2);

    free(t2);
    return 0;
}