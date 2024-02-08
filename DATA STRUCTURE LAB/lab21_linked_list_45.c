// Program for Linked List Implementation of Stacks

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
    printf("\nSTACK--> ");
    while (temp)
    {
        printf(" %d -->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
void push(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
int pop(struct node **start)
{
    if((*start) == NULL)
    {
        printf("\nSTACK IS EMPTY!!!\n");
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

    printf("\nLinked List Implementation of Stacks:\n=====================================\n\n");
    
    int choose;
    while(1)
    {
        printf("\n\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            push(&start1,input());
            break;
        case 2:
            pop(&start1);
            break;
        case 3:
            display(start1);
            break;
        case 4:
            free_all_node(&start1);
            return 0;
        default:
            printf("\n\nINVALID CHOICE\n\n");
            break;
        }
    }
    return 0;
}




