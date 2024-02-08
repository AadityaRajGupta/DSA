// Program for Linked List Implementaion of Queue

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
    printf("\nQUEUE--> ");
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
void insertion(struct node **start, int x)
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
int deletion(struct node **start)
{
    if((*start) == NULL)
    {
        printf("\nQUEUE IS EMPTY!!!\n");
        return 0;
    }
    struct node *temp;
    temp=*start;
    (*start)=(*start)->next;
    printf("\nELEMENTED DELETED: %d \n",temp->data);
    free(temp);
    return 0;
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
    struct node *start1;
    start1=NULL;

    printf("\nLinked List Implementaion of Queue:\n===================================\n\n");
    
    int choose;
    while(1)
    {
        printf("\n1. INSERTION\n2. DELETION\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            insertion(&start1,input());
            break;
        case 2:
            deletion(&start1);
            break;
        case 3:
            display(start1);
            break;
        case 4:
            free_all_node(&start1);
            return 0;
        default:
            printf("\n\nINVALID CHOICE!!!\n\n");
            break;
        }
    }
    return 0;
}
