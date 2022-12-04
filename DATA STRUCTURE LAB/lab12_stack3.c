//Program for Sorting of stack
#include <stdio.h>
#include <stdlib.h>

#define size 10
#define create() s->top1 = -1;s->top2 = -1
#define push_a(item) s->a[++s->top1] = item
#define push_b(item) s->b[++s->top2] = item
#define pop_a() s->a[s->top1--]
#define pop_b() s->b[s->top2--]

struct stack
{
    int a[size];
    int b[size];
    int top1;
    int top2;
    int num;
} *s;

int empty()
{
    while (s->top2 != -1)
        push_a(pop_b());
}
int sort()
{
    int temp = pop_a();
    push_b(temp);
    int arr, brr;
    while(s->top2!=s->num)
    {
        arr = s->a[s->top1];//printf("arr: %d ",arr);
        brr = s->b[s->top2];//printf("brr: %d ",brr);
        if (brr < arr)
        {
            push_b(pop_a());
        }
        else
        {
            arr = pop_a();
            empty();
            push_b(arr);
        }
    }
}
int display_a()
{
    printf("\nA:");
    for (int i = 0; i <= s->top1; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}
int display_b()
{
    printf("B:");
    for (int i = 0; i <= s->top2; i++)
        printf("%d ", s->b[i]);
    printf("\n\n");
}
int main()
{
    s = (struct stack *)malloc(sizeof(struct stack));
    int item,number;
    create();

    printf("NUMBER OF ELEMENT WANT TO ENTER:");
    scanf("%d",&number);
    number--;
    s->num=number;
    printf("ENTER THE ELEMENT: ");
    while(s->top1!=s->num)
    {
        scanf("%d", &item);
        push_a(item);
    }
    // display_a();
    // display_b();
    sort();
    display_a();
    display_b();
    return 0;
}