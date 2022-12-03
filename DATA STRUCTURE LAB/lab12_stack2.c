// Program for Finding Maximum/Minimum in the Stack
#include <stdio.h>
#include <stdlib.h>

#define size 20
struct stack
{
    int a[size];
    int max;
    int min;
    int top;
}*s;

#define create() s->top = -1;
#define push(item) s->a[++s->top] = item
#define pop() s->a[s->top--]
#define top_E() s->a[s->top]

int display()
{
    printf("\nSTACK:");
    for(int i=0;i<=s->top;i++)
    {
        printf(" %d ",s->a[i]);
    }
    printf("\n\n");
}
// maximum and minimum number from stack
int extreme()
{
    while (s->top!=-1)
    {
        int top_value=pop();
        if (s->max<top_value)
            s->max=top_value;
        if (s->min>top_value)
            s->min=top_value;
    }
    return 0;
}
int main()
{
    int choose,item,i;
    s=(struct stack *)malloc(sizeof(struct stack));
    s->max=__WINT_MIN__;   // store minimum number possible
    s->min=__INT_MAX__;    // store maximum number possible
    s->top=-1;
    printf("ENTER HOW MANY DATA WANT TO ENTER:");
    scanf("%d",&choose);
    for(i=0;i<choose;i++)
    {
        printf("ENTER ANY ELEMENT:");
        scanf("%d",&item);
        push(item);
    }
    display();
    extreme();
    printf("MAXIMUM FROM STACK: %d\n",s->max);
    printf("MINIMUM FROM STACK: %d\n",s->min);
    return 0;
}