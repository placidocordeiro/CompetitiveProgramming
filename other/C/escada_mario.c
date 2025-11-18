#include <stdio.h>

void printar_escada(int n, int i)
{
    for (int j = 0; j<n-i; ++j)
    {
        printf(" ");
    }
    for (int k = 0; k<i; ++k)
    {
        printf("#");
    }

    printf(" ");

    for (int k = 0; k<i; ++k)
    {
        printf("#");
    }
    for (int j = 0; j<n-i; ++j)
    {
        printf(" ");
    }
    
    printf("\n");
    if (i == n) return;
    printar_escada(n,i+1);
}

void main()
{
    printf("Digite um valor de 1 a 8: ");
    int valor;
    scanf("%d",&valor);

    printar_escada(valor,1);
}