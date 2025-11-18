#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 20

struct node 
{
    int number;
    struct node *next;
};
void printar(struct node *lista)
{
    while(lista!=NULL)
    {printf("%d\n", lista->number);
    lista=lista->next;}
    return;
}
void swap(struct node *i1,struct node *i2)
{
    int aux=i1->number;
    i1->number=i2->number;
    i2->number=aux;
    return;
}
struct node *ordenar(struct node *lista)
{
    struct node *anterior=lista;
    while(anterior->next!=NULL)
    {
        struct node *adiante=anterior->next;
        while(adiante!=NULL)
        {
            if(anterior->number > adiante->number)
            {swap(anterior,adiante);}
            adiante=adiante->next;
        }
        anterior=anterior->next;
    }
    return lista;
}
struct node *addnode(struct node *lista, int item)
{
    struct node *new=malloc(sizeof(struct node));
    new->number=item;
    new->next=lista;
    return new;
}
bool tem(struct node *lista,int item)
{
    while(lista!=NULL)
    {
        if(lista->number==item)
        {return true;}
        lista=lista->next;
    }
    return false;
}
struct node *comparar(int array1[],int array2[],struct node *lista,int *cont)
{
    for(int i=0; i<TAM;i++)
    {
        for(int j=0;j<TAM;j++)
        {
            if(array1[i]==array2[j])
            {
                if(tem(lista,array1[i])==false)
                {*cont=*cont+1;
                    lista=addnode(lista,array1[i]);}
            }
        }
    }
    return lista;
}
void scan(int array[])
{
    for(int i=0; i<TAM;i++)
    {
        int numero;
        scanf("%d",&numero);
        array[i]=numero;
    }
    return;
}
int main()
{
    int array1[TAM], array2[TAM];
    scan(array1);
    scan(array2);
    struct node *lista=NULL;
    int cont=0;
    lista=comparar(array1,array2, lista,&cont);
    if(cont==0)
    {printf("VAZIO\n");
    return 0;}
    lista=ordenar(lista);
    printar(lista);
}