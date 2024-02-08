// Program for concatenation of Circular Linked List
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
void initialise_circular_ll(struct node **last,char name)
// void initialise_circular_ll(struct node **last)
{
    printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        insert_end(&(*last),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*last);
    printf("\nNUMBER OF ELEMENT PRESENT IN CIRCULAR LINKED LIST: %d\n",count(*last));
}

void concatenate(struct node **last1,struct node **last2)
{
    struct node *temp;
    temp=(*last1)->next;
    (*last1)->next=(*last2)->next;
    (*last2)->next=temp;
}

void concatenation__circular_LL(struct node *last1,struct node *last2,struct node **last3)
{
    struct node *temp;
    temp=last1->next;
    do
    {
        insert_end(&(*last3),temp->data);
        temp=temp->next;
    } while (temp!=last1->next);

    temp=last2->next;
    do 
    {
        insert_end(&(*last3),temp->data);
        temp=temp->next;
    }while(temp!=last2->next);
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
    struct node *last1,*last2,*last3;
    last1=NULL;
    last2=NULL;
    last3=NULL;

    printf("\nCIRCULAR LINKED LIST:\n=====================\n\n");
    
    initialise_circular_ll(&last1,'A');
    initialise_circular_ll(&last2,'B');

    printf("\n\n\n");
    concatenation__circular_LL(last1,last2,&last3);
    display(last3);

    // concatenate(&last1,&last2);
    // display(last1);
    // display(last2);
    // // free_all_node(&last1); comment karna hai ye kyuki main pointer last2 wala hai ab

    free_all_node(&last1);
    free_all_node(&last2);
    free_all_node(&last3);
    return 0;
}
