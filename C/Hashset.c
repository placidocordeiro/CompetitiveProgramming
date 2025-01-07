#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elemento
{
    int num;
    struct elemento* next;
} elemento;

typedef struct
{
    int tam[1000000];
    elemento* table[1000000];
} hash;

hash* criar_hash() 
{
    hash *new_hash = (hash*) malloc(sizeof(hash));

    for (int i = 0; i < 100; i++) 
    {
        new_hash->table[i] = NULL;
        new_hash->tam[i] = 0;
    }

    return new_hash;
}

int soma_tam(hash* ht, int TAM)
{
    int t = 0;
    for(int i = 0; i < TAM; i++)
    {
        t += ht->tam[i];
    }
    return t;
}

hash* resize(hash* ht, int* TAM)
{
    int NEW_TAM = (2 * *TAM) - 1;

    hash* hash_table = criar_hash();

    for(int i = 0; i < *TAM; i++)
    {
        elemento* aux = ht->table[i];

        while(aux != NULL)
        {
           ADD(hash_table, &NEW_TAM, 0, aux->num); 
           aux = aux->next;
        }
    }

    *TAM = NEW_TAM; 

    return hash_table;
}

void ADD(hash* ht, int* TAM, int normal, int aux_num)
{
    int num, h, exist = 0, comp = 0;

    if(normal)
    {
        scanf(" %d", &num); 
    } 
    else num = aux_num;
    h = num % *TAM;
    

    int comp_na_linha = 0;

    for(int i = 0; i < *TAM; i++)
    {
        elemento* aux = ht->table[i];
        {
            while(aux != NULL)
            {
                comp++;
                if(aux->num == num)
                {
                    exist = 1; break;
                }
                aux = aux->next;
            }
        }
        if(i == h) comp_na_linha = comp;
        if(exist) break;

        comp = 0;
    }

    if(!exist){
        elemento* new_elemento = (elemento*) malloc(sizeof(elemento));
        new_elemento->num = num;
        new_elemento->next = ht->table[h];

        ht->table[h] = new_elemento;
        ht->tam[h] += 1; 
    }

    if(normal)
    {
        printf("%d %d\n", exist ? 0 : 1, exist ? comp : comp_na_linha);
    }
}

void DEL(hash* ht, int TAM)
{
    int num, h, exist = 0, comp = 0;
    scanf(" %d", &num);
    
    h = num % TAM;

    elemento* aux = ht->table[h],* aux2 = NULL;
    
    while(aux != NULL)
    {
        comp++;

        if(aux->num == num)
        {
            exist = 1;

            if(aux2 == NULL) ht->table[h] = aux->next; else aux2->next = aux->next;

            ht->tam[h] -= 1;

            break;
        }
        
        aux2 = aux;
        aux = aux->next;
    }
    
    printf("%d %d\n", exist ? 1 : 0, comp);
}

void HAS(hash* ht, int TAM)
{
    int num, h, comp = 0, exist = 0;
    scanf(" %d", &num);

    h = num % TAM; 

    elemento* aux = ht->table[h];
    {
        while(aux != NULL)
        {
            comp++;
            if(aux->num == num)
            {
                exist = 1; break;
            }
            aux = aux->next;
        }
    }

    printf("%d %d\n", exist ? 1 : 0, comp);
}

void PRT(hash* ht, int TAM)
{
    int maior = 0;
    for(int i = 0; i < TAM; i++)
    {
        if(ht->tam[i] > maior)
        {
            maior = ht->tam[i];
        }
    }

    printf("%d %d %d\n", TAM, soma_tam(ht, TAM), maior);
}

void main() 
{
    char command[4]; int num_command = 0, TAM = 7;
    hash* hash_table = criar_hash();

    while(scanf(" %s", command) != EOF)
    {
        printf("%d ", num_command); num_command++;

        switch(command[0])
        {
            case 'A': 
            {
                ADD(hash_table, &TAM, 1, 0); 
                double ocupacao = soma_tam(hash_table, TAM)/ (double) TAM;
                if(ocupacao >= 0.75) hash_table = resize(hash_table, &TAM);
                break;
            }
            case 'D': DEL(hash_table, TAM);        break;
            case 'H': HAS(hash_table, TAM);        break;
            case 'P': PRT(hash_table, TAM);        break;
        }
    }
}