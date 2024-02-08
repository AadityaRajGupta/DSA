// Program to remove all Fibonacci Nodes from a Circular Singly Linked List

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

int max_from_node(struct node *last)
{
    struct node *temp = last->next;
    int max=INT_MIN;
    do
    {
        if(max<temp->data)
            max=temp->data;

        temp = temp->next;
    }while (temp!=last->next);
    return max;
}
int dat[100];
int fibonaaci(int max_num)
{
    int prev,curr,temp,i;
    prev=0;
    curr=1;

    dat[0]=0;
    dat[1]=1;
    i=2;
    while (dat[i-1]<=max_num)
        dat[i++]=dat[i-1]+dat[i-2];

    // for(int j=0;j<i;j++)
    //     printf("%d ",dat[j]);

    return i;
}
int check_fibonaaci(int num,int i)
{
    for(int j=0;j<i;j++)
        if(dat[j]==num)
            return 1;

    return 0;
}
int delete(struct node **last,struct node *hello)
{
    struct node *temp,*prev;
    if((*last)->next==hello)
    {
        temp=(*last)->next;
        (*last)->next=temp->next;
        free(temp);
        return 0;
    }

    prev=(*last);
    temp=(*last)->next;
    do{
        if(temp==hello)
        {
            if(hello==(*last))
                *last=(*last)->next;
            prev->next=temp->next;
            free(temp);
            return 0;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=(*last)->next);
    return 0;
}
void remove_fibonacci_nodes(struct node **last)
{
    int i=fibonaaci(max_from_node(*last));

    struct node *temp,*del;
    temp=(*last)->next;
    do
    {
        while(check_fibonaaci(temp->data,i))
        {
            del=temp;
            temp=temp->next;
            delete(&(*last),del);
        }
        temp=temp->next;
    } while (temp!=(*last)->next);
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
    remove_fibonacci_nodes(&last1);
    display(last1);

    free_all_node(&last1);
    return 0;
}
