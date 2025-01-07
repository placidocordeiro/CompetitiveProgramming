#define COMPLETAR_COM_ZEROS(a, c1, c2) while(*c1 > *c2) {insert_num(a, 0); (*c2) += 1;};
#define espace printf(" ");
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	char c;
	struct node* next;
}node;

node* add(node* list, int n){
	node* new_node = (node*) malloc(sizeof(node));	
	new_node-> c = n;
	new_node-> next = list;
	return new_node;
}

void insert_num(node* list, int a){
	node* new_last = (node*) malloc(sizeof(node));	
	node* last_item = list;

	while(last_item -> next != NULL){
		last_item = last_item -> next;
	} 

	new_last -> c = a; 
	new_last -> next = last_item -> next; 
	last_item -> next = new_last;
}


void print(node* list){
	printf("%d", list->c);
	if(list->next != NULL){
		espace print(list->next);
	}
}

void fix_num(node* list, int* aux){
    if(list -> next != NULL){
		fix_num(list -> next, aux);
	}

    list -> c += *aux;

    if(list -> c > 9){
        *aux = list -> c / 10;
        list -> c %= 10;
    } else *aux = 0;
}

node* remove_node(node *list){
	node* new_start = list -> next;
	free(list);

	return new_start;
}

int main(){
	node* num1;
	node* num2;
	char num, somado; 
	int cont1, cont2, n_aux = 0;
	node* soma;

	cont1 = cont2 = 0;
	num1 = NULL;
    num2 = NULL;
	soma = NULL;

	while(1){
		scanf(" %c", &num);
		if(num == '+') break;
		num1 = add(num1, (num - '0'));
		cont1++;
	};
	
	while(1){
		scanf(" %c", &num);	 
		if(num == '=') break;
		num2 = add(num2, (num - '0'));
		cont2++;
	};
	

	if(!cont1 || !cont2){
		if(cont1 || cont2){
			node* exist = (cont1) ? num1 : num2;
			while(exist != NULL){
				soma = add(soma, exist -> c);
				exist = exist -> next;
			}
			print(soma);
		}
		else printf("Lista vazia!");
	}else{	
		COMPLETAR_COM_ZEROS(num1, &cont2, &cont1);
		COMPLETAR_COM_ZEROS(num2, &cont1, &cont2);

		while(cont1){
			somado = num1 -> c + num2 -> c;
			soma = add(soma, somado);
			
			num1 = num1 -> next;
			num2 = num2 -> next;
			cont1--;
		}
		
		fix_num(soma, &n_aux); if(n_aux != 0) soma = add(soma, n_aux);
		while(soma -> c == 0) soma = remove_node(soma);

		print(soma);
	}
	return 0;
}