#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node in the polynomial linked list
struct Node
{
    int coefficient;   // Coefficient of the term
    int exponent;      // Exponent of the term
    struct Node *next; // Pointer to the next node
};

// Global head pointer for the polynomial linked list
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL; // Initialize next pointer to NULL
    return newNode;
}

// Function to insert a new term at the end of the polynomial linked list
void InsertAtEnd(int coeff, int exp)
{
    struct Node *temp = createNode(coeff, exp);

    if (head == NULL)
    {
        head = temp; // If the list is empty, set head to the new node
        return;
    }

    struct Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next; // Traverse to the end of the list
    }

    temp2->next = temp; // Link the new node at the end
}

// Function to print the polynomial linked list
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Main function to demonstrate the polynomial linked list
int main()
{
    // Insert polynomial terms into the linked list
    InsertAtEnd(3, 2); // 3x^2
    InsertAtEnd(5, 1); // + 5x
    InsertAtEnd(2, 0); // + 2

    printf("Polynomial: ");
    Print(); // Outputs: 3x^2 + 5x + 2

    // Free the polynomial linked list
    FreeList();

    return 0;
}
