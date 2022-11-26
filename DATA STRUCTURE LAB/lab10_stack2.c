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
    s->base = 2;
    input_decimal();
    printf("\nDECIMAL TO BINARY CONVERSION:\n");
    decimal_to_any();
    printf(" %d ==> ", s->decimal);
    display();
    return 0;
}

/*
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
    printf("\nPRESS 1 FOR DECIMAL TO BINARY CONVERSION\nPRESS 2 FOR DECIMAL TO OCTAL CONVERSION\nPRESS 3 FOR DECIMAL TO HEXADECIMAL CONVERSION\nPRESS 4 FOR DECIMAL TO ANY BASE CONVERSION\nENTER YOUR CHOOSE:");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        s->base = 2;
        input_decimal();
        printf("\nDECIMAL TO BINARY CONVERSION:\n");
        break;
    case 2:
        s->base = 8;
        input_decimal();
        printf("\nDECIMAL TO OCTAL CONVERSION\n");
        break;
    case 3:
        s->base = 16;
        input_decimal();
        printf("\nDECIMAL TO HEXADECIMAL CONVERSION:\n");
        break;
    case 4:
        input_decimal();
        printf("ENTER DESIRED BASE VALUE:");
        scanf("%d",&B);
        s->base=B;
        printf("\nDECIMAL TO ANY BASE CONVERSION:\n");
        break;
    default:
        printf("\nINVALID CHOICE!!!\n");
        return 0;
    }
    decimal_to_any();
    printf(" %d ==> ",s->decimal);
    display();
    return 0;
}
*/
