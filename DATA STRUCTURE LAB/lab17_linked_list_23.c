// Program for finding if the given link list is palindrome or not

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
int palindrome(struct node *start)
{
    struct node *mid,*temp;

    temp=start;
    mid=start;

    while(temp!=NULL && temp->next!=NULL)
    {
        mid=mid->next;
        temp=temp->next->next;
    }

    reverse_ll(&mid);

    temp=start;
    while(mid)
    {
        if(mid->data!=temp->data)
            return 0;

        mid=mid->next;
        temp=temp->next;
    }
    return 1;
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
    if(palindrome(start1))
        printf("Palindrome\n\n");
    else
        printf("Not palindrome\n\n");
    
    free_all_node(&start1);
    return 0;
}




