#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
typedef struct
{
    int top;
    char stack[MAX];
} Stack;
void init(Stack *s)
{
    s->top = -1;
}
void reverse(char *exp)
{
    char temp;
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++)
    {
        temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}
int precedence(char op)
{
    switch (op)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    default:
        return -1;
    }
}
char pop(Stack *s)
{
    return s->stack[(s->top)--];
}
void push(Stack *s, char op)
{
    s->stack[++s->top] = op;
}
int main()
{
    Stack s;
    init(&s);
    int j = 0;
    char x;

    char *exp;
    char *postfix;

    exp = (char *)calloc(MAX, sizeof(char));
    scanf("%s", exp);
    postfix = (char *)calloc(MAX, sizeof(char));
    int len = strlen(exp);
    reverse(exp);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            exp[i] = ')';
        }
        else if (exp[i] == ')')
        {
            exp[i] = '(';
        }
    }

    while (*exp != '\0')
    {
        if (isalnum(*exp))
        {
            postfix[j++] = *exp;
        }
        else if (*exp == '(')
        {
            push(&s, *exp);
        }
        else if (*exp == ')')
        {
            while ((x = pop(&s)) != '(')
            {
                postfix[j++] = x;
            }
        }
        else
        {
            while (precedence(s.stack[s.top]) >= precedence(*exp))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, *exp);
        }
        exp++;
    }
    while (s.top != -1)
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    reverse(postfix);
    printf("%s", postfix);
}
