#include <stdio.h>
#include <stdlib.h>

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
    if (q->f==q->r && q->f!=-1)
        return 1;
    return 0;
}

int isfull()
{
    // if(q->r==size-1)
    if(q->r==size-1 && q->f==-1)
        return 1;
    if((q->r+1)%size==q->f && q->f!=-1 )
        return 1;
    return 0;
}
int insertion(int item)
{
    if (!isfull())
    {
        q->r = ++q->r % size;
        q->a[q->r] = item;
        printf("\n");
        // printf("\n\nf: %d r:%d\n",q->f,q->r);
    }
    else
        printf("\n\nQUEUE IS FULL!!!\n\n");
}
int deletion()
{
    if (!isempty())
    {
        int item=q->a[++q->f%size];
        // return item;
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
        int i = q->f + 1;
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