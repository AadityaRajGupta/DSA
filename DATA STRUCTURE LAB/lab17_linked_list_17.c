// Program to perform Binary Search on the Linked List

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

struct node *middle_element_ll(struct node *start,struct node *last)
{
    struct node *mid,*temp;
    mid=start;
    temp=start->next;

    while(temp)
    {
        temp=temp->next;
        if(temp!=NULL)
        {
            temp=temp->next;
            mid=mid->next;
        }
    }
    return mid;
}
int binary_search_ll(struct node *root,int num)
{
    struct node *start,*last,*mid;

    start=root;
    last=NULL;

    do{
        mid=middle_element_ll(start,last);

        if (num==mid->data)
            return 1;
        
        else if (num>mid->data)
            start=mid->next;

        else
            last=mid;
    }while(last!=NULL || last!=start);

    return 0;   
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
    printf("\nENTER DATA WANT TO SEARCH:\n");
    if(binary_search_ll(start1,input()))
        printf("\nFOUND");
    else
        printf("\nNOT FOUND");

    free_all_node(&start1);
    return 0;
}



