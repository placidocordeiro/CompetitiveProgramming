#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct binary_tree
{
    int num;
    struct binary_tree* right;
    struct binary_tree* left;
} binary_tree;

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right)
{
    binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));

    new_binary_tree->num= item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;

    return new_binary_tree;
}

binary_tree* add(binary_tree *bt, int item)
{
    if (bt == NULL) 
    {
        bt = create_binary_tree(item, NULL, NULL);
    } 
    else if (bt->num> item) 
    {
        bt->left = add(bt->left, item);
    } 
    else 
    {
        bt->right = add(bt->right, item);
    }

    return bt;
}

void printar_arvore(binary_tree* tree)
{
    if(tree != NULL)
    {
        printf(" ( %d ", tree->num); 
        printar_arvore(tree->left);
        printar_arvore(tree->right);
        printf(") ");
    }
    else
    {
        printf(" () ");
    }
}

void main ()
{
    binary_tree* tree = NULL;
    int num;

    while(scanf("%d", &num) != EOF)
    {
        tree = add(tree, num);
        
        printf("\n----\nAdicionando %d\n  ", num);
        printar_arvore(tree); 
    }
    printf("\n----");
} 