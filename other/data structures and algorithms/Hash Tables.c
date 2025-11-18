#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int key;
    struct element* next;
} element;

typedef struct
{
    element* table[100];
} hash;

hash* create_hash() 
{
    hash *new_hash = (hash*) malloc(sizeof(hash));

    for (int i = 0; i < 100; i++) 
    {
        new_hash->table[i] = NULL;
    }

    return new_hash;
}

void put(hash* ht, int key, int TAM)
{
    int h = key % TAM;

    element* new_element = (element*) malloc(sizeof(element));
    new_element->key = key;
    new_element->next = NULL;

    if(ht->table[h] == NULL)
    {
        ht->table[h] = new_element;
    }
    else
    {
        element* copy = ht->table[h];
        while(copy->next != NULL){
            copy = copy->next;
        }
        copy->next = new_element;
    }
}

void print(hash* ht, int TAM)
{
    for(int i = 0; i < TAM; i++){
        element* item = ht->table[i];

        printf("%d -> ", i);

        while(item != NULL)
        {
            printf("%d -> ",item->key);
            item = item->next;
        }

        printf("\\\n");
    }
}

void main()
{
    int testes;
    scanf("%d", &testes);

    while(testes)
    {
        int TAM, chaves, chave;
        scanf("%d %d", &TAM, &chaves);

        hash* hash_table = create_hash();

        while(chaves)
        {
            scanf("%d", &chave);
            put(hash_table, chave, TAM);
            chaves--;
        }

        print(hash_table, TAM);
        printf("\n");
        
        testes--;
    }
}