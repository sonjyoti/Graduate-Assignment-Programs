
#include <stdio.h>
#include <stdlib.h>

struct cSll
{
    int val;
    struct cSll *next;
};

typedef struct cSll Node;

Node *head = NULL, *tail = NULL;

Node *getNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Input data: ");
    scanf("%d", &newNode->val);
    newNode->next = NULL;
    return newNode;
}

void displayNodes()
{
    Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("head-->");
    do
    {
        printf("%d-->", temp->val);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

void countNodes()
{
    if (head == NULL)
    {
        printf("No. of nodes in the list: 0\n");
        return;
    }
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("No. of nodes in the list: %d\n", count);
}

void insertFirst()
{
    printf("Inserting at the beginning.\n");
    Node *newNode = getNode();
    newNode->next = newNode;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
}

void insertLast()
{
    printf("Inserting at the end.\n");
    if (head == NULL)
    {
        insertFirst();
        return;
    }
    Node *newNode = getNode();
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void insertPosition()
{
    printf("Inserting at a given position.\n");
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
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFirst()
{
    printf("Deleing the first node.\n");
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    if (tail == head)
    {
        head = NULL;
        tail = head;
        return;
    }
    head = head->next;
    tail->next = head;
}

void deleteLast()
{
    printf("Deleting the end node.\n");
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    if (tail == head)
    {
        head = NULL;
        tail = head;
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
        temp = temp->next;
    temp->next = head;
    tail = temp;
}

void deletePosition()
{
    printf("Deleting a node from a given position.\n");
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    int pos;
    printf("Input position: ");
    scanf("%d", &pos);
    if (pos == 0)
    {
        deleteFirst();
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
        deleteLast();
        return;
    }
    temp->next = temp->next->next;
}

int main()
{
    insertLast();
    displayNodes();
    countNodes();
    deleteFirst();
    displayNodes();
    countNodes();
    insertFirst();
    displayNodes();
    countNodes();
    insertLast();
    displayNodes();
    countNodes();
    insertFirst();
    displayNodes();
    countNodes();
    insertPosition();
    displayNodes();
    countNodes();
    insertLast();
    displayNodes();
    countNodes();
    deleteFirst();
    displayNodes();
    countNodes();
    deleteLast();
    displayNodes();
    countNodes();
    deletePosition();
    displayNodes();
    countNodes();
    return 0;
}