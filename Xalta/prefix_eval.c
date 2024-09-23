#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 100
typedef struct
{
    int top;
    int stack[MAX];
} Stack;
void init(Stack *s)
{
    s->top = -1;
}
void push(Stack *s, int item)
{
    s->stack[++s->top] = item;
}
int pop(Stack *s)
{
    return s->stack[s->top--];
}
int main()
{
    Stack s;
    init(&s);
    int op1, op2;
    char exp[MAX];
    scanf("%s", exp);
    int len = strlen(exp);
    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {
            push(&s, exp[i] - '0');
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            switch (exp[i])
            {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    int result = pop(&s);
    printf("%d", result);
}
