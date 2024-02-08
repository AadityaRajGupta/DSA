// Program for implementation of Header Linked List

// using header node to store the length of linked list 
// many other think can be done like max element, min element, 

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
    temp=temp->next;
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
    struct node *newnode,*headernode;
    headernode = getnode();
    newnode = getnode();

    headernode->data=1;
    headernode->next=newnode;
    newnode->data = x;
    newnode->next = *start;
    *start = headernode;
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

        ptr->data++;
        ptr=ptr->next;

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
        inserend(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n\n",(*start)->data);
}

void deletion(struct node **start)
{
    struct node *temp,*del;
    temp=*start;
    temp->data--;
    temp=temp->next;
    while(temp->next->next)
        temp=temp->next;

    del=temp->next;
    temp->next=NULL;
    printf("\nELEMENT DELETED: %d\n",del->data);
    free(del);
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

    printf("\nHEADER LINKED LIST:\n===================\n\n");
    
    initialise_ll(&start1);

    deletion(&start1);
    deletion(&start1);
    deletion(&start1);
    deletion(&start1);
    deletion(&start1);

    display(start1);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n\n",start1->data);

    free_all_node(&start1);
    return 0;
}

