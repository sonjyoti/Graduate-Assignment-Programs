
// program to create a doubly linked list with insertion and deletion operations

#include <stdio.h>  // standard input output header file
#include <stdlib.h> // standard library header file

struct dll // structure declaration for one node
{
    int val;                 // member to store the value of a node of integer type
    struct dll *prev, *next; // two pointers that will store the address of the previous and next nodes
};

typedef struct dll Node;

Node *head = NULL; // this will store the address of the initial node

// below function will return a Node * (pointer)
Node *getNode() // creating a node
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // memory allocation for the new node
    printf("Enter data: ");
    scanf("%d", &newNode->val); // reading data for the new node
    newNode->prev = NULL;       // previous is being set to null for the new node
    newNode->next = NULL;       // next is being set to null for the new node
    return newNode;             // returning the new node
}

void displayList() // displaying of the linked list
{
    if (head == NULL) // if list is empty
    {
        printf("Empty list.\n"); // display this message
        return;                  // then return
    }

    printf("Displaying the linked list.\n");

    printf("head-->");
    Node *tmp = head;   // or else create a temporary node and point it to the same address as head
    while (tmp != NULL) // traverse till temporary node becomes null
    {
        printf("%d-->", tmp->val); // print the data along with it
        tmp = tmp->next;           // update temp as temp's next
    }
    printf("null\n");
}

void revDisplayList() // reversal traversal of the linked list
{
    if (head == NULL) // if list is empty
    {
        printf("Empty list.\n"); // display this message
        return;                  // then return
    }

    printf("Reverse display of the list.\n");

    Node *tmp = head;         // or else create a temporary node
    while (tmp->next != NULL) // traverse till temp's next becomes null
        tmp = tmp->next;      // update temp as temp's next
    printf("null-->");
    while (tmp != NULL) // then traverse temp becomes null
    {
        printf("%d-->", tmp->val); // printf temp's value along
        tmp = tmp->prev;           // update temp as temp's previous
    }
    printf("head\n");
}

void countNodesDisplay() // counting the number of nodes in the list and will display
{
    if (head == NULL) // if list is empty
    {
        printf("No. of node(s): 0.\n");
        return;
    }
    Node *temp = head;   // declaring a temporary variable and making it point towards to the same node as head
    int count = 0;       // a count variable of int type to store no. of nodes
    while (temp != NULL) // temp will traverse till the last node
    {
        temp = temp->next; // updating temp as temp's next
        count++;           // count is incremented by 1 every time temp passes a node
    }
    printf("No. of node(s): %d\n", count); // result will be displayed
}

// INSERTION FUNCTIONS

void insertFirst() // inserting a node at the beginning of the node
{
    printf("\nInserting element at the first position.\n");

    Node *newNode = getNode(); // declaring a node and calling getNode() to create a new node
    if (head == NULL)          // if list is null
    {
        head = newNode; // make head the new node
        return;         // then return
    }
    head->prev = newNode; // else link head's previous node as the new node
    newNode->next = head; // the make new node's next the node that the start is pointing
    head = newNode;       // then make the head the new node as we're inserting in the beginning
}

void insertLast() // inserting node at the end of the list
{
    printf("\nInserting element at the last position.\n");

    Node *newNode = getNode(); // declaring a node and calling getNode() to create a new node
    if (head == NULL)          // if the list is empty
    {
        head = newNode; // make head the new node
        return;         // return
    }
    Node *tmp = head;         // or else create a temporary variable (i.e 'tmp' here)
    while (tmp->next != NULL) // traverse till tmp's next becomes null
        tmp = tmp->next;      // make tmp as tmp's next along
    newNode->prev = tmp;      // now make the new node's previous tmp
    tmp->next = newNode;      // then make temp's next as the new node
}

void insertPosition() // inserting in an intermediate position of the list
{
    printf("\nInserting element at an intermidiate position.\n");

    Node *newNode = getNode(); // declaring a node and calling getNode() to create a new node
    if (head == NULL)          // if list is empty
    {
        head = newNode; // make head, the new node
        return;         // then return
    }
    int pos;
    printf("Input position: ");
    scanf("%d", &pos);            // taking input of the desired position
    Node *temp = head;            // a temporary pointer 'temp' is declared to traverse to the position
    for (int i = 1; i < pos; i++) // for loop used for the traversal
        temp = temp->next;        // making temp, temp's next until it gets to the position
    newNode->prev = temp;         // new node's previous is pointed to temp
    newNode->next = temp->next;   // new node's next is now pointing towards the temp's next
    temp->next->prev = newNode;   // temp's next node's previous is then made to point to the new node
    temp->next = newNode;         // then temp's next is pointed towards the new node
}

// DELETION FUNCTIONS

void deleteFirst() // deleting a node from the beginning of the list
{
    printf("\nDeleting element at the first position.\n");

    if (head == NULL) // if the list is empty
    {
        printf("Empty list.\n"); // display this message
        return;                  // then return
    }
    head = head->next; // head is made to point at head's next
    head->prev = NULL; // head's prev is made null
}

void deleteLast() // deleting a node from the ending of the list
{
    printf("\nDeleting element at the last position.\n");

    if (head == NULL) // if list is empty
    {
        printf("Empty list.\n"); // display this message
        return;                  // then return
    }

    Node *temp = head; // temporary variable, temp, is declared

    while (temp->next->next != NULL) // temp will traverse till the last second node
        temp = temp->next;           // updating temp to it's next
    temp->next = NULL;               // last second node of the list will now point to null
}

void deletePosition()
{
    printf("\nDeleting element at an intermediate position.\n");

    if (head == NULL) // if list is empty
    {
        printf("Empty list.\n"); // display this message
        return;                  // then return
    }

    Node *temp = head; // taking a temporary variable temp and pointing it to the head
    int pos;
    printf("Input position: ");
    scanf("%d", &pos); // taking input of the desired position

    if (pos == 0) // if the first element to be deleted
    {
        deleteFirst(); // deleteFirst() is called to delete the only element
        return;        // then return
    }

    for (int i = 1; i < pos; i++) // temp will traverse till desired position
        temp = temp->next;
    temp->next->next->prev = temp; // updating the 'to be deleted' node's next node's previous node to temp
    temp->next = temp->next->next; // then the next of the entered node's previous node's next will point to the position node's next
}

int main()
{
    displayList(); // display function call

    insertLast(); // insertion at the end function call

    displayList();

    insertFirst(); // insertion at the beginning function call

    displayList();

    insertFirst();

    displayList();

    insertLast();

    displayList();

    revDisplayList(); // reverse display of the list

    insertPosition();

    displayList();

    countNodesDisplay();

    revDisplayList();

    deleteFirst(); // deleting a node from the beginning

    displayList();

    countNodesDisplay();

    revDisplayList();

    deleteLast(); // deleting a node from the ending

    displayList();

    countNodesDisplay();

    revDisplayList();

    deletePosition(); // deleting a node from an intermidiate position

    displayList();

    revDisplayList();

    countNodesDisplay();

    return 0;
}
