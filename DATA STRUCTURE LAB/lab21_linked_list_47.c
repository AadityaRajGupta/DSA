// Program for Linked List implementation of Double Ended Queue

// using doubly linked list
// insertFront()
// insertRear() 
// deleteFront()
// deleteRear()

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node 
{
    int data;
    struct node *prev;
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
int display_queue(struct node *head)
{
    struct node *temp = head;
    printf("\nDOUBLE ENDED QUEUE--> ");
    while(temp)
    {
        printf(" %d -->", temp->data);
        temp=temp->next;
    }
    printf(" NULL\n");
}
int display(struct node *head)
{
    int flag=0;
    struct node *temp = head;
    struct node *tail=NULL;
    printf("\nFROM START:\n===========");
    printf("\nDOUBLY LINKED LIST--> ");
    while(temp)
    {
        if(flag==0)
            if(temp->next==NULL)
            {
                tail=temp;
                flag=1;
            }
        
        printf(" %d -->", temp->data);
        temp=temp->next;
    }
    printf(" NULL\n");

    printf("\nFROM END:\n=========");
    printf("\nDOUBLY LINKED LIST--> ");
    temp=tail;
    while (temp)
    {
        printf(" %d -->", temp->data);
        temp=temp->prev;
    }
    printf(" NULL\n");

}

void insert_front(struct node **start,struct node **last, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = *start;
    
    if(*start==NULL)
    {
        *last=newnode;
        *start=newnode;
    }
    else
    {
        (*start)->prev=newnode;
        *start=newnode;
    }
}
void insert_rear(struct node **start,struct node **last, int x)
{
    if (*start == NULL)
    {
        insert_front(&(*start),&(*last), x);
    }
    else
    {
        struct node *newnode;
        newnode = getnode();
        newnode->data = x;
        newnode->prev = *last;
        newnode->next = NULL;
        (*last)->next = newnode;
        (*last) = newnode;
    }
}
void delete_front(struct node **start,struct node **last)
{
    if(*start==NULL)
    {
        printf("\nQUEUE IS EMPTY!!!\n");
        return ;
    }
    struct node *temp;
    temp = *start;

    if(temp->next == NULL)
    {
        *start=NULL;
        *last=NULL;
        printf("\nELEMENT DELETED: %d\n",temp->data);
        free(temp);
        return ;
    }

    (*start)=(*start)->next;
    (*start)->prev=NULL;
    printf("\nELEMENT DELETED: %d\n",temp->data);
    free(temp);
}
void delete_rear(struct node **start,struct node **last)
{
    if(*last==NULL)
    {
        printf("\nQUEUE IS EMPTY!!!\n");
        return ;
    }
    struct node *temp;
    temp = *last;

    if(temp->prev == NULL)
    {
        *start=NULL;
        *last=NULL;
        printf("\nELEMENT DELETED: %d\n",temp->data);
        free(temp);
        return ;
    }

    (*last)=(*last)->prev;
    (*last)->next=NULL;
    printf("\nELEMENT DELETED: %d\n",temp->data);
    free(temp);
}

int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
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
    struct node *start,*last;
    start=NULL;
    last=NULL;

    printf("\nLinked List Implementaion of Queue:\n===================================\n\n");
    
    int choose;
    while(1)
    {
        printf("\n===================================================\n1. INSERTION AT FRONT\n2. INSERTION AT REAR\n3. DELETION FROM FRONT\n4. DELETION FROM REAR\n5. DISPLAY\n6. EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            insert_front(&start,&last,input());
            break;
        case 2:
            insert_rear(&start,&last,input());
            break;
        case 3:
            delete_front(&start,&last);
            break;
        case 4:
            delete_rear(&start,&last);
            break;
        case 5:
            display_queue(start);
            break;
        case 6:
            free_all_node(&start);
            return 0;
        default:
            printf("\n\nINVALID CHOICE!!!\n\n");
            break;
        }
    }
    return 0;
}

