// Program for implementation of Josephus Problem

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
void Josephus_program(struct node **last,int k)
{
    int count = 0;
    struct node *temp,*del;
    temp=(*last)->next;

    while(temp!=temp->next)
    {
        count++;
        if(count==k)
        {
            count=0;
            del=temp;
            temp=temp->next;
            printf("\ndel:%d \n",del->data);
            delete(&(*last),del);
            // display(*last);
        }
        else
            temp=temp->next;
        
        // if(temp==temp->next)
        //     return;
    }
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
    int k;
    printf("ENTER THE VALUE OF K:");
    scanf("%d",&k);
    Josephus_program(&last1,k);
    display(last1);

    free_all_node(&last1);
    return 0;
}

