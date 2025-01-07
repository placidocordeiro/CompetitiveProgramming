#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *next;
}No;

typedef struct 
{
    No *inicio;
    int size;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->size = 0;
}

void printar_lista(Lista lista)
{
    No *no = lista.inicio;
    printf("\n\tLista de tamanho %d: ",lista.size);

    while (no)
    {
        printf("%d -> ",no->valor);
        no = no->next;
    }
    printf("NULL\n\n");
}

void inserir_no_inicio(Lista *lista, int num)
{
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
        new->next = lista->inicio;
        lista->inicio = new;
        lista->size += 1;
    } else printf("Erro ao alocar memória!!!\n");
}

void inserir_no_final(Lista *lista, int num)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
        new->next = NULL;

        // é a raiz?
        if (lista->inicio == NULL)
        {
            lista->inicio = new;
        }
        else 
        {
            aux = lista->inicio;
            while (aux->next)
            {
                aux = aux->next;
            }
            aux->next = new;
        }
        lista->size += 1;
    } else printf("Erro ao alocar memória!!!\n");
}

void inserir_no_meio(Lista *lista, int num, int anterior)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
    } else printf("Erro ao alocar memória!!!\n");

    // é a raiz?
    if(lista->inicio == NULL)
    {
        lista->inicio = new;
        new->next = NULL;
    }
    else
    {
        aux = lista->inicio;

        while (aux->valor != anterior && aux->next)
        {
            aux = aux->next;
        }
        new->next = aux->next;
        aux->next = new;
    }
    lista->size += 1;
}

void inserir_ordenado(Lista *lista, int num)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;

        // a lista está vazia?
        if (lista->inicio == NULL)
        {
            new->next = NULL;
            lista->inicio = new;
        }
        else if (new->valor < lista->inicio->valor)
        {
            new->next = lista->inicio;
            lista->inicio = new;
        }
        else
        {
            aux = lista->inicio;

            while (aux->next && new->valor > aux->next->valor)
            {
                aux = aux->next;
            }

            new->next = aux->next;
            aux->next = new;
        }

    } else printf("Erro ao alocar memória!!!\n");
}

No *remover_no(Lista *lista, int num)
{
    No *aux;
    No *remover = NULL;

    if (lista->inicio)
    {
        if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->next;
            lista->size -= 1;
        }
        else
        {
            aux = lista->inicio;

            while (aux->next && aux->next->valor != num)
            {
                aux = aux->next;
            }
            if (aux->next)
            {
                remover = aux->next;
                aux->next = remover->next;
                lista->size -= 1;
            }
        }
    }

    return remover;
}

void main()
{
    int opcao, valor, anterior;
    Lista lista;
    No *remover;

    criar_lista(&lista);

    do 
    {
        printf("[0] SAIR\n[1] INSERIR NO INICIO\n[2] INSERIR NO FIM\n[3] INSERIR NO MEIO\n[4] INSERIR ORDENADO\n[5] REMOVER ELEMENTO\n[6] IMPRIMIR\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            system("clear");
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_no_inicio(&lista,valor);
            break;
        case 2:
            system("clear");
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_no_final(&lista,valor);
            break;
        case 3:
            system("clear");
            printf("Digite um valor: ");
            scanf("%d",&valor);
            printf("Após qual número você quer posicionar esse valor: ");
            scanf("%d",&anterior);
            inserir_no_meio(&lista,valor,anterior);
            break;
        case 4:
            system("clear");
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_ordenado(&lista,valor);
            break;
        case 5:
            system("clear");
            printf("Digite o valor que você quer remover: ");
            scanf("%d",&valor);
            remover = remover_no(&lista,valor);
            if (remover)
            {
                printf("Elemento a ser removido: %d\n",remover->valor);
                free(remover);
            }
            break;
        case 6:
            system("clear");
            printar_lista(lista);
            break;
        default:
            system("clear");
            if (opcao != 0)
            {
                printf("\nOPÇÃO INVÁLIDA!!!\n\n");
            }
        }
    } while(opcao != 0);
}