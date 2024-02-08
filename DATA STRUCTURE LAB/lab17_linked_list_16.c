// Program for Finding the Middle element of a singly linked list in one pass

// double pointer ==> p - 1 step and q - 2 step when q -> last i.e p -> middle element print(p->data)
// one pointer + counter ==> same as above just no use two pointer

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

void middle_element_ll(struct node *start)
{
    struct node *mid,*temp;
    temp=start;
    mid=start;

    while(temp!=NULL && temp->next!=NULL)
    {
        mid=mid->next;
        temp=temp->next->next;
    }
    if(mid!=NULL)
        printf("\nMIDDLE ELEMENT: %d\n",mid->data);
}
void middle_element_ll_my_imple(struct node *start)
{
    struct node *mid,*temp;
    temp=start;
    mid=start;

    while(temp)
    {
        mid=mid->next;
        temp=temp->next->next;
        if( temp->next == NULL)
            temp=temp->next;
        else if( temp->next->next == NULL)
            temp=temp->next->next;
    }
    if(mid!=NULL)
        printf("\nMIDDLE ELEMENT: %d\n",mid->data);
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
    middle_element_ll(start1);

    free_all_node(&start1);
    return 0;
}
