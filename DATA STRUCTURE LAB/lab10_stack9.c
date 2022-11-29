#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

#define create() s->top = -1
#define push(item) s->original[++s->top] = item
#define pop() s->original[s->top--]

struct stack
{
    char original[size];
    int top;
}*s;
int display()
{
    printf("REVERSE OF GIVEN STRING:");
    while(s->top!=-1)
        printf("%c",pop());
}
int main()
{
    char str[size];
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    printf("ENTER ANY STRING:");
    gets(str);
    int i=-1;
    while(str[++i]!='\0')
        push(str[i]);
    display();
    return 0;
}
