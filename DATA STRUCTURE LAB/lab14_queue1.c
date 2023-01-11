#include <stdio.h>
#include <stdlib.h>

//Program for Array Implementation of Priority Queue (Ascending Array)

#define size 5

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
    if (q->r==-1)
        return 1;
    return 0;
}
int isfull()
{
    if (q->r == size - 1)
        return 1;
    return 0;
}
void priority()
{
    int i,j;
    int item=q->a[q->r];
    for(i=q->r-1;i>=0;i--)
    {
        if (q->a[i] > item)
        {
            q->a[i + 1] = q->a[i];
            q->a[i]=item;
        }
    }
}

// first insertion pe dono zero(0) kar denge or f=0 and r tho increment karke insert kar hi raha hai

void insertion(int item)
{
    if (!isfull())
    {
        if (q->r==-1)
            q->f=0;

        q->a[++q->r] = item;

        priority();
    }
    else
        printf("\nQUEUE IS FULL!!!\n");
}

// hum f kho insertion baad hi 0 pe le aae the tho uss index ka element delete karga phir increment kardega 
// jub r==f tho ake hi element hai array me tho usse delete karke reset kar denge r = f = -1 .
void deletion()
{
    if (!isempty())
    {
        printf("\nDELETED ELEMENT: %d", q->a[q->f]);
        if(q->f==q->r)
            create();
        q->f++;
    }
    else
        printf("\nQUEUE IS EMPTY!!!");
}
void display()
{
    if (!isempty())
    {
        printf("\n\nQUEUE:");
        int i;
        for (i = q->f; i <= q->r; i++)
            printf("%d ", q->a[i]);
    }
    else
        printf("\nQUEUE IS EMPTY!!!");
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
        printf("\n==========================================================\n");
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