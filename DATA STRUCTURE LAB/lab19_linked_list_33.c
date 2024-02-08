// Program to find out the substraction of two given link list

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};
int count(struct node *head)
{
    struct node *temp = head;
    int count=0;
    while (temp)
    {
        count+=1;
        temp = temp->next;
    }
    return count;
}
int display(struct node *head)
{
    struct node *temp = head;
    printf("\nLINKED LIST--> ");
    while (temp)
    {
        printf(" %d -->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
void inserbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, int x)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), x);
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
void initialise_ll(struct node **start,char name)
{
    printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        inserend(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(*start));
}

void reverse_ll(struct node **start)
{
    struct node *previous,*current,*forward;
    previous=NULL;
    current=*start;
    forward=(*start)->next;

    while (current!=NULL)
    {
        current->next=previous;

        previous=current;
        current=forward;
        if(forward!=NULL)
            forward=forward->next;
    }
    *start=previous;
}
// it take more cycle for the completion of program this can overcome by taking group of number two reduce the computation cycles
void subtraction_of_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    reverse_ll(&(*start1));
    reverse_ll(&(*start2));

    p=*start1;
    q=*start2;

    int diff=0,carry=0;
    while(p!=NULL && q!=NULL)
    {   
        diff=p->data-q->data-carry;
        if(diff<0)
        {
            diff=q->data;
            carry=1;
        }
        else
            carry=0;
        inserbeg(&(*start3),diff);
        p=p->next;
        q=q->next;
    }
    while(p!=NULL)
    {
        diff = p->data-carry;
        if (diff < 0)  carry=1; 
        else carry=0;

        inserbeg(&(*start3),diff);
        p=p->next;
    }
    while (q!=NULL)
    {
        diff = q->data-carry;
        if (diff < 0)  carry=1; 
        else carry=0;

        inserbeg(&(*start3),diff);
        q=q->next;
    }
}

void free_all_node(struct node **start)
{
    struct node *temp;
    while((*start)!=NULL)
    {
        temp=*start;
        *start=(*start)->next;
        free(temp);
    }
}
int main()
{
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1,'A');
    initialise_ll(&start2,'B');

    printf("\n\n\n");
    if(count(start1) < count(start2))
    {
        subtraction_of_LL(&start2,&start1,&start3);
        start3->data=(start3->data)*-1;
    }
    else 
        subtraction_of_LL(&start1,&start2,&start3);
    printf("SUBTRACTION OF TWO LINKED LIST:");
    display(start3);

    free_all_node(&start1);
    free_all_node(&start2);
    free_all_node(&start3);
    return 0;
}

