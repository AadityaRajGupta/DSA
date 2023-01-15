// Program for Queue implementation using Stack

#include <stdio.h>
#include <stdlib.h>

#define size 10

#define create_A() s1->top = -1;
#define push_A(item) s1->a[++s1->top] = item
#define pop_A() s1->a[s1->top--]

#define create_B() s2->top = -1;
#define push_B(item) s2->a[++s2->top] = item
#define pop_B() s2->a[s2->top--]

struct stack
{
    int a[size];
    int top;
};

void enqueue(struct stack *s1,int item)
{
    push_A(item);
}

void dequeue(struct stack *s1,struct stack *s2)
{
    int item;
    while(s1->top!=0)
        push_B(pop_A());
    
    printf("\n\nDELETED ELEMENT:%d\n\n",pop_A());

    while(s2->top!=-1)
        push_A(pop_B());
}

int display(struct stack *s1)
{
    printf("\n\nQUEUE:");
    for (int i = 0; i <= s1->top; i++)
        printf("%d ", s1->a[i]);
    printf("\n");
}

int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
}

int main()
{
    struct stack *s1,*s2;
    s1 = (struct stack *)malloc(sizeof(struct stack));
    s2 = (struct stack *)malloc(sizeof(struct stack));

    int item,choose;

    create_A();
    create_B();
    while(1)
    {
        printf("\n==========================================================\n");
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            if (s1->top==size-1)
                printf("\n\nQUEUE FULL\n\n");
            else
                enqueue(s1,input());
            break;
        case 2:
            if (s1->top==-1)
                printf("\n\nQUEUE IS EMPTY!!!\n\n");
            else
                dequeue(s1,s2);
            break;
        case 3:
            if (s1->top==-1)
                printf("\n\nQUEUE IS EMPTY!!!\n\n");
            else
                display(s1);
            break;
        case 4:
            return 0;
        default:
            printf("\n\nINVALID CHOICE\n\n");
            break;
        }
    }
}