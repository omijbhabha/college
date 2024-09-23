#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int front;
    int rear;
    int items[MAX];
} Queue;

// Function to initialize the queue
void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
bool isFull(Queue *q)
{
    if (q->rear == MAX - 1)
    {
        return true;
    }
    return false;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q)
{
    if (q->front == -1)
    {
        return true;
    }
    return false;
}

// Function to insert an element into the priority queue
void push(Queue *q, int num)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1)
    {
        // First element to be inserted
        q->front = 0;
        q->rear = 0;
        q->items[q->rear] = num;
    }
    else
    {
        // Insert element in its correct position based on priority
        int i;
        for (i = q->rear; i >= q->front; i--)
        {
            if (q->items[i] > num)
            {
                q->items[i + 1] = q->items[i]; // Shift elements to make space
            }
            else
            {
                break;
            }
        }
        q->items[i + 1] = num; // Insert the new element
        q->rear++;             // Increase the rear index
    }
}

// Function to remove the highest priority element (smallest number)
void pop(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return;
    }

    // Remove the front element
    printf("Popped: %d\n", q->items[q->front]);

    if (q->front == q->rear)
    {
        // Only one element was present
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
}

// Function to display the priority queue elements
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    Queue pq;
    init(&pq);

    push(&pq, 40);
    push(&pq, 30);
    push(&pq, 50);
    push(&pq, 10);
    push(&pq, 20);

    printf("Priority Queue elements: ");
    display(&pq); // Should print elements in priority order: 10 20 30 40 50

    pop(&pq); // Pops 10
    printf("Priority Queue after pop: ");
    display(&pq); // Should print: 20 30 40 50

    return 0;
}