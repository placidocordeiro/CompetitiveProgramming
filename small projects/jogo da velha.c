#include <stdio.h>
#include <stdlib.h>

void printar(char jogo[][3])
{
    for (int i=0;i<3;i++)
    { 
        for (int j=0;j<3;j++)
        {
            printf("|%c",jogo[i][j]);
        }
        printf("|\n");
    }
}

void jogada(char matriz[][3],char *turn)
{
    int linha,coluna;
    scanf("%d %d",&linha,&coluna);
    

    if (matriz[linha][coluna] != '_')
    {
        printf("esta casa esta ocupada, escolha outra!!!\n");
        jogada(matriz,turn);
    }
    else 
    {
        matriz[linha][coluna] = *turn;
        if (*turn == 'x') *turn = 'o';
        else *turn = 'x';
    }
    return;
}

void restart(char matriz[][3])
{
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            matriz[i][j]='_';
        }
    }
}


void verificar(char matriz[][3], int *p)
{
    char reset;
    if (matriz[0][0] != '_' && matriz[0][1] != '_' && matriz[0][2] != '_')
        {
            if (matriz[1][0] != '_' && matriz[1][1] != '_' && matriz[1][2] != '_')
            {
                if (matriz[2][0] != '_' && matriz[2][1] != '_' && matriz[2][2] != '_')
                {
                    printf("\nO jogo deu velha!!!\nNinguem venceu...\n");
                    printf("\nVoce deseja jogar novamente? (Y/N)\n\n");
                    scanf(" %c",&reset);
                    if (reset == 'Y' || reset == 'y') 
                    {
                        restart(matriz);
                        system("clear");
                        printar(matriz);
                        reset = ' ';
                    }
                    else if (reset == 'N' || reset == 'n')
                    {
                        system("clear");
                        printf("Encerrando...\n\nMuito obrigado por jogar!!!\n");
                        *p = 0;
                        return;
                    }
                }
            }
        }

    for (int i=0;i<3;i++)
    {
        if (matriz[i][0]==matriz[i][1] && matriz[i][1]==matriz[i][2] && matriz[i][0]!='_')
        {
            printf("\nVitoria do jogador %c!!!\n",matriz[i][0]);
            printf("\nVoce deseja jogar novamente? (Y/N)\n\n");
            scanf(" %c",&reset);
            if (reset == 'Y' || reset == 'y') 
            {
                restart(matriz);
                system("clear");
                printar(matriz);
                reset = ' ';
            }
            else if (reset == 'N' || reset == 'n')
            {
                system("clear");
                printf("Encerrando...\n\nMuito obrigado por jogar!!!\n");
                *p = 0;
                return;
            }
        }
    }
    for (int j=0;j<3;j++)
    {
        if (matriz[0][j]==matriz[1][j] && matriz[1][j]==matriz[2][j] && matriz[0][j]!='_')
        {
            printf("\nVitoria do jogador %c!!!\n",matriz[0][j]);
            printf("\nVoce deseja jogar novamente? (Y/N)\n\n");
            scanf(" %c",&reset);
            if (reset == 'Y' || reset == 'y') 
            {
                restart(matriz);
                system("clear");
                printar(matriz);
                reset = ' ';
            }
            else if (reset == 'N' || reset == 'n')
            {
                system("clear");
                printf("Encerrando...\n\nMuito obrigado por jogar!!!\n");
                *p = 0;
                return;
            }
        }
    }
    for (int i = 0;i<3;i++)
    {
        for (int j = 0;j<3;j++)
        {
            if (i==j && matriz[i][j]==matriz[i+1][j+1] && matriz[i+1][j+1]==matriz[i+2][j+2] && matriz[i][j]!='_')
            {
                printf("\nVitoria do jogador %c!!!\n",matriz[i][j]);
                printf("\nVoce deseja jogar novamente? (Y/N)\n\n");
                scanf(" %c",&reset);
                if (reset == 'Y' || reset == 'y') 
                {
                    restart(matriz);
                    system("clear");
                    printar(matriz);
                    reset = ' ';
                }
                else if (reset == 'N' || reset == 'n')
                {
                    system("clear");
                    printf("Encerrando...\n\nMuito obrigado por jogar!!!\n");
                    *p = 0;
                    return;
                }
            }
        }
    }
    if (matriz[0][2]==matriz[1][1] && matriz[1][1]==matriz[2][0] && matriz[1][1]!='_')
    {
        printf("\nVitoria do jogador %c!!!\n",matriz[1][1]);
        printf("\nVoce deseja jogar novamente? (Y/N)\n\n");
        scanf(" %c",&reset);
        if (reset == 'Y' || reset == 'y') 
        {
            restart(matriz);
            system("clear");
            printar(matriz);
            reset = ' ';
        }
        else if (reset == 'N' || reset == 'n')
        {
            system("clear");
            printf("Encerrando...\n\nMuito obrigado por jogar!!!\n");
            *p = 0;
            return;
        }
    }

    printf("\nDigite a coordenada da sua jogada!!!\n");
    return;
}

void main()
{
    char jogo[3][3] = {'_','_','_','_','_','_','_','_','_'};

    int ativo = 1;
    char last_turn = 'x';

    while (ativo==1)
    { 
        printf("\n\n");
        system("clear");
        printar(jogo);

        verificar(jogo,&ativo);
        if (ativo==0) break;
        jogada(jogo,&last_turn);
    }
}