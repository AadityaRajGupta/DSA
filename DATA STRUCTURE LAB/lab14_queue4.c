// Program for Stack implementation using Queue

#include <stdio.h>
#include <stdlib.h>

#define size 5

struct queue
{
    int a[size];
    int f;
    int r;
};

void swap(struct queue *a,struct queue *b)
{
    struct queue *temp;
    temp=(struct queue *)malloc(sizeof(struct queue));
    temp=a;
    a=b;
    b=temp;
}
int create(struct queue *q)
{
    q->f = -1;
    q->r = -1;
}
int isempty(struct queue *q)
{
    if (q->r==-1)
        return 1;
    return 0;
}
int isfull(struct queue *q)
{
    if (q->r == size - 1)
        return 1;
    return 0;
}




// first insertion pe dono zero(0) kar denge or f=0 and r tho increment karke insert kar hi raha hai
// some error during enqueuing as dequeue call that number time suspe 
void enqueue(struct queue *q,int item)
{
    if (q->r == -1)
        q->f = 0;

    q->a[++q->r] = item;
}
void push(struct queue *q,int item)
{
    if(!isfull(q))
        enqueue(q,item);
    else
        printf("\nSTACK IS FULL !!!\n");

}





// hum f kho insertion baad hi 0 pe le aae the tho uss index ka element delete karga phir increment kardega 
// jub r==f tho ake hi element hai array me tho usse delete karke reset kar denge r = f = -1 .
int dequeue(struct queue *q)
{
    int data=q->a[q->f];
    if (q->f == q->r)
        create(q);
    q->f++;

    return data;
}
void pop(struct queue *q1,struct queue *q2)
{
    if (!isempty(q1))
    {
        for (int i = q1->f; i < q1->r; i++)
            enqueue(q2,dequeue(q1));

        printf("\nDELETED ELEMENT: %d", dequeue(q1));
    }
    else 
        printf("\nSTACK IS EMPTY !!!\n");
}





void display(struct queue *q)
{
    if (!isempty(q))
    {
        printf("\n\nSTACK:");
        int i;
        for (i = q->f; i <= q->r; i++)
            printf("%d ", q->a[i]);
    }
    else
        printf("\nSTACK IS EMPTY !!!\n");
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
    struct queue *q1,*q2,*temp;
    q1 = (struct queue *)malloc(sizeof(struct queue));
    q2 = (struct queue *)malloc(sizeof(struct queue));
    temp=(struct queue *)malloc(sizeof(struct queue));
    create(q1);
    create(q2);
    while (1)
    {
        printf("\n==========================================================\n");
        printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            push(q1,input());
            break;
        case 2:
            pop(q1,q2);
            temp=q1;
            q1=q2;
            q2=temp;
            break;
        case 3:
            display(q1);
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