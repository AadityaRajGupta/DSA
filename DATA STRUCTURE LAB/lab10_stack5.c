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
        if (item>=10)
            printf("%c",(item%10)+65);
        else
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
    int choose,D,B;
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    input_decimal();
    printf("ENTER DESIRED BASE VALUE:");
    scanf("%d", &B);
    s->base = B;
    printf("\nDECIMAL TO ANY BASE CONVERSION:\n");
    decimal_to_any();
    printf(" %d ==> ", s->decimal);
    display();
    return 0;
}
