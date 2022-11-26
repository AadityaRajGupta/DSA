#include <stdio.h>
#include <stdlib.h>

#define size 20

#define create() s->top = -1;
#define push(item) s->a[++s->top] = item;
#define pop() s->a[s->top--];
struct stack
{
    int a[size];
    int top;
    int decimal;
    int base;
}*s;

void display()
{
    int item;
    while(s->top!=-1)
    {
        item=pop();
        printf("%d",item);
    }
    printf("\n\n");
}
void decimal_to_any()
{
    int num=s->decimal;
    while(num!=0)
    {
        push(num%(s->base));
        num=num/(s->base);
    }
}
void input_decimal()
{
    int D;
    printf("\nENTER DECIMAL BASE NUMBER:");
    scanf("%d", &D);
    s->decimal=D;
}
int main()
{
    int choose, D, B;
    s = (struct stack *)malloc(sizeof(struct stack));
    create();
    s->base = 8;
    input_decimal();
    printf("\nDECIMAL TO OCTAL CONVERSION\n");
    decimal_to_any();
    printf(" %d ==> ", s->decimal);
    display();
    return 0;
}
