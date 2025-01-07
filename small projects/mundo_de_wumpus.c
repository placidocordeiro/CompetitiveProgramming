#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define DERROTA 1
#define VITORIA 2


int checar_estado(char *local)
{
    if (*local == 'w' || *local == 'p') return DERROTA;
    else if (*local == 't') return VITORIA;
    else return NORMAL;
}

int esta_no_tabuleiro(char *local,char matriz[4][4])
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            if (&matriz[i][j] == local)
            {
                return 1;
            }
        }
    }

    return 0;
}

void inicializar_jogo(char matriz[4][4])
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            matriz[i][j] = '_';
        }
    }

    matriz[0][0] = 'c';
    return;
}

void posicionar(char elemento, char matriz[4][4])
{
    int linha = rand() % 4;
    int coluna = rand() % 4;

    if (matriz[linha][coluna] != '_')
    {
        posicionar(elemento,matriz);
    }
    else
    {
        matriz[linha][coluna] = elemento;
        return;
    }
}

void swap(char *elemento1, char *elemento2)
{
    char aux = *elemento1;

    *elemento1 = *elemento2;
    *elemento2 = aux;
    return;
}

void printar(char matriz[4][4])
{
    for (int i = 0; i<4; i++)
    {
        printf("|");
        for (int j = 0; j<4; j++)
        {
            printf("%c|",matriz[i][j]);
        }
        printf("\n");
    }
}

char *achar_player(char matriz[4][4])
{
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            if (matriz[i][j] == 'c') return &matriz[i][j];
        }
    }
}

void brisa_e_fedor(char *local)
{
    if (    *(local - 1) == 'w' || *(local + 1) == 'w' ||
            *(local - 4) == 'w' || *(local + 4) == 'w')
    {
        printf("\nvocê sente um fedor, o wumpus está por perto!!!\n");
    }

    if (    *(local - 1) == 'p' || *(local + 1) == 'p' ||
            *(local - 4) == 'p' || *(local + 4) == 'p')
    {
        printf("\nvocê sente uma brisa, há um poço por perto!!!\n");
    }
}

void main()
{
    srand(time(NULL));

    int opcao = -1;

    char tabuleiro[4][4];
    char wumpus = 'w';
    char tesouro = 't';
    char poco = 'p';
    char cacador = 'c';


    inicializar_jogo(tabuleiro);

    posicionar(wumpus,tabuleiro);
    posicionar(tesouro,tabuleiro);
    posicionar(poco,tabuleiro);
    posicionar(poco,tabuleiro);

    do
    {
        printf("\n\n");
        printar(tabuleiro);
        brisa_e_fedor(achar_player(tabuleiro));

        printf("\nPara onde deseja se mover?\n\n[1] ESQUERDA\n[2] DIREITA\n[3] CIMA\n[4] BAIXO\n\n[0] SAIR\n\n>>");
        scanf("%d",&opcao);

        switch (opcao)  
        {
        case 1:
            system("clear");
            if (esta_no_tabuleiro(achar_player(tabuleiro)-1,tabuleiro) == 0) 
            {
                printf("\nesta casa nao esta no tabuleiro, escolha outra!!!!\n");
                break;
            }
            if (checar_estado(achar_player(tabuleiro)-1) == DERROTA)
            {
                printf("\nvocê perdeu!!!!\n");
                exit(1);
            }
            else if (checar_estado(achar_player(tabuleiro)-1) == VITORIA)
            {
                printf("\nvocê venceu!!!!\n");
                exit(1);
            }
            else 
            {
                swap(achar_player(tabuleiro),achar_player(tabuleiro)-1);
                printf("\nnada aconteceu...\n");
            }
            break;

        case 2:
            system("clear");
            if (esta_no_tabuleiro(achar_player(tabuleiro)+1,tabuleiro) == 0) 
            {
                printf("\nesta casa nao esta no tabuleiro, escolha outra!!!!\n");
                break;
            }
            if (checar_estado(achar_player(tabuleiro)+1) == DERROTA)
            {
                printf("\nvocê perdeu!!!!\n");
                exit(1);
            }
            else if (checar_estado(achar_player(tabuleiro)+1) == VITORIA)
            {
                printf("\nvocê venceu!!!!\n");
                exit(1);
            }
            else 
            {
                swap(achar_player(tabuleiro),achar_player(tabuleiro)+1);
                printf("\nnada aconteceu...\n");
            }
            break;
        
        case 3:
            system("clear");
            if (esta_no_tabuleiro(achar_player(tabuleiro)-4,tabuleiro) == 0) 
            {
                printf("\nesta casa nao esta no tabuleiro, escolha outra!!!!\n");
                break;
            }
            if (checar_estado(achar_player(tabuleiro)-4) == DERROTA)
            {
                printf("\nvocê perdeu!!!!\n");
                exit(1);
            }
            else if (checar_estado(achar_player(tabuleiro)-4) == VITORIA)
            {
                printf("\nvocê venceu!!!!\n");
                exit(1);
            }
            else 
            {
                swap(achar_player(tabuleiro),achar_player(tabuleiro)-4);
                printf("\nnada aconteceu...\n");
            }
            break;

        case 4:
            system("clear");
            if (esta_no_tabuleiro(achar_player(tabuleiro)+4,tabuleiro) == 0) 
            {
                printf("\nesta casa nao esta no tabuleiro, escolha outra!!!!\n");
                break;
            }
            if (checar_estado(achar_player(tabuleiro)+4) == DERROTA)
            {
                printf("\nvocê perdeu!!!!\n");
                exit(1);
            }
            else if (checar_estado(achar_player(tabuleiro)+4) == VITORIA)
            {
                printf("\nvocê venceu!!!!\n");
                exit(1);
            }
            else 
            {
                swap(achar_player(tabuleiro),achar_player(tabuleiro)+4);
                printf("\nnada aconteceu...\n");
            }
            break;

        case 0:
            system("clear");
            printf("\nfechando jogo...\n");
            break;

        default:
            system("clear");
            printf("\nopção inválida, tente novamente!!!\n");
            break;
        }
    } while (opcao != 0);

}