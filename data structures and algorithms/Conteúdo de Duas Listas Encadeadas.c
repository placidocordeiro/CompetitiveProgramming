#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next; 
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória no novo nó\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int isSubset(struct Node* listA, struct Node* listB) {
    struct Node* currentB = listB;

    while (currentB != NULL) {
        int found = 0;
        struct Node* currentA = listA;

        while (currentA != NULL) {
            if (currentA->data == currentB->data) {
                found = 1;
                break;
            }
            currentA = currentA->next;
        }

        if (!found) {
            return 0; 
        }

        currentB = currentB->next;
    }

    return 1; 
}

int main() {
    struct Node* listA = NULL;
    struct Node* listB = NULL;

    int n, m, data;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        
        scanf("%d", &data);
        insertAtEnd(&listA, data);
    }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        
        scanf("%d", &data);
        insertAtEnd(&listB, data);
    }

    printf("%d\n",isSubset(listA, listB));

    
    while (listA != NULL) {
        struct Node* temp = listA;
        listA = listA->next;
        free(temp);
    }

    while (listB != NULL) {
        struct Node* temp = listB;
        listB = listB->next;
        free(temp);
    }

    return 0;
}
