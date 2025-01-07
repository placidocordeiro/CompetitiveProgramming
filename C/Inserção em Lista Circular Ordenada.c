#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    int tamanho;
} LISTA;

void inicializar(LISTA *l)
{
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;  
    l->tamanho = 0;
}

NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
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

void exibirLista(LISTA *l)
{
    NO* p = l->cabeca->prox;
    while (p != l->cabeca)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}

void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

void destruir(LISTA *l)
{
    NO* atual = l->cabeca->prox;
    while (atual != l->cabeca) {  
        NO* prox = atual->prox; 
        free(atual);            
        atual = prox;
    }
    free(l->cabeca);  
    l->cabeca = NULL; 
}

bool inserirNaOrdem(ITEM item, LISTA *l)
{
    NO *node = criarNo(item, NULL);

    if (vazia(l)) {
        l->cabeca->prox = node;
        node->prox = l->cabeca;
        l->tamanho++;
        return true;
    }

    NO *current_node = l->cabeca->prox;
    NO *previous_node = l->cabeca;

    while (current_node != l->cabeca) {
        if (node->item.chave < current_node->item.chave) {
            node->prox = current_node;
            previous_node->prox = node;
            l->tamanho++;
            return true;
        } else if (node->item.chave == current_node->item.chave) {
            return false;
        }

        previous_node = current_node;
        current_node = current_node->prox;
    }

    previous_node->prox = node;
    node->prox = l->cabeca;
    l->tamanho++;
    return true;
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
        inserirNaOrdem(item, l);
    }
}

int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);
    
  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}