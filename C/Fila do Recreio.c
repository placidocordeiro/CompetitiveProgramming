#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int nota;
	bool traded;
	struct node* next;
} Node;

typedef struct
{
	Node* primeiro;
} Queue;

int vazia(Queue* fila)
{
	return fila->primeiro == NULL;
}

Queue* create_queue()
{
	Queue* fila = (Queue*) malloc(sizeof(Queue));
	fila->primeiro = NULL;
	return fila;
}

void enqueue(Queue* fila, int nota)
{
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->traded = false;
	new_node->nota = nota;	
	new_node->next = fila->primeiro;
	fila->primeiro = new_node;
}

void reordenar(Node* primeiro)
{
	if(primeiro == NULL) return;
	
	Node* tail = primeiro;
	int aux; bool aux_t;
	
	while(tail != NULL)
	{
		if(primeiro->nota > tail->nota)
		{
			primeiro->traded = true;
			tail->traded = true;
			
			aux = tail->nota;
			aux_t = tail->traded;
			
			tail->nota = primeiro->nota;
			tail->traded = primeiro->traded;
			
			primeiro->nota = aux;
			primeiro->traded = aux_t;
		}
		tail = tail->next;
	}
	reordenar(primeiro->next);
}

int nottraded(Node* copy, Node* fila)
{
	int not_tradeds = 0;
	while(fila != NULL)
	{
		if(fila->nota == copy->nota)
		{
			not_tradeds++;
		}
		fila = fila->next;
		copy = copy->next;
	}
	return not_tradeds;
}

Queue* copiar(Node* fila)
{
	Queue* new_queue = (Queue*) malloc(sizeof(Queue));
	new_queue-> primeiro = NULL;
	while(fila != NULL)
	{
		enqueue(new_queue, fila->nota);
		fila = fila->next;
	}
	return new_queue;
}

void main()
{
	int testes;
	scanf("%d", &testes);
	
	while(testes)
	{
	    Queue* fila = create_queue();
		int estudantes, nota;
		scanf("%d", &estudantes);
		
		while(estudantes)
		{
			scanf("%d", &nota);
			enqueue(fila, nota);
			estudantes--;
		}
	    
	    Queue* copy = copiar(fila->primeiro);
	    reordenar(copy->primeiro);
	    printf("%d\n", nottraded(copy->primeiro, fila->primeiro));
		testes--;
	}
}