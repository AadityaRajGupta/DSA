// Program for reversing the Circular Linked List

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
};
int count(struct node *last)
{
    struct node *temp = last->next;
    int count=0;
    do
    {
        count+=1;
        temp = temp->next;
    }
    while (temp!=last->next);
    return count;
}
int display(struct node *last)
{
    struct node *temp = last->next;
    printf("\nCIRCULAR LINKED LIST -->");
    do
    {
        printf(" %d -->", temp->data);
        temp = temp->next;
    }
    while (temp!=last->next);
    printf(" . . . . .\n\n");
    return 0;

    // printf(" \n");
    // printf(" %d -->", temp->data);
    // temp=temp->next;
    // printf(" %d ", temp->data);
    // temp=temp->next;
}
void insert_beginning(struct node **last,int x)
{
    struct node *ptr, *newnode;
    if (*last == NULL)
    {
        newnode = getnode();
        newnode->data = x;
        (*last) = newnode;
        newnode->next = (*last);
    }
    else
    {
        newnode = getnode();
        newnode->data = x;
        newnode->next = (*last)->next;
        (*last)->next = newnode;
    }
}
void insert_end(struct node **last, int x)
{
    struct node *newnode;
    if (*last == NULL)
    {
        insert_beginning(&(*last),x);
    }
    else
    {
        newnode = getnode();
        newnode->data = x;
        newnode->next = (*last)->next;
        (*last)->next = newnode;
        (*last)=newnode;
    }
}
int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
}
// void initialise_circular_ll(struct node **last,char name)
void initialise_circular_ll(struct node **last)
{
    // printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        insert_end(&(*last),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*last);
    printf("\nNUMBER OF ELEMENT PRESENT IN CIRCULAR LINKED LIST: %d\n",count(*last));
}

void reverse_circular_LL(struct node **last)
{
    struct node *prev,*curr,*forw;
    prev=*last;
    curr=(*last)->next;
    forw=curr->next;
    do
    {
        curr->next=prev;

        // printf("\n============\n%d --> %d forw:%d   \n",curr->data,prev->data,forw->data);
        
        prev=curr;
        curr=forw;
        forw=forw->next;
    }while(curr!=(*last));
    curr->next=prev;
    (*last)=forw;
}

void free_all_node(struct node **last)
{
    struct node *temp,*start;
    start=(*last);
    (*last)=(*last)->next;
    start->next=NULL;

    while((*last)!=NULL)
    {
        temp=(*last);
        (*last)=(*last)->next;
        free(temp);
    }
}
int main()
{
    struct node *last1;
    last1=NULL;

    printf("\nCIRCULAR LINKED LIST:\n=====================\n\n");
    
    initialise_circular_ll(&last1);

    printf("\n\n\n");
    reverse_circular_LL(&last1);
    display(last1);

    free_all_node(&last1);
    return 0;
}
