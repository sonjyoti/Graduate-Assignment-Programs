#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

typedef struct node Queue;

Queue *front = NULL;

void enqueue()
{
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    printf("Input data: ");
    scanf("%d", &newNode->data);
    if (front == NULL)
    {
        front = newNode;
        printf("Enqueue successful...");
        return;
    }
    Queue *dummy = front;
    while (dummy->next != NULL)
        dummy = dummy->next;
    dummy->next = newNode;
    printf("Enqueue successful...");
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Underflow...\n");
        return;
    }
    front = front->next;
    printf("Dequeue successful...");
}

void printQ()
{
    if (front == NULL)
    {
        printf("Empty queue...\n");
        return;
    }
    Queue *dummy = front;
    printf("front-->");
    while (dummy != NULL)
    {
        printf("%d-->", dummy->data);
        dummy = dummy->next;
    }
    printf("rear\n");
}

int main()
{
    dequeue();
    printQ();
    enqueue();
    printQ();
    enqueue();
    printQ();
    dequeue();
    printQ();
    return 0;
}