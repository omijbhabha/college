#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 10
typedef struct
{
    int front;
    int rear;
    int items[MAX];
} Dequeue;
void init(Dequeue *dq)
{
    dq->front = -1;
    dq->rear = -1;
}
bool isFull(Dequeue *dq)
{
    return ((dq->rear + 1) % MAX == dq->front);
}
bool isEmpty(Dequeue *dq)
{
    return (dq->front == -1 && dq->rear == -1);
}
void enqueueR(Dequeue *dq, int x)
{
    if (isFull(dq))
    {
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->items[dq->rear] = x;
}
void enqueueF(Dequeue *dq, int x)
{
    if (isFull(dq))
    {
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = 0;
        dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->items[dq->front] = x;
}
void dequeueF(Dequeue *dq)
{
    if (isEmpty(dq))
    {
        return;
    }
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        printf("%d\n", dq->items[dq->front]);
        dq->front = (dq->front + 1) % MAX;
    }
}
void dequeueR(Dequeue *dq)
{
    if (isEmpty(dq))
    {
        return;
    }
    if (dq->front == dq->rear)
    {
        dq->front = -1;
        dq->rear = -1;
    }
    else
    {
        printf("%d\n", dq->items[dq->rear]);
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}
void display(Dequeue *dq)
{
    int i = dq->front;
    while (true)
    {
        printf("%d ", dq->items[i]);
        if (i == dq->rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    Dequeue deque;
    init(&deque);

    enqueueR(&deque, 10);
    enqueueF(&deque, 20);
    enqueueR(&deque, 30);
    enqueueF(&deque, 40);

    display(&deque); // Output: 40 20 10 30
    dequeueF(&deque);
    dequeueR(&deque);

    display(&deque); // Output: 20 10

    return 0;
}
