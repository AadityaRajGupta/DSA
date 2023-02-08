#include <stdio.h>
#include <stdlib.h>

#define size 2
// Program of Array Implementaion of Linear Queue

/*
Queue follows the ⁡⁣⁣⁢First In First Out (FIFO)⁡ rule 

In programming terms, putting items in the queue is called ⁡⁢⁢⁢ENQUEUE⁡,
and removing items from the queue is called ⁡⁢⁢⁢DEQUEUE⁡.

*/

struct queue
{
    int a[size];
    int f;
    int r;
} *q;
int create()
{
    q->f = -1;
    q->r = -1;
}
int isempty()
{
    if (q->r == -1)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if (q->r == size - 1)
        return 1;
    return 0;
}
int insertion(int item)
{
    if (!isfull())
        q->a[++q->r] = item;
    else
        printf("\nQUEUE IS FULL!!!\n");
}
int deletion()
{
    if (!isempty())
    {
        printf("\nDELETED ELEMENT: %d\n", q->a[++q->f]);
        if(q->f==q->r)
            create();
    }
    else
        printf("\nQUEUE IS EMPTY!!!");
    return 0;
}
int display()
{
    if (!isempty())
    {
        printf("\n\nQUEUE:");
        int i;
        for (i = q->f + 1; i != q->r + 1; i++)
            printf("%d ", q->a[i]);
        printf("\n");
    }
    else
        printf("\nQUEUE IS EMPTY!!!");
    return 0;
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
    int choose;
    q = (struct queue *)malloc(sizeof(struct queue));
    create();
    while (1)
    {
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            insertion(input());
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("\n\nINVALID CHOICE!!!\n\n");
            break;
        }
    }
    return 0;
}