#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10
typedef struct
{
    int top;
    char stack[100];
} Stack;
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
void init(Stack *s)
{
    s->top = -1;
}
void push(Stack *s, char op)
{
    s->stack[++(s->top)] = op;
}
char pop(Stack *s)
{
    return s->stack[s->top--];
}
int main()
{
    Stack s;
    char *exp;
    char x;
    init(&s);
    exp = (char *)calloc(MAX, sizeof(char));
    scanf("%s", exp);
    for (int i = 0; i < strlen(exp); i++) // not needed
    {
        while (*exp != '\0')
        {
            if (isalnum(*exp))
            {
                printf("%c", *exp);
            }
            else if (*exp == '(')
            {
                push(&s, *exp);
            }
            else if (*exp == ')')
            {
                while ((x = pop(&s)) != '(')
                {
                    printf("%c", x);
                }
            }
            else
            {
                while (precedence(s.stack[s.top]) >= precedence(*exp))
                {
                    printf("%c", pop(&s));
                }
                push(&s, *exp);
            }
            exp++;
        }
    }
    while (s.top != -1)
    {
        printf("%c", pop(&s));
    }
}