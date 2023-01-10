#include <stdio.h>
#include <stdlib.h>

#define size 10

// Program for ArrayImplementation of Double Ended Queue

/*
⁡⁢⁢⁣Input Restricted Deque:  In this deque, input is restricted at a single end but allows deletion at both the ends.
⁡⁢⁢⁣Output Restricted Deque:⁡ In this deque, output is restricted at a single end but allows insertion at both the ends.

front=(front-1+cap)%cap 
rear= (rear-1+cap)%cap 

*/
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}
void reset()
{
    printf("\033[0m");
}

struct queue
{
    int a[size];
    int front;
    int rear;
};

int create(struct queue *q)
{
    q->front=-1;
    q->rear=-1;
}

int isfull(struct queue *q)
{
    if (q->front==0 && q->rear==size - 1)
        return 1;
    if (q->front==q->rear+1)
        return 1;
    return 0;
}
int isempty(struct queue *q)
{
    if (q->front==-1)
        return 1;
    return 0;
}

// minus karke insert kar raha hu
void insertion_front(struct queue *q,int data)
{
    if (!isfull(q))
    {
        if(q->front==0 || q->front==-1)
            q->front=size-1;
        
        else
            q->front=q->front-1;
        q->a[q->front]=data;
    }
    else
    {
        green();
        printf("\nDEQUEUE IS FULL !!!\n");
        reset();
    }
}

// plus karke insert kar raha hu first case -1 to 0 karke insert karna hai
void insertion_rear(struct queue *q,int data)
{
    if (!isfull(q))
    {
        if(q->rear==size-1)
            q->rear=0;
        else 
            q->rear=q->rear+1;
        q->a[q->rear]=data;
    }
    else
    {
        green();
        printf("\nDEQUEUE IS FULL !!!\n");
        reset();
    }
}

//increment karte hi element delete
void deletion_front(struct queue *q)
{
    if(!isempty(q))
    {
        if(q->front==-1)
            q->front=0;
        printf("\nDELETED ELEMENT : %d",q->a[q->front]);
        q->a[q->front]=0;
        if (q->front==size-1)
            q->front=0;
        else if (q->front == q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->front=q->front+1;
    }
    else
    {
        red();
        printf("\nDEQUEUE IS EMPTY !!!\n");
        reset();
    }
}

// decrement karte hi element delete
void deletion_rear(struct queue *q)
{
    if(!isempty(q))
    {
        if(q->rear==-1)
            q->rear=size-1;
        printf("\nDELETED ELEMENT : %d",q->a[q->rear]);
        q->a[q->rear]=0;
        if (q->rear==0)
            q->rear=size-1;
        else if (q->front == q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
            q->rear=q->rear-1;
    }
    else
    {
        red();
        printf("\nDEQUEUE IS EMPTY !!!\n");
        reset();
    }
}

void count(struct queue *q)
{
    int i,count=0;
    for (i=0;i<size;i++)
        if(q->a[i]!=0)
            count++;
        
    printf("\nTOTAL NUMBER OF ELEMENT PRESENT: %d",count);
}
int input()
{
    int item;
    printf("\n\nENTER ANY NUMBER:");
    scanf("%d",&item);
    return item;
}

void display(struct queue *q)
{
    if (!isempty(q))
    {
        // printf("\n\nf: %d r:%d\n",dq->f,dq->r);
        printf("\n\nQUEUE:");
        int i;
        for (i=0; i < size; i++)
        {
            printf("%d ", q->a[i]);
        }
    }
    else
    {
        red();
        printf("\nDEQUEUE IS EMPTY !!!\n");
        reset();
    }
}
int main()
{
    int choose;
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    create(q);
    for(int i=0;i<size;i++)
        q->a[i]=0;

    while(1)
    {
        yellow();
        printf("\n\n=========================================================================================\n");
        reset();
        printf("\n1. INSERT TO FRONT\n2. DELETE FROM FRONT\n\n3. INSERT TO REAR\n4. DELETE FROM REAR\n\n5. DISPLAY\n6. COUNT\n7. EXIT \n\nENTER YOUR CHOOSE:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                insertion_front(q,input());
                break;
            case 2:
                deletion_front(q);
                break;
            case 3:
                insertion_rear(q,input());
                break;
            case 4:
                deletion_rear(q);
                break;
            case 5:
                display(q);
                break;
            case 6:
                count(q);
                break;
            case 7:
                return 0;
            default:
            printf("\nINVALID ENTRY!!!\n");
                break;
        }
    }
    return 0;
}