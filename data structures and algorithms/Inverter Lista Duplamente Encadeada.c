#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *ant;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    NO* cauda;
    int tamanho;
} LISTA;

void inicializar(LISTA *l)
{
    l->cabeca = NULL;
    l->cauda = NULL;
    l->tamanho = 0;
}

NO* criarNo(ITEM item,  NO *ant, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->ant = ant;
    pNovo->prox = prox;
    return pNovo;
}

int tamanho(LISTA *l)
{
    return l->tamanho;
}

bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}

bool inserir(ITEM item, LISTA *l){
    NO* pNovo = criarNo(item, NULL, l->cabeca);
    l->tamanho++;

    if (l->cabeca) 
       l->cabeca->ant = pNovo;  
    
    l->cabeca = pNovo;
    
    if (l->cauda == NULL) 
       l->cauda = pNovo;

    return true;
}

void exibirListaCabecaCauda(LISTA *l)
{
    NO* p = l->cabeca;
    while (p)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}

void exibirListaCaudaCabeca(LISTA *l)
{
    NO* p = l->cauda;
    while (p)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->ant;
    }
}

void imprimirLista(LISTA *l, bool crescente)
{
    printf("Tamanho = %d\n", tamanho(l));
    if (crescente)
        exibirListaCabecaCauda(l);
    else
        exibirListaCaudaCabeca(l);
    printf("\n");
}

void destruir(LISTA *l)
{
    NO* atual = l->cabeca;
    while (atual) {
        NO* prox = atual->prox; 
        free(atual);            
        atual = prox;
    }
    l->cabeca = NULL; 
    l->cauda = NULL; 
}

void inverter(LISTA *l)
{
    NO* head = l->cabeca;
    NO* rear = l->cauda;
    NO* aux;
    
    while(l->cauda != NULL)
    {
        aux = l->cauda->prox;
        l->cauda->prox = l->cauda->ant;
        l->cauda->ant = aux;
        l->cauda = l->cauda->prox;
    }
        l->cauda = head;
        l->cabeca = rear;
}

void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserir(item, l);
    }
}

int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l, true);   
  
  inverter(&l);
  imprimirLista(&l, true);  
  imprimirLista(&l, false); 

  destruir(&l);
  return 0;
}
