#include <stdio.h>
#include <math.h>

void bandeira(unsigned long int num)
{
    num /= pow(10,15);
    if (num == 3) printf("AMERICAN EXPRESS\n");
    else if (num == 4) printf("VISA\n");
    else if (num == 5) printf("MASTERCARD\n");
    else printf("Sei lá po\n");
}

int soma_digitos(int numero, int retorno)
{
    do
    {
        retorno += numero%10;
        numero /= 10;
    } while (numero!=0);
    return retorno;
}

void validar(unsigned long int numero, int valor)
{
    unsigned long int aux = numero;
    while (aux != 0)
    {
        aux /= 10;
        valor += soma_digitos(2 * (aux%10),0);
        aux /= 10;
    }

    aux = numero;
    while (aux != 0)
    {
        valor += aux%10;
        aux /= 100;
    }

    if (valor%10 == 0)
    {
        printf("Esse número é válido!!!\n");
        bandeira(numero);
    }
    else
    {
        printf("Esse não número é válido!!!\n");
    }
}


void main()
{
    unsigned long int numero;
    printf("Digite o número do seu cartão de crédito: ");
    scanf("%lu",&numero);

    validar(numero,0);
}
