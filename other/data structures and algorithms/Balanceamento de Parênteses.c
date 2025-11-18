#define STRING 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char item;
	struct node* next;
} Node;

typedef struct
{
	Node* top;
} Stack;

void add(Stack* pilha, char a)
{
	Node* new_top = (Node*) malloc(sizeof(Node));
	new_top -> item  = a;
	new_top -> next = pilha -> top;
	pilha -> top = new_top;
}

void remover(Stack* pilha)
{
	Node* aux = pilha->top->next;
	free(pilha->top);
	pilha->top = aux;
}

char ver(Stack* pilha)
{
  return pilha->top->item;
}

void contador(int array[], char c)
{
    switch(c)
	{
        case('['): array[0]++; break;
        case(']'): array[1]++; break;
        case('('): array[2]++; break;
        case(')'): array[3]++; break;
    }
}

void main()
{
	Stack* pilha = (Stack*) malloc(sizeof(Stack));
	char string[255], top;
	int tamanho, num, ward = 0;
	
	pilha -> top = NULL;
	scanf("%d ", &num);
	
	while(num)
	{
        int cont[4] = {};
		
        fgets(string, 255, stdin);
		tamanho = strlen(string);
		
		for(int i = 0; i < tamanho; i++)
		{
			add(pilha, string[i]);
			top = ver(pilha); 
            contador(cont, top);
            if(cont[1] > cont[0] || cont[3] > cont[2])
			{
                ward = STRING;
                printf("No\n", string, cont[0], cont[1], cont[2], cont[3]);
                break;
            }
 	    }
		
        if(!ward)
		{
			if(cont[1] != cont[0] || cont[3] != cont[2])
			{
				printf("No\n");
			}
			else 
			{
				printf("Yes\n", cont[0], cont[1], cont[2], cont[3]);
			}
		} 
		
		while(pilha->top != NULL) remover(pilha);
		ward = 0;
		num--;
	}
}