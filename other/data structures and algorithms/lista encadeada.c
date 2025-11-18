#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *next;
}No;

void printar_lista(No *no)
{
    printf("\n\tLista: ");

    while (no)
    {
        printf("%d -> ",no->valor);
        no = no->next;
    }
    printf("NULL\n\n");
}

void inserir_no_inicio(No **lista, int num)
{
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
        new->next = *lista;
        *lista = new;
    } else printf("Erro ao alocar memória!!!\n");
}

void inserir_no_final(No **lista, int num)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
        new->next = NULL;

        // é a raiz?
        if (*lista == NULL)
        {
            *lista = new;
        }
        else 
        {
            aux = *lista;
            while (aux->next)
            {
                aux = aux->next;
            }
            aux->next = new;
        }
    } else printf("Erro ao alocar memória!!!\n");
}

void inserir_no_meio(No **lista, int num, int anterior)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;
    } else printf("Erro ao alocar memória!!!\n");

    // é a raiz?
    if(*lista == NULL)
    {
        *lista = new;
        new->next = NULL;
    }
    else
    {
        aux = *lista;

        while (aux->valor != anterior && aux->next)
        {
            aux = aux->next;
        }
        new->next = aux->next;
        aux->next = new;
    }
}

void inserir_ordenado(No **lista, int num)
{
    No *aux;
    No *new = malloc(sizeof(No));

    if (new)
    {
        new->valor = num;

        // a lista está vazia?
        if (*lista == NULL)
        {
            *lista = new;
        }
        else if (new->valor < (*lista)->valor)
        {
            new->next = *lista;
            *lista = new;
        }
        else
        {
            aux = *lista;

            while (aux->next && new->valor > aux->next->valor)
            {
                aux = aux->next;
            }

            new->next = aux->next;
            aux->next = new;
        }

    } else printf("Erro ao alocar memória!!!\n");
}

No *remover_no(No **lista, int num)
{
    No *aux;
    No *remover = NULL;

    if (*lista)
    {
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->next;
        }
        else
        {
            aux = *lista;

            while (aux->next && aux->next->valor != num)
            {
                aux = aux->next;
            }
            if (aux->next)
            {
                remover = aux->next;
                aux->next = remover->next;
            }
        }
    }

    return remover;
}

No *buscar(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->next->valor != num)
    {
        aux = aux->next;
    }

    if (aux) no = aux->next;

    return no;
}

void main()
{
    int opcao, valor, anterior;
    No *elemento, *lista = NULL;

    do 
    {
        printf("[0] SAIR\n[1] INSERIR NO INICIO\n[2] INSERIR NO FIM\n[3] INSERIR NO MEIO\n[4] INSERIR ORDENADO\n[5] REMOVER ELEMENTO\n[6] IMPRIMIR\n[7] BUSCAR ELEMENTO\n");
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
            elemento = remover_no(&lista,valor);
            if (elemento)
            {
                printf("\nElemento a ser removido: %d\n",elemento->valor);
                free(elemento);
            }
            break;
        case 6:
            system("clear");
            printar_lista(lista);
            break;
        case 7:
            system("clear");
            printf("Digite o valor que você quer buscar: ");
            scanf("%d",&valor);
            elemento = buscar(&lista,valor);
            if (elemento) printf("Elemento encontrado: %d\n",elemento->valor);
            else printf("Elemento nao encontrado!!!\n");
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