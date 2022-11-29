#include <stdio.h>
#include <stdlib.h>

#define size 20

#define create() s->top = -1;
#define push(item) s->a[++s->top] = item;
#define pop() s->a[s->top--]
struct stack
{
    int a[size];
    int top;
}*s;

int palindrome(int number)
{
    int temp=number;
    int digit_size=0,i;
    while(temp!=0)
    {
        digit_size++;
        temp=temp/10;
    }
    temp=number;
    for(i=0;i<(int)(digit_size/2);i++)
    {
        push(temp%10);
        temp=temp/10;
    }
    if (digit_size%2!=0)
    {
        i++;
        temp=temp/10;
    }
    for(;i<digit_size;i++)
    {
        if(temp%10!=pop())
            return 0;
        temp=temp/10;
    }
    return 1;
}
int main()
{
    int check,number;
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    printf("ENTER ANY NUMBER:");
    scanf("%d",&number);
    check=palindrome(number);
    (check==0) ? printf("NOT PALINDROME") : printf("PALINDROME");
    return 0;
}
