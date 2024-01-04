
#include <stdio.h>
#include <stdlib.h>

struct sLL
{
    int value;
    struct sLL *link;
};

typedef struct sLL Node;

Node *head = NULL;

void reverseList()
{
    printf("List being reversed...\n");
    Node *prev = NULL, *curr, *next;
    curr = next = head;
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node *createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Input data: ");
    scanf("%d", &newNode->value);
    newNode->link = NULL;
    return newNode;
}

void insertFirst()
{
    printf("Insertion at the beginning.\n");
    if (head == NULL)
        head = createNode();
    else
    {
        Node *newNode = createNode();
        newNode->link = head;
        head = newNode;
    }
}

void insertLast()
{
    printf("Insertion at the end.\n");
    if (head == NULL)
        insertFirst();
    else
    {
        Node *newNode = createNode(), *tmp = head;
        while (tmp->link != NULL)
            tmp = tmp->link;
        tmp->link = newNode;
    }
}

void insertPosition()
{
    int pos;
    Node *tmp = head, *pre, *newNode;
    printf("Input position: ");
    scanf("%d", &pos);

    printf("Element to be inserted at position %d.\n", pos);
    if (pos == 0)
        insertFirst();
    else
    {
        newNode = createNode();
        for (int i = 1; i < pos; i++)
            tmp = tmp->link;
        pre = tmp->link;
        tmp->link = newNode;
        tmp->link->link = pre;
    }
}

void countNodesDisplay()
{
    int ctr = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        ctr++;
        temp = temp->link;
    }
    printf("No. of nodes in the list: %d\n", ctr);
}

void displayNodes()
{
    Node *temp = head;
    printf("head");
    while (temp != NULL)
    {
        printf("-->%d", temp->value);
        temp = temp->link;
    }
    printf("-->null\n");
}

int main()
{
    insertFirst();
    insertLast();
    insertFirst();
    insertLast();
    insertPosition();
    displayNodes();
    reverseList();
    displayNodes();
    return 0;
}