#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct{
	int elements[MAX_SIZE];
	int current_size;
	int backs;
}stack;

stack* create_stack(){
	stack* new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = new_stack->backs = 0;
	return new_stack;
}

void enter(stack* pilha){
	pilha->elements[pilha->current_size++] = 1;
	if(pilha->backs > 0) pilha->backs--;
}

void back(stack* pilha){
	if(pilha->current_size > 1){
		pilha->current_size--;
		pilha->backs++;
	}
}

void forw(stack* pilha){
	if(pilha->backs){
		pilha->current_size++;
		pilha->backs--;
	}
}

int main(void){
	stack* pilha = create_stack();
	char action[10];
	
	while(scanf(" %s", action) != EOF && strcmp(action, "STOP")){
		if(!strcmp(action, "ENTER")){
			enter(pilha);
		}
		else if(!strcmp(action, "FORWARD")){
			forw(pilha);
		}
		else{
			back(pilha);
		}	
	}
	
	printf("BACK: %d\nFORWARD: %d\n", pilha->current_size-1, pilha->backs);
	return 0;
}
