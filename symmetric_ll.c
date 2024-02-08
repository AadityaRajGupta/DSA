#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node 
{
    int data;
    struct node *next;
};

int display(struct node *head)
{
    struct node *temp = head;
    while (temp)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertion_at_start(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void insert_at_end(struct node **start, int x)
{
    if (*start == NULL)
    {
        insertion_at_start(&(*start), x);
    }
    else
    {
        struct node *newnode, *ptr;
        ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newnode = getnode();
        newnode->data = x;
        newnode->next = NULL;
        ptr->next = newnode;
    }
}
int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
}
void initialise_ll(struct node **start)
{
    int choose=0;
    do{
        insert_at_end(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);
}
void symmetric_difference_ll(struct node *start1,struct node *start2,struct node **start3)
{
    struct node *p,*q;
    p=start1;
    q=start2;

    while (p!=NULL && q!=NULL)
    {
        if (p->data<q->data)
        {
            insert_at_end(&(*start3),p->data);
            p=p->next;
        }
        else if (p->data == q->data)
        {
            q=q->next;
            p=p->next;
        }
        else
        {
            insert_at_end(&(*start3),q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insert_at_end(&(*start3),p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        insert_at_end(&(*start3),q->data);
        q=q->next;
    }
}   

int main()
{
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;
    
    printf("set1:\n");
    initialise_ll(&start1);
    printf("\n\nset2:\n");
    initialise_ll(&start2);

    printf("\nSymmetric Difference:");
    symmetric_difference_ll(start1,start2,&start3);
    display(start3);

    return 0;
}
