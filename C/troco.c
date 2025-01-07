#include <stdio.h>

int moedas(double reais, int counter, double valor)
{
    while (valor+0.25 <= reais)
    {
        valor += 0.25;
        ++counter;
    }
    while (valor+0.1 <= reais)
    {
        valor += 0.1;
        ++counter;
    }
    while (valor+0.05 <= reais)
    {
        valor += 0.05;
        ++counter;
    }
    while (valor+0.01 <= reais)
    {
        valor += 0.01;
        ++counter;
    }
    
    return counter;
}

void main()
{
    double valor;
    printf("Digite o valor do troco em reais: ");
    scanf("%lf",&valor);

    printf("Você irá precisar de %d moedas\n",moedas(valor,0,0));
}