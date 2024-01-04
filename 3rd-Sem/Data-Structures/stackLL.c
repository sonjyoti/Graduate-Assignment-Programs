
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
struct LL
{
    int val;
    struct LL *prev, *next;
};

typedef struct LL Node;
int top = 0;
Node *head = NULL;

Node *getNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    printf("Input data: ");
    scanf("%d", &newNode->val);
    return newNode;
}

void push()
{
    printf("Pushing an element...\n");
    if (top == MAX)
    {
        printf("Stack Overflow.\n");
        return;
    }
    Node *newNode = getNode();
    if (head == NULL)
    {
        head = newNode;
        top++;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void pop()
{
    printf("Popping from the stack..\n");
    if (top == 0)
    {
        printf("Stack underflow.\n");
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}

void traverse()
{
    Node *temp = head;
    printf("Elements in the stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push();
    traverse();
    push();
    traverse();
    push();
    traverse();
    pop();
    traverse();
    return 0;
}