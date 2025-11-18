#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define espace printf(" ");

typedef struct node{
    int a;
    struct node* next;
}node;

typedef struct{
	int max;
	int current;
	int end;
}seq;


node* add(node* list, int x){
    node* new_node = (node*) malloc(sizeof(node));
    new_node -> a = x;
    new_node -> next = list;
    return new_node;
}

int main(){
    node *list, *aux;
    seq zeros;
    int index = 0, max_start, max_end, tam;
    char num[50];
    
    zeros.max = zeros.current = 0;
    list = NULL;
    
    scanf(" %s", num);
    while(strcmp(num, "0")){
        tam = strlen(num);
        
        for(int i = 0; i < tam; i++){
          list = add(list, num[i] - '0');
          index++;
        }
    
    while(list != NULL){
        if(zeros.current == 0) zeros.end = index;
        if(list -> a == 0){
        	zeros.current++;
        } else{
        	if(zeros.current >= zeros.max){
        		zeros.max = zeros.current;
        		max_start = index+1;
        		max_end = zeros.end;
        	}
        	zeros.current = 0;
        }
        
    	list = list -> next;
    	index--;
    }
    if(zeros.current >= zeros.max){
        		zeros.max = zeros.current;
        		max_start = index+1;
        		max_end = zeros.end;
    }
    
    printf("%d %d\n", max_start-1, max_end-1);
    
    scanf(" %s", num);
    index = 0;
    list = NULL;
    zeros.max = zeros.current = 0;
    }
    return 0;
}