#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int size = 10;
typedef struct
{
    int *items;
    int front;
    int rear;
} Queue;
void init(Queue *q)
{
    q->front = -1;
    q->rear = -1;
    q->items = (int *)calloc(size, sizeof(int));
}
bool isEmpty(Queue *q)
{
    return (q->front == -1);
}
bool isFull(Queue *q)
{
    return ((q->rear + 1) % size == q->front);
}
void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        return;
    }

    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % size;
    }

    q->items[q->rear] = x;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % size;
    }
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    while (true)
    {
        printf("%d ", q->items[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);
    enqueue(&q, 7);
    enqueue(&q, 9);
    enqueue(&q, 10);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 3);
    enqueue(&q, 7);
    dequeue(&q);
    enqueue(&q, 3);

    display(&q);

    free(q.items);
    return 0;
}
// xdddd wrogn code go kys
