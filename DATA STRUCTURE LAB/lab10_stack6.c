// Program to check the validity of Parenthesized Arithmetic Expression using Stack

#include <stdio.h>
#include <stdlib.h>

#define size 20

struct stack
{
    char check[size];
    int top;
}*s;

#define create() s->top = -1
#define push(item) s->check[++s->top] = item
#define pop() s->check[s->top--]
#define top_E() s->check[s->top]

int main()
{
    char str[20];
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    gets(str);

    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
            push(str[i]);
        if (str[i] == ')')
        {
            if ( top_E() == '(' && str[i] == ')')
                pop();
        }
        i++;
    }
    if (s->top == -1)
        printf("EXPRESSION IS BALANCED");
    else
        printf("EXPRESSION IS NOT BALANCED");
    return 0;
}
