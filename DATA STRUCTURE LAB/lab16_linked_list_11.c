// Program for Merging two sorted Linked List/unsoted link list

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
    printf("\nLINKED LIST-->");
    while (temp)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
int sort(struct node *head)
{
    struct node *i,*j;
    i=head;
    while(i!=NULL)
    {
        j=head;
        while(j!=NULL)
        {
            if (i->data<=j->data)
            {
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

// reserve karke starting me bhi add kar sakte hai phir insertion O(N) then reverse O(N) overall O(N) else this method take O(N^2)
// Reversing the Linear Linked List
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
void merge_ll(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    p=*start1;
    q=*start2;

    while (p!=NULL && q!=NULL)
    {
        if (p->data<=q->data)
        {
            inserbeg(&(*start3),p->data);
            p=p->next;
        }
        else
        {
            inserbeg(&(*start3),q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserbeg(&(*start3),p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserbeg(&(*start3),q->data);
        q=q->next;
    }
    reverse_ll(&(*start3));
}   
/* this take O(N^2)
void merge_ll(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    p=*start1;
    q=*start2;

    while (p!=NULL && q!=NULL)
    {
        if (p->data<=q->data)
        {
            inserend(&(*start3),p->data);
            p=p->next;
        }
        else
        {
            inserend(&(*start3),q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserend(&(*start3),p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserend(&(*start3),q->data);
        q=q->next;
    }
}   */

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
    // sort(start1);
    // sort(start2);
    merge_ll(&start1,&start2,&start3);
    display(start3);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n\n\n",count(start3));

    free_all_node(&start1);
    free_all_node(&start2);
    free_all_node(&start3);
    return 0;
}
