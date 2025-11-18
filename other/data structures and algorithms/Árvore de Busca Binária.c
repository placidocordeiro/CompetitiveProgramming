#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct binarytree
{
	int num;
	struct binarytree* direita;
	struct binarytree* esquerda;
}binarytree;

binarytree* create_node (int num)
{
	binarytree* tree = (binarytree*) malloc(sizeof(binarytree));
	tree->direita = tree->esquerda = NULL;
    tree->num = num;

    return tree;
}

int inverter_num(int num, int TAM)
{
    int new_num = 0;
    while(num > 9)
    {
        new_num = (num % 10) * pow(10, TAM-1);
        num /= 10;
        TAM--;
    }
    return new_num + num;
}

binarytree* construct (binarytree* tree, char* notacao, int* i)
{ 
    while(notacao[*i] == ')' || notacao[*i] == ' ') *i += 1;

	if(notacao[*i] == '(')
	{
		if(notacao[*i + 1] == ')')
		{
			tree = NULL; *i += 2;
		}
		else
		{
            *i += 1;
			int num = 0, TAM = 0;

            for(int factor = 1; notacao[*i] != '('; *i += 1, factor *= 10, TAM++)
            {
                num += (notacao[*i] - '0') * factor;
            }
            if(num > 9) num = inverter_num(num, TAM);
            while(num <= 9 && TAM-1){
            	num*=10;
            }
		    
		    tree = create_node(num);
		    tree->esquerda = construct(tree->esquerda, notacao, i);
		    tree->direita = construct(tree->direita, notacao, i);
		}
		return tree;
	}
}

void analisis(binarytree* tree, int* binary)
{
    binarytree* aux = tree->esquerda;

    if(aux != NULL && binary)
    {
        if(aux->num >= tree->num)
        {
            *binary = 0;
        }
        analisis(aux, binary);
    }

    aux = tree->direita;
    if(aux != NULL && binary)
    {
        if(aux->num < tree->num)
        {
            *binary = 0;
        }
        analisis(aux, binary);
    }
}

void main()
{
	char notacao[100]; int i = 0, binary = 1;
	scanf(" %[^\n]", notacao);
	
	binarytree* tree = NULL;
	
	tree = construct(tree, notacao, &i);
    
    analisis(tree, &binary);
    printf("%s", binary ? "VERDADEIRO" : "FALSO");
}