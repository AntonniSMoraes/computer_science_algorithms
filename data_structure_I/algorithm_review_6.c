#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Videojogo{
    char* Titulo;
    char* Plataforma;
    char* Fabricante;
    int ano;
}Jogo;

void Pesquisa(Jogo* jogo){

    fflush(stdin);
    char nome[50];
    int i;

    printf("Digite o nome: \n");
    fgets(nome, sizeof(nome), stdin);
    for (i=0; i<4; i++){
        if(strcmp(nome,jogo[i].Titulo)==0){
            printf("Titulo: %s\nPlataforma: %s\nFabricante: %s\nAno: %i\n",jogo[i].Titulo,jogo[i].Plataforma,jogo[i].Fabricante, jogo[i].ano);
        }
    }
}

void Registro(Jogo* jogo){
    int i;
    for(i = 0; i<4; i++){
        if(strcmp(jogo[i].Titulo, "00000")==0){
            printf("Insira o nome do jogo: \n");
            fgets(jogo[i].Titulo, sizeof(jogo[i].Titulo), stdin);
            printf("Insira a plataforma do jogo: \n");
            fgets(jogo[i].Plataforma, sizeof(jogo[i].Plataforma), stdin);
            printf("Insira o fabricante do jogo: \n");
            fgets(jogo[i].Fabricante, sizeof(jogo[i].Fabricante), stdin);
            printf("Insira o ano do jogo: \n");
            scanf("%i", &jogo[i].ano);
        }
    }
}

void Menu(Jogo* jogo){
    char resposta;
    do{
        printf("1 - Registrar Jogo\n2 - Pesquisar\n3 - Sair\n");
        fflush(stdin);
        scanf("%c", &resposta);
        if(resposta == '1'){
        Registro(jogo);
        } else if(resposta == '2'){
        Pesquisa(jogo);
        }
    }while(resposta != '3');
}

int main(){
    Jogo* jogo;
    jogo = (Jogo*)malloc(4*sizeof(Jogo));
    
    int i;
    
    for(i = 0; i <4; i++){
        jogo[i].Titulo = "00000";
        jogo[i].Plataforma = "00000";
        jogo[i].Fabricante = "00000";
        jogo[i].ano = 0000;
    }
    Menu(jogo);
    
    free(jogo);

    return 0;
}