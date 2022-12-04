//Program for implementation of Multiple stack in one Array

#include <stdio.h>
#include <stdlib.h>

#define size 20
struct stack
{
    int a[size];
    int top1,top2,top3,top4;    // used 1 array to implement 4 stacks
}*s;

int create()
{
    s->top1=-1;
    s->top2=size/2;
    s->top3=size/2-1;
    s->top4=size;
}
int push(int item,int stk)
{
    if (stk == 1 || stk == 2)
    {
        if ((s->top1 + 1) != s->top2)
        {
            if (stk == 1)
                s->a[++s->top1] = item;
            else if (stk == 2)
                s->a[--s->top2] = item;
        }
        else
            printf("\n\nSTACK 1 AND 2 ARE FULL!!!\n");
    }
    if (stk == 3 || stk == 4)
    {
        if ((s->top3 + 1) != s->top4)
        {
            if (stk == 3)
                s->a[++s->top3] = item;
            else if (stk == 4)
                s->a[--s->top4] = item;
        }

        else
            printf("\n\nSTACK 3 AND 4 ARE FULL!!!\n");
    }
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
    else if (stk==2)
    {
        if (s->top2 == size/2)
        {
            printf("\nSTACK 2 EMPTY!!!\n");
            return 0;
        }
        printf("\nPOPED ELEMENT FROM STACK 2:%d", s->a[s->top2++]);
    }
    else if (stk == 3)
    {
        if (s->top3 == size/2-1)
        {
            printf("\nSTACK 3 EMPTY!!!\n");
            return 0;
        }
        printf("\nPOPED ELEMENT FROM STACK 3:%d", s->a[s->top3--]);
    }
    else if (stk==4)
    {
        if (s->top4 == size)
        {
            printf("\nSTACK 4 EMPTY!!!\n");
            return 0;
        }
        printf("\nPOPED ELEMENT FROM STACK 4:%d", s->a[s->top4++]);
    }
    return 0;
}
int display()
{
    int i;
    printf("\nSTACK 1:");
    for(i=0;i<=s->top1;i++)
        printf("%d ",s->a[i]);

    printf("\nSTACK 2:");
    for(i=size/2-1;i>=s->top2;i--)
        printf("%d ",s->a[i]);

    printf("\nSTACK 3:");
    for(i=size/2;i<=s->top3;i++)
        printf("%d ",s->a[i]);
    
    printf("\nSTACK 4:");
    for(i=size-1;i>=s->top4;i--)
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
            printf("STACK [1,2,3,4]:");
            scanf("%d", &stk);
            push(item,stk);
            break;
        case 2:
            printf("\n\nSTACK [1,2,3,4]:");
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

