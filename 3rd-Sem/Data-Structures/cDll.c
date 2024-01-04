
#include <stdio.h>
#include <stdlib.h>

struct cDll
{
    int val;
    struct cDll *prev, *next;
};

typedef struct cDll Node;

Node *head = NULL, *tail = NULL;

Node *getNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Input data: ");
    scanf("%d", &newNode->val);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayNodes()
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    printf("Displaying the linked list.\n");
    Node *temp = head;
    printf("head-->");
    do
    {
        printf("%d-->", temp->val);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

void revDisplayNodes()
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("Reverse display of the list.\n");
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    printf("head-->");
    do
    {
        printf("%d-->", temp->val);
        temp = temp->prev;
    } while (temp != tail);
    printf("head\n");
}

void countNodes()
{
    Node *temp = head;
    int count = 0;
    if (head == NULL)
    {
        printf("No. of node(s): %d\n", count);
        return;
    }
    do
    {
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("No. of node(s): %d\n", count);
}

void insertFirst()
{
    printf("\nInserting a node at the first position.\n");
    Node *newNode = getNode();
    if (head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = head;
        return;
    }
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    head = newNode;
    tail->next = head;
}

void insertLast()
{
    printf("\nInserting a node at the last position.\n");
    Node *newNode = getNode();
    if (head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        tail = head;
        return;
    }
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    head->prev = tail;
}

void insertPosition()
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    printf("\nInserting a node a given position.\n");
    int pos;
    printf("Input position: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        insertFirst();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Index out of bound.\n");
            return;
        }
    }
    if (temp->next == head)
    {
        insertLast();
        return;
    }
    Node *newNode = getNode();
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFirst()
{
    printf("Deleting the first node.\n");
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    head = head->next;
    head->prev = tail;
    tail->next = head;
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    if (head == tail)
    {
        deleteFirst();
        return;
    }
    printf("Deleting the last node.\n");
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
}

void deletePosition()
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    int pos, i;
    printf("Input position: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        deleteFirst();
        return;
    }
    Node *temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Index out of bound.\n");
            return;
        }
    }
    if (temp->next->next == head)
    {
        deleteLast();
        return;
    }
}

int main()
{
    insertLast();
    displayNodes();
    insertPosition();
    displayNodes();
    insertFirst();
    displayNodes();
    revDisplayNodes();
    countNodes();
    insertFirst();
    displayNodes();
    insertFirst();
    displayNodes();
    insertLast();
    displayNodes();
    revDisplayNodes();
    insertPosition();
    displayNodes();
    revDisplayNodes();
    deleteFirst();
    displayNodes();
    revDisplayNodes();
    deleteLast();
    displayNodes();
    revDisplayNodes();
    deletePosition();
    displayNodes();
    revDisplayNodes();
    countNodes();
    return 0;
}
