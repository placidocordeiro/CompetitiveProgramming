#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node* next;
} node;

typedef struct lista
{
    struct lista* next;
    node* items;
} Lista;

typedef struct
{
    Lista* top;
} stack;

stack* create_stack()
{
    stack* new_stack = (stack*) malloc(sizeof(stack));
    new_stack->top = NULL;
    return new_stack;
}

Lista* create_lista()
{
    Lista* new_lista = (Lista*) malloc(sizeof(Lista));
    new_lista->items = NULL;
    new_lista->next = NULL;
    return new_lista;
}

node* create_node()
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->next = NULL;
    return new_node;
}

node* add_node(node* lista, int item)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->next = lista;
    new_node->item = item;
    return new_node;
}

Lista* add_lista(stack* stack, Lista* lista)
{
    lista->next = stack->top;
    return lista;
}

void print(node* lista)
{
    if(lista->next->next == NULL)
    {
        printf("%d", lista->item);
    } 
    else 
    {
        print(lista->next);
        printf(" %d", lista->item);
    }
}

void pop(stack* pilha)
{
	Lista* aux = pilha->top->next;
	free(pilha->top);
	pilha->top = aux;
}

void main()
{
    stack* pilha = create_stack();
    char comando[5];

    while(scanf(" %s", comando) != EOF)
    {
        if(!strcmp(comando, "PUSH"))
        {
            Lista* lista = create_lista();
            node* elements = create_node();
            int num; char espaco;
            while(scanf("%d %c", &num, &espaco) != EOF && espaco != '\n')
            {
                elements = add_node(elements, num);
            }

            if(espaco == '\n') 
            {
                elements = add_node(elements, num); 
            }

            lista->items = elements;
            pilha->top = add_lista(pilha, lista); 
        } 
        else 
        {
            if(pilha->top != NULL)
            {
                print(pilha->top->items); printf("\n");
                pop(pilha);
            } else printf("EMPTY STACK\n");
        }
    }
}