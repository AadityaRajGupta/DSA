#include <stdio.h>
#include <stdlib.h>

#define size 20

struct stack
{
    int a[size];
    int top;
}*s;

int create()
{
    s->top=-1;
}
int display()
{
    if (s->top==-1)
    {
        printf("\n\nSTACK IS EMPTY!!!\n\n");
        return 0;
    }
    printf("\n\nSTACK:");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->a[i]);
    printf("\n");
    return 0;
}
int pop()
{
    if (s->top==-1)
    {
        printf("\n\nEMPTY\n\n");
        return 0;
    }
    int x=s->a[s->top--];
    printf("\n\nPOPED ELEMENT: %d\n\n",x);
    return 0;
}
int push()
{
    if (s->top==size-1)
    {
        printf("\n\nSTACK FULL\n\n");
        return 0;
    }
    int x;
    printf("\n\nENTER ANY NUMBER TO PUSH:");
    scanf("%d",&x);
    s->a[++s->top]=x;
    return 0;
}
int main()
{
    int choose=0;
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    while(1)
    {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

/*
#include <stdio.h>
#include <stdlib.h>

#define size 10

#define create() s->top = -1;
#define push(item) s->a[++s->top] = item;
#define pop() s->a[s->top--];
struct stack
{
    int a[size];
    int top;
} *s;

int display()
{
    printf("\n\nSTACK:");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}
int main()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    int item,choose=0;
    create();
    while(1)
    {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            if (s->top==size-1)
                printf("\n\nSTACK FULL\n\n");
            else
            {
                printf("\n\nENTER ANY NUMBER:");
                scanf("%d",&item);
                push(item);
            }
            break;
        case 2:
            if (s->top==-1)
                printf("\n\nEMPTY\n\n");
            else
            {
                item = pop();
                printf("\n\nPOPED ELEMENT:%d\n\n",item);
            }
            break;
        case 3:
            if (s->top==-1)
                printf("\n\nSTACK IS EMPTY!!!\n\n");
            else
                display();
            break;
        case 4:
            return 0;
        default:
            printf("\n\nINVALID CHOICE\n\n");
            break;
        }
    }
}*/