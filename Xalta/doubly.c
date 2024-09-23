#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev; // Pointer to the previous node
};

// Global head pointer for the doubly linked list
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // Initialize previous pointer to NULL
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void InsertAtEnd(int x)
{
    struct Node *newNode = createNode(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp; // Set the previous pointer of the new node
}

// Function to print the doubly linked list
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Main function to demonstrate the doubly linked list
int main()
{
    // Insert elements into the doubly linked list
    InsertAtEnd(1);
    InsertAtEnd(2);
    InsertAtEnd(3);

    printf("Doubly Linked List: ");
    Print(); // Outputs: 1 <-> 2 <-> 3 <-> NULL

    // Free the doubly linked list
    FreeList();

    return 0;
}
