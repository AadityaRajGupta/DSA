// Program for Linked List Implementaion of Priority Queue

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
        if(ptr->data<x)
            inserbeg(&(*start),x);
        else
        {
            while (ptr->next != NULL && ptr->next->data > x)
            {
                ptr = ptr->next;
            }
            newnode = getnode();
            newnode->data = x;
            if (ptr->next == NULL)
                newnode->next = NULL;
            else
                newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
    display(*start);
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
        inserend(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(*start));
}

void delete_beg(struct node **start)
{
    struct node *temp;
    int num;
    num=(*start)->data;

    temp=(*start);
    (*start)=(*start)->next;
    free(temp);

    printf("\n\nELEMENTED DELETED: %d",num);
    // return num;
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
    struct node *start1;
    start1=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1);

    printf("\n\n\n");
    delete_beg(&start1);
    display(start1);
    delete_beg(&start1);
    display(start1);
    delete_beg(&start1);
    display(start1);
    delete_beg(&start1);
    display(start1);

    free_all_node(&start1);
    return 0;
}



