// Program for implementation of 2 stacks using a single Array

#include <stdio.h>
#include <stdlib.h>

#define size 5
struct stack
{
    int a[size];
    int top1,top2;
}*s;

int create()
{
    s->top1=-1;
    s->top2=size;
}
int push(int item,int stk)
{
    if ((s->top1+1)!=s->top2)
    {
        if (stk==1)
            s->a[++s->top1]=item;
        else
            s->a[--s->top2]=item;
    }
    else
        printf("\n\nSTACK IS FULL!!!\n");
    return 0;
}
int pop(int stk)
{
    if (stk == 1)
    {
        if (s->top1 == -1)
        {
            printf("\nSTACK 1 EMPTY!!!\n");
            return 0;
        }
        printf("\nPOPED ELEMENT FROM STACK 1:%d", s->a[s->top1--]);
    }
    else
    {
        if (s->top2 == size)
        {
            printf("\nSTACK 2 EMPTY!!!\n");
            return 0;
        }
        printf("\nPOPED ELEMENT FROM STACK 2:%d", s->a[s->top2++]);
    }
    return 0;
}
int display()
{
    int i;
    printf("\nSTACK 1:");
    for(i=0;i<=s->top1;i++)
        printf("%d ",s->a[i]);
    printf("\n\nSTACK 2:");
    for(i=size-1;i>=s->top2;i--)
        printf("%d ",s->a[i]);
    printf("\n\n");
}
int main()
{
    int choose=0,item,stk;
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    while(1)
    {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("\nENTER ANY NUMBER:");
            scanf("%d", &item);
            printf("STACK 1 or 2:");
            scanf("%d", &stk);
            push(item,stk);
            break;
        case 2:
            printf("\n\nSTACK 1 or 2:");
            scanf("%d", &stk);
            pop(stk);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("\n\nINVALID CHOICE\n\n");
            break;
        }
    }
    return 0;
}

