#include <stdio.h>
#include <stdlib.h>

// Program of Array Implementaion of CircularQueue

#define size 5

struct queue
{
    int a[size];
    int f;
    int r;
}*q;

int create()
{
    q->f=-1;
    q->r=-1;
}

int isempty()
{
    if (q->f==-1)
        return 1;
    return 0;
}

int isfull()
{
    if ((q->f==0 && q->r==size-1) || q->f==q->r+1)
        return 1;
    return 0;
}
int insertion(int item)
{
    if (!isfull())
    {
        if (q->f==-1)
            q->f=0;
        q->r=(q->r+1)%size;
        q->a[q->r]=item;
    }
    else
        printf("\n\nQUEUE IS FULL!!!\n\n");
}
int deletion()
{
    if (!isempty())
    {
        int item=q->a[q->f];
        if (q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else
            q->f=(q->f+1)%size;
        printf("\nDELETED ELEMENT: %d\n\n",item);
    }
    else
        printf("\nQUEUE IS EMPTY!!!\n\n");
    return 0;
}
int input()
{
    int item;
    printf("\n\nENTER ANY NUMBER:");
    scanf("%d",&item);
    return item;
}
int display()
{
    if (!isempty())
    {
        // printf("\n\nf: %d r:%d\n",q->f,q->r);
        printf("\n\nQUEUE:");
        int i = q->f;
        for (; i != q->r; i = (i + 1) % size)
        {
            printf("%d ", q->a[i]);
        }
        printf("%d \n\n", q->a[i]);
    }
    return 0;
}
int main()
{
    int choose;
    q=(struct queue *) malloc (sizeof(struct queue));
    create();
    while (1)
    {
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch(choose)
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