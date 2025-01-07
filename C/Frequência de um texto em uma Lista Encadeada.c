#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    char letra;
    int frequencia;
    struct node *next;
};

void printar(struct node *lista)
{
    while(lista!=NULL)
    {printf("%c %d\n", lista->letra, lista->frequencia);
    lista=lista->next;}
    return;
}
void swap(struct node *i1,struct node *i2)
{
    char aux1=i1->letra;
    i1->letra=i2->letra;
    i2->letra=aux1;
    int aux2=i1->frequencia;
    i1->frequencia=i2->frequencia;
    i2->frequencia=aux2;
    return;
}
struct node *bubblesort(struct node *lista)
{
    struct node *anterior=lista;
    while(anterior->next!=NULL)
    {
        struct node *proximo=anterior->next;
        while(proximo!=NULL)
        {
            if(anterior->letra < proximo->letra)
            {

                swap(anterior,proximo);}
            proximo=proximo->next;
        }
        anterior=anterior->next;
    }
    return lista;
}
struct node *addnode(struct node *lista,char caracter,int cont)
{
    struct node *new=malloc(sizeof(struct node));
    new->letra=caracter;
    new->frequencia=cont;
    new->next=lista;
    return new;
}
bool tem(char caracter,struct node *lista)
{
    while(lista!=NULL)
    {
        if(lista->letra==caracter)
        {return true;}
        lista=lista->next;
    }
    return false;
}
struct node *calcular_frequencia(int t,char frase[],struct node *lista)
{
    int i=0;
    while(frase[i]!='\0')
    {
        int cont=0;
        int j=0;
        char ref=frase[i];

        while(frase[j]!='\0')
        {
            if(frase[j]==ref)
            {
                cont++;
            }
            if(j==t-1)
            {
                if(tem(ref,lista)==false)
                {
                    lista=addnode(lista,ref,cont);
                }
            }
            j++;
        }
        i++;
    }
    return lista;
}
int main() 
{
    char frase[1000];
    scanf("%[^\n]", frase);
    int tam=strlen(frase);
    struct node *lista=NULL;
    lista=calcular_frequencia(tam,frase,lista);
    lista=bubblesort(lista);
    printar(lista);
	return 0;
}