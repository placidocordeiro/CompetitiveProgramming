#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    int num;
    struct node *next;
};

void swap(struct node *i1, struct node *i2)
{
    int aux=i1->num;
    i1->num=i2->num;
    i2->num=aux;
    return;
}
void printar(struct node *lista)
{
    while(lista != NULL)
    {
        printf("%d ", lista->num);
        lista=lista->next;
    }
    printf("\n");
    return;
}
void ordenar2(struct node *lista, int t, int count)
{
    if(count==t-1)
    {
        return;
    }
    else
    {
        int a=lista->num;
        int b=lista->next->num;
        if(a>b)
        {
            swap(lista, lista->next);
        }
    }
    lista=lista->next;
    ordenar2(lista, t, count+1);
}
void ordenar1(struct node *lista, int t, int count)
{
    if(count==t-2)
    {
        return;
    }
    else
    {
        ordenar2(lista, t, 0);
    }
    ordenar1(lista, t, count+1);
}
struct node *addnode(struct node *cabeca, int item)
{
    struct node *new= malloc(sizeof(struct node));
    new->num=item;
    new->next=cabeca;
    return new;
}
struct node *escanear(struct node *lista, int *count)
{
    int numero;
    if(scanf("%d", &numero)==EOF)
    {
        return lista;
    }
    else
    {
        *count=*count+1;
        lista=addnode(lista, numero);
    }
    escanear(lista, count);
}
int main() 
{
    struct node *lista = NULL;
    int countador =0;
    lista=escanear(lista, &countador);
    ordenar1(lista, countador, 0);
    printar(lista);
	return 0;
}