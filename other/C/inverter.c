#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} node;

node *empty_list()
{
    return NULL;
}

void add(node **head, int item)
{
    node *new_node = malloc(sizeof(node));
    if (new_node)
    {
        new_node->item = item;
        new_node->next = *head;
        *head = new_node;
    }
    return;
}

void result(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->item);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node *head = empty_list();
    int number;

    while (scanf("%d", &number) != EOF)
    {
        add(&head, number);
    }

    result(head);

    return 0;
}

