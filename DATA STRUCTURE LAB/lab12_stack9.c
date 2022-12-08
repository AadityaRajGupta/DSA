// Calling a function by Reference, implementation of Stack using Call by reference
#include <stdio.h>
#include <stdlib.h>

#define size 20

struct stack
{
    int a[size];
    int top;
};

typedef struct stack stk;

int create(stk *HELL)
{
    HELL->top=-1;
}
int display(stk *HELL)
{
    if (HELL->top==-1)
    {
        printf("\n\nSTACK IS EMPTY!!!\n\n");
        return 0;
    }
    printf("\n\nSTACK:");
    for (int i = 0; i <= HELL->top; i++)
        printf("%d ", HELL->a[i]);
    printf("\n");
    return 0;
}
int pop(stk *HELL)
{
    if (HELL->top==-1)
    {
        printf("\n\nEMPTY\n\n");
        return 0;
    }
    int x=HELL->a[HELL->top--];
    printf("\n\nPOPED ELEMENT: %d\n\n",x);
    return 0;
}
int push(stk *HELL)
{
    if (HELL->top==size-1)
    {
        printf("\n\nSTACK FULL\n\n");
        return 0;
    }
    int x;
    printf("\n\nENTER ANY NUMBER TO PUSH:");
    scanf("%d",&x);
    HELL->a[++HELL->top]=x;
    return 0;
}
int main()
{
    int choose=0;
    stk *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    create(s);
    while(1)
    {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
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

struct input
{
    int a;
};
int function(struct input *hello)
{
    hello->a=50;
    printf("\n\nVALUE OF A (INSIDE FUNTION): %d\n",hello->a);
    return 0;
}
int main()
{
    struct input *i;
    i=(struct input *) malloc(sizeof(struct input));
    i->a=20;
    printf("\nVALUE OF A (BEFORE FUNTION CALL): %d\n",i->a);
    function(i);
    printf("\n\nVALUE OF A (AFTER FUNTION CALL): %d\n",i->a);
    return 0;
}*/
