#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

struct Node 
{
    int val;
    struct Node* esquerda;
    struct Node* direita;
};

struct Node* createNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

struct Node* montar_arvore(char* s, int* index) 
{
    if (s[*index] == '(') 
    {
        (*index)++;
        if (s[*index] == ')') 
        {
            (*index)++;
            return NULL;
        }

        int num = 0;
        int sign = 1;
        if (s[*index] == '-') 
        {
            sign = -1;
            (*index)++;
        }
        while (s[*index] >= '0' && s[*index] <= '9') 
        {
            num = num * 10 + (s[*index] - '0');
            (*index)++;
        }
        num *= sign;

        struct Node* node = createNode(num);

        node->esquerda = montar_arvore(s, index);
        node->direita = montar_arvore(s, index);

        (*index)++;
        return node;
    }
    return NULL;
}

bool arvore_completa(struct Node* raiz) 
{
    if (raiz == NULL) 
    {
        return true;
    }

    bool tem_no_incompleto = false;
    bool completo = true;

    struct Node** queue = (struct Node**) malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = raiz;

    while (front < rear) 
    {
        struct Node* node = queue[front++];

        if (node == NULL) 
        {
            tem_no_incompleto = true;
        } else 
        {
            if (tem_no_incompleto) 
            {
                completo = false;
                break;
            }

            queue[rear++] = node->esquerda;
            queue[rear++] = node->direita;
        }
    }

    free(queue);

    return completo;
}


void printar_no_com_um_filho(struct Node* raiz) 
{
    if (raiz == NULL) 
    {
        return;
    }

    printar_no_com_um_filho(raiz->esquerda);
    if ((raiz->esquerda && !raiz->direita) || (!raiz->esquerda && raiz->direita)) 
    {
        printf("%d ", raiz->val);
    }

    printar_no_com_um_filho(raiz->direita);
}

int countNodes(struct Node* raiz) 
{
    if (raiz == NULL) 
    {
        return 0;
    }
    return 1 + countNodes(raiz->esquerda) + countNodes(raiz->direita);
}

void main() 
{
    char s[1000];
    scanf("%s", s);
    int index = 0;
    struct Node* raiz = montar_arvore(s, &index);

    if (arvore_completa(raiz)== true)
    {
        printf("completa\ntotal de nos: %d", countNodes(raiz));
    }
    else
    {
        printf("nao completa\nnos com um filho: ");
        printar_no_com_um_filho(raiz);
    }
}