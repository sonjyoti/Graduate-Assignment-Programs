
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
int stack[MAX];
int top = 0;

void display()
{
    int j;
    if (top == 0)
    {
        printf("Empty stack.\n");
        return;
    }
    for (j = 0; j < top; j++)
        printf("%d ", stack[j]);
    printf("\n");
}

void pop()
{
    if (top == 0)
    {
        printf("Stack underflow.\n");
        return;
    }
    printf("Popped element is: %d\n", stack[--top]);
}

void push()
{
    if (top == MAX)
    {
        printf("Stack overflow.\n");
        return;
    }
    int data;
    printf("Input the data: ");
    scanf("%d", &data);
    stack[top] = data;
    top++;
    printf("Data pushed to the stack.\n");
}

int main()
{
    pop();
    display();
    push();
    display();
    push();
    display();
    push();
    display();
    pop();
    display();
    return 0;
}