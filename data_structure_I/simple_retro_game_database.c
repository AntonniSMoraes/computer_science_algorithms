#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Utilizando vetores dinâmicos de structs em C, crie um programa simples para realizar o cadastro e a consulta de itens de uma coleção de até 1000 retrojogos,
    com a possibilidade de cadastrar novos itens. Os novos itens ainda não precisam ter persistência em disco.
    
    O seu programa deverá ser capaz de permitir ao usuário:

    - o cadastro de novos itens;
    - a consulta por qualquer campo e
    - a visualização dos itens cadastrados. 

    Crie no seu código 10 entradas iniciais para teste, dentre as quais:

    1. Atari 2600 Pitfall II
    2. Sega CD Snatcher
    3. Super Nintendo Super Mario World II
    4. Megadrive Sonic III
    5. NES Megaman

    . Você pode usar dados dos site rarityguide ou pricecharting, se quiser.

    Os campos da estrutura, correspondendo aos atributos mínimos da struct são:

    Nome do item;
    Plataforma;
    Fabricante;
    Ano de lançamento;
    Raridade;
    Preço lacrado;
    Preço na caixa;
    Preço solto;
    Dois links (busca no ebay e emulador)

    Inclua, também, um código sequencial de identificação único para cada item.

    Plus: Permita ao usuário excluir itens.
*/


typedef struct
{
    char nome[100];
    char plataforma[50];
    char fabricante[50];
    char lancamento[5];
    char raridade[20];
    char valorLacrado[20];
    char valorCaixa[20];
    char valorSolto[20];
    char linkCompra[300];
    char linkEmulador[300];
    char id[10];
}Game;

void DezIniciais(Game* jogos)
{
    int i;
        for(i = 0; i<1000; i++)
    {
        strcpy(jogos[i].nome, "00000000000");
        strcpy(jogos[i].plataforma, "00000000000");
        strcpy(jogos[i].fabricante, "00000000000");
        strcpy(jogos[i].lancamento, "00000");
        strcpy(jogos[i].raridade, "00000000000");
        strcpy(jogos[i].valorLacrado, "00000000000");
        strcpy(jogos[i].valorCaixa, "00000000000");
        strcpy(jogos[i].valorSolto, "00000000000");
        strcpy(jogos[i].linkCompra, "00000000000");
        strcpy(jogos[i].linkEmulador, "00000000000");
        strcpy(jogos[i].id, "000000000");
    }
    strcpy(jogos[0].nome, "Pitfall II Lost Caverns");
    strcpy(jogos[0].plataforma, "Atari 2600");
    strcpy(jogos[0].fabricante, "Activision");
    strcpy(jogos[0].lancamento, "1984");
    strcpy(jogos[0].raridade, "40%");
    strcpy(jogos[0].valorLacrado, "$136,25");
    strcpy(jogos[0].valorCaixa, "$81,99");
    strcpy(jogos[0].valorSolto, "$24,63");
    strcpy(jogos[0].linkCompra, "https://www.ebay.com/p/56245813?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G15396_abTestName-control&toolid=10001");
    strcpy(jogos[0].linkEmulador, "https://stella-emu.github.io/");
    strcpy(jogos[0].id, "000000000x");
    strcpy(jogos[1].nome, "Snatcher");
    strcpy(jogos[1].plataforma, "Sega CD");
    strcpy(jogos[1].fabricante, "Konami");
    strcpy(jogos[1].lancamento, "1994");
    strcpy(jogos[1].raridade, "96%");
    strcpy(jogos[1].valorLacrado, "$2.700,00");
    strcpy(jogos[1].valorCaixa, "$1.264,99");
    strcpy(jogos[1].valorSolto, "$1.040,92");
    strcpy(jogos[1].linkCompra, "https://www.ebay.com/p/214706765?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G14763_abTestName-control&toolid=10001");
    strcpy(jogos[1].linkEmulador, "http://www.roxemuladores.com.br/emuladores/mega-drive.aspx");
    strcpy(jogos[1].id, "0000000001");
    strcpy(jogos[2].nome, "Super Mario World 2: Yoshis Island");
    strcpy(jogos[2].plataforma, "Super Famicom");
    strcpy(jogos[2].fabricante, "Nintendo");
    strcpy(jogos[2].lancamento, "1995");
    strcpy(jogos[2].raridade, "53%");
    strcpy(jogos[2].valorLacrado, "$87,00");
    strcpy(jogos[2].valorCaixa, "$33,37");
    strcpy(jogos[2].valorSolto, "$11,82");
    strcpy(jogos[2].linkCompra, "https://www.ebay.com/sch/i.html?_nkw=Super+Mario+World+2+Yoshi%27s+Island+Super+Famicom&_sacat=1249&mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G44662_abTestName-control&toolid=10001");
    strcpy(jogos[2].linkEmulador, "https://rggames.com.br/o-melhor-emulador-de-super-nintendo-para-computador/");
    strcpy(jogos[2].id, "0000000002");
    strcpy(jogos[3].nome, "Sonic the Hedgehog 3");
    strcpy(jogos[3].plataforma, "Sega Genesis");
    strcpy(jogos[3].fabricante, "Sega");
    strcpy(jogos[3].lancamento, "1994");
    strcpy(jogos[3].raridade, "46%");
    strcpy(jogos[3].valorLacrado, "$300,00");
    strcpy(jogos[3].valorCaixa, "$60,50");
    strcpy(jogos[3].valorSolto, "$33,70");
    strcpy(jogos[3].linkCompra, "https://www.ebay.com/p/5784?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G9791_abTestName-control&toolid=10001");
    strcpy(jogos[3].linkEmulador, "https://rggames.com.br/gens-emulador-de-mega-drive-sega-genesis/");
    strcpy(jogos[3].id, "0000000003");
    strcpy(jogos[4].nome, "Mega Man");
    strcpy(jogos[4].plataforma, "Nintendo Entertainment System NES");
    strcpy(jogos[4].fabricante, "Capcom");
    strcpy(jogos[4].lancamento, "1987");
    strcpy(jogos[4].raridade, "74%");
    strcpy(jogos[4].valorLacrado, "$2.957,10");
    strcpy(jogos[4].valorCaixa, "$819,29");
    strcpy(jogos[4].valorSolto, "$95,00");
    strcpy(jogos[4].linkCompra, "https://www.ebay.com/p/4779?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G9314_abTestName-control&toolid=10001");
    strcpy(jogos[4].linkEmulador, "https://rggames.com.br/virtuanes-melhor-emulador-de-nintendo-8bits/");
    strcpy(jogos[4].id, "0000000004");
    strcpy(jogos[5].nome, "Donkey Kong");
    strcpy(jogos[5].plataforma, "Commodore 64");
    strcpy(jogos[5].fabricante, "Atarisoft");
    strcpy(jogos[5].lancamento, "1983");
    strcpy(jogos[5].raridade, "41%");
    strcpy(jogos[5].valorLacrado, "$125,00");
    strcpy(jogos[5].valorCaixa, "$62,50");
    strcpy(jogos[5].valorSolto, "$21,29");
    strcpy(jogos[5].linkCompra, "https://www.ebay.com/itm/265689150069?hash=item3ddc4eb275:g:wqQAAOSwSgdifUNn");
    strcpy(jogos[5].linkEmulador, "https://vice-emu.sourceforge.io/");
    strcpy(jogos[5].id, "0000000005");
    strcpy(jogos[6].nome, "Pokemon Blue Version");
    strcpy(jogos[6].plataforma, "Nintendo Game Boy");
    strcpy(jogos[6].fabricante, "Nintendo");
    strcpy(jogos[6].lancamento, "1998");
    strcpy(jogos[6].raridade, "57%");
    strcpy(jogos[6].valorLacrado, "$1.501,58");
    strcpy(jogos[6].valorCaixa, "$283,39");
    strcpy(jogos[6].valorSolto, "$41,41");
    strcpy(jogos[6].linkCompra,"https://www.ebay.com/p/108927148?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G2979_abTestName-control&toolid=10001");
    strcpy(jogos[6].linkEmulador, "https://rggames.com.br/mgba-o-melhor-emulador-de-game-boy-game-boy-color-game-boy-advance-para-pc/#downloads");
    strcpy(jogos[6].id, "0000000006");
    strcpy(jogos[7].nome, "Contra");
    strcpy(jogos[7].plataforma, "Nintendo Entertainment System NES");
    strcpy(jogos[7].fabricante, "Konami");
    strcpy(jogos[7].lancamento, "1988");
    strcpy(jogos[7].raridade, "50%");
    strcpy(jogos[7].valorLacrado, "$8.500,00");
    strcpy(jogos[7].valorCaixa, "$222,11");
    strcpy(jogos[7].valorSolto, "$41,00");
    strcpy(jogos[7].linkCompra, "https://www.ebay.com/p/170245546?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G12139_abTestName-control&toolid=10001");
    strcpy(jogos[7].linkEmulador, "https://rggames.com.br/virtuanes-melhor-emulador-de-nintendo-8bits/");
    strcpy(jogos[7].id, "0000000007");
    strcpy(jogos[8].nome, "Digimon World");
    strcpy(jogos[8].plataforma, "Sony PlayStation 1");
    strcpy(jogos[8].fabricante, "Bandai");
    strcpy(jogos[8].lancamento, "1999");
    strcpy(jogos[8].raridade, "80%");
    strcpy(jogos[8].valorLacrado, "$80,91");
    strcpy(jogos[8].valorCaixa, "$39,38");
    strcpy(jogos[8].valorSolto, "$20,66");
    strcpy(jogos[8].linkCompra, "https://www.ebay.com/itm/154999974533?hash=item2416b7ea85:g:WAIAAOSwkqliaAMB");
    strcpy(jogos[8].linkEmulador, "https://rggames.com.br/psx-o-melhor-emulador-de-ps1-para-pc/");
    strcpy(jogos[8].id, "0000000008");
    strcpy(jogos[9].nome, "Star Force");
    strcpy(jogos[9].plataforma, "Nintendo Entertainment System NES");
    strcpy(jogos[9].fabricante, "Tecmo");
    strcpy(jogos[9].lancamento, "1987");
    strcpy(jogos[9].raridade, "20%");
    strcpy(jogos[9].valorLacrado, "$176,00");
    strcpy(jogos[9].valorCaixa, "$44,04");
    strcpy(jogos[9].valorSolto, "$6,61");
    strcpy(jogos[9].linkCompra, "https://www.ebay.com/p/170235302?mkevt=1&mkcid=1&mkrid=711-53200-19255-0&campid=5336817478&customid=G12439_abTestName-control&toolid=10001");
    strcpy(jogos[9].linkEmulador, "https://rggames.com.br/virtuanes-melhor-emulador-de-nintendo-8bits/");
    strcpy(jogos[9].id, "0000000009");
}

void Cadastro(Game* jogos)
{
    int i=0;
    for(i=0; i<1000; i++)
    {
        if(strcmp(jogos[i].nome,"00000000000")==0)
        {
            fflush(stdin);
            printf("Digite o nome do jogo: \n");
            fgets(jogos[i].nome, sizeof(jogos[i].nome), stdin);
            printf("Digite a plataforma do jogo: \n");
            fgets(jogos[i].plataforma, sizeof(jogos[i].plataforma), stdin);
            printf("Digite a fabricant do jogo: \n");
            fgets(jogos[i].fabricante, sizeof(jogos[i].fabricante), stdin);
            printf("Digite o Ano de lancamento do jogo: \n");
            fgets(jogos[i].lancamento, sizeof(jogos[i].lancamento), stdin);
            printf("Digite a raridade do jogo: \n");
            fgets(jogos[i].raridade, sizeof(jogos[i].raridade), stdin);
            printf("Digite o valor lacrado do jogo: \n");
            fgets(jogos[i].valorLacrado, sizeof(jogos[i].valorLacrado), stdin);
            printf("Digite o valor na caixa do jogo: \n");
            fgets(jogos[i].valorCaixa, sizeof(jogos[i].valorCaixa), stdin);
            printf("Digite o valor solto do jogo: \n");
            fgets(jogos[i].valorSolto, sizeof(jogos[i].valorSolto), stdin);
            printf("Digite um link para compra do jogo: \n");
            fgets(jogos[i].linkCompra, sizeof(jogos[i].linkCompra), stdin);
            printf("Digite um link para um emulador para o jogo: \n");
            fgets(jogos[i].linkEmulador, sizeof(jogos[i].linkEmulador), stdin);
            printf("Digite um codigo sequencial de identificacao com ate 10 digitos: \n");
            fgets(jogos[i].id, sizeof(jogos[i].id), stdin);
            return;
        }
    }
}

void Consulta(Game* jogos)
{
    char pesquisa[100];
    int i = 0;
    printf("Digite a palavra chave a ser pesquisada:\n");
    printf("Nome // Plataforma // Fabricante // Ano de Lancamento // Raridade // id\n");
    fflush(stdin);
    fgets(pesquisa, sizeof(pesquisa), stdin);
    pesquisa[strcspn(pesquisa, "\n")] = 0; // Remove newline character
    for(i = 0; i<1000; i++)
    {
        if(strcmp(pesquisa, jogos[i].nome)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n Codigo sequencial de identificacao: %s \n ", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador, jogos[i].id);
            printf("--------------------------------------------------------------------------------\n");
            return;
        } else if(strcmp(pesquisa, jogos[i].plataforma)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n Codigo sequencial de identificacao: %s \n ", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador, jogos[i].id);
            printf("--------------------------------------------------------------------------------\n");
            return;
        } else if(strcmp(pesquisa, jogos[i].fabricante)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n Codigo sequencial de identificacao: %s \n ", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador, jogos[i].id);
            printf("--------------------------------------------------------------------------------\n");
            return;
        } else if(strcmp(pesquisa, jogos[i].lancamento)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n Codigo sequencial de identificacao: %s \n ", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador, jogos[i].id);
            printf("--------------------------------------------------------------------------------\n");
            return;
        } else if(strcmp(pesquisa, jogos[i].raridade)==0)
        {
            printf("--------------------------------------------------------------------------------\n");
            printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador);
            printf("--------------------------------------------------------------------------------\n");
            return;
        } else
        {
            printf("Nao ha jogos com essa palavra chave\n");
            return;
        }
    }
}

void Visualizador(Game* jogos)
{
    int i = 0, limite;
    printf("Visualizar ate qual numero?(ultimo: 999)");
    scanf("%d", &limite);
    for(i=0; i<=limite; i++)
    {
        printf("-------------------------------------------------------------------------------------\n");
        printf("%d - Nome: %s - Plataforma: %s - Fabricante: %s \n Lancamento: %s - Raridade: %s \n Valor Lacrado: %s \n Valor na Caixa: %s \n Valor Usado: %s \n Link de compra: %s \n Link de emulador: %s \n Codigo sequencial de identificacao: %s \n ", i, jogos[i].nome, jogos[i].plataforma, jogos[i].fabricante, jogos[i].lancamento,jogos[i].raridade, jogos[i].valorLacrado, jogos[i].valorCaixa, jogos[i].valorSolto, jogos[i].linkCompra, jogos[i].linkEmulador, jogos[i].id);
        printf("-------------------------------------------------------------------------------------\n");
    }
}

void ApagarItens(Game* jogos)
{
    char pesquisa[100];
    int i = 0;
    printf("Digite o nome do jogo a ser deletado:\n");
    fflush(stdin);
    fgets(pesquisa, sizeof(pesquisa), stdin);
    pesquisa[strcspn(pesquisa, "\n")] = 0; // Remove newline character
    for(i = 0; i<1000; i++)
    {
        if(strcmp(pesquisa, jogos[i].nome)==0)
        {
            strcpy(jogos[i].nome, "00000000000");
            strcpy(jogos[i].plataforma, "00000000000");
            strcpy(jogos[i].fabricante, "00000000000");
            strcpy(jogos[i].lancamento, "00000");
            strcpy(jogos[i].raridade, "00000000000");
            strcpy(jogos[i].valorLacrado, "00000000000");
            strcpy(jogos[i].valorCaixa, "00000000000");
            strcpy(jogos[i].valorSolto, "00000000000");
            strcpy(jogos[i].linkCompra, "00000000000");
            strcpy(jogos[i].linkEmulador, "00000000000");
            strcpy(jogos[i].id, "0000000000");
            return;
        }else
        {
            printf("Nome Invalido\n");
            return;
        }
    }
}

int main()
{
    int i=0;
    Game* jogos;
    jogos = (Game*)malloc(1000*sizeof(Game));
    DezIniciais(jogos);

    int seletor;
    do
    {
        printf("__________Simple RetroGaming Database__________\n\n");
        printf("1 - Cadastro de Itens\n");
        printf("2 - Consulta de Itens\n");
        printf("3 - Visualizar Itens Cadastrados\n");
        printf("4 - Apagar Itens Cadastrados\n");
        printf("0 - Sair\n\n");
        scanf("%d", &seletor);
        if(seletor == 1)
        {
            printf("Cadastrar novos itens: \n");
            Cadastro(jogos);
        } else if(seletor == 2)
        {
            printf("Consultar itens: \n");
            Consulta(jogos);
        } else if(seletor == 3)
        {
            printf("Visualizar todos os itens: \n");
            Visualizador(jogos);
        } else if(seletor == 4)
        {
            printf("Apagar itens: \n");
            ApagarItens(jogos);
        } else if(seletor == 0)
        {
            printf("Programa encerrado.\n");
            return 0;
        } else
        {
           printf("Selecao invalida.\n");
        }
    }while(seletor < 5);

    for(i = 0; i<1000; i++)
    {
        strcpy(jogos[i].nome, "00000000000");
        strcpy(jogos[i].plataforma, "00000000000");
        strcpy(jogos[i].fabricante, "00000000000");
        strcpy(jogos[i].lancamento, "00000");
        strcpy(jogos[i].raridade, "00000000000");
        strcpy(jogos[i].valorLacrado, "00000000000");
        strcpy(jogos[i].valorCaixa, "00000000000");
        strcpy(jogos[i].valorSolto, "00000000000");
        strcpy(jogos[i].linkCompra, "00000000000");
        strcpy(jogos[i].linkEmulador, "00000000000");
    }

    free(jogos);
    jogos = NULL;

    return 0;
}