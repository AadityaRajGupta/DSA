#include <stdio.h>
#include <stdlib.h>
#define size 10

// input restricted=0 or output restricted=1
// front=(front-1+cap)%cap 
// rear= (rear-1+cap)%cap 

struct queue
{
    int a[size];
    int f;
    int r;
    int restriction;
}*dq;

int create()
{
    dq->f=-1;
    dq->r=-1;
}

int isfull()
{
    if (dq->restriction==0)
    {
        if (dq->r!=-1 && (dq->f+1)%size)
    }
    else
    {

    }
}
int insertion_front()
{
    
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
        // printf("\n\nf: %d r:%d\n",dq->f,dq->r);
        printf("\n\nQUEUE:");
        int i = dq->f + 1;
        for (; i != dq->r; i = (i + 1) % size)
        {
            printf("%d ", dq->a[i]);
        }
        printf("%d \n\n", dq->a[i]);
    }
    else
        printf("\nQUEUE IS EMPTY!!!\n\n");
    return 0;
}
int main()
{
    int choose;
    dq = (struct queue *)malloc(sizeof(struct queue));
    create();

    while(1)
    {
        printf("\n1. INSERT TO FRONT\n2. DELETE FROM FRONT\n\n3. INSERT TO REAR\n4. DELETE FROM REAR\n\n5. DISPLAY\n6. EXIT \n\nENTER YOUR CHOOSE:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                insertion_front(input());
                break;
            case 2:
                insertion_rear(input());
                break;
            case 3:
                deletion_front();
                break;
            case 4:
                deletion_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
            printf("\nINVALID ENTRY!!!\n");
                break;
        }
    }
    return 0;
}