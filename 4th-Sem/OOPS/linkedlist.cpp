/*Write a class template for representing a singly linked list. Write functions for inserting,
deleting, searching and for displaying a linked list.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class SLL
{
private:
    class Node
    {
    public:
        int data;
        Node *link;
        Node(int val)
        {
            data = val;
        }
    };

    Node *head = NULL;

    Node *createNode(int val)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = val;
        newNode->link = NULL;
        return newNode;
    }

public:
    void insertNode(int val)
    {
        printf("Insertion.\n");
        if (head == NULL)
            head = createNode(val);
        else
        {
            Node *newNode = createNode(val);
            newNode->link = head;
            head = newNode;
        }
    }
    void display()
    {
        Node *temp = head;
        printf("head");
        while (temp != NULL)
        {
            printf("-->%d", temp->data);
            temp = temp->link;
        }
        printf("-->null\n");
    }
    void deleteNode()
    {
        if (head == NULL)
            printf("Empty list.");
        else
        {
            printf("Deletion.\n");
            head = head->link;
        }
    }
    void search(int val)
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            if (temp->data == val)
            {
                cout << "Element found in position: " << i << "\n";
                return;
            }
            temp = temp->link;
        }
        cout << "Element not available.\n";
    }
};

int main()
{
    SLL list;
    list.insertNode(7);
    list.insertNode(9);
    list.display();
    list.insertNode(5);
    list.display();
    list.deleteNode();
    list.display();
    list.search(7);
    return 0;
}