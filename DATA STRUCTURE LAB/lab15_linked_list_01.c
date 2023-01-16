// Program for Linear Linked List Primitive operations

// Traversal
// Insertion
// Deletion 
// Search - 
// Sort 

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
    printf("\nLINKED LIST-->");
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
void deletion(struct node **start,int index)
{
    struct node *temp = *start;
    int count=-1;
    while (temp)
    {
        count+=1;
        if ((count+1)==index)
        {
            temp->next=temp->next->next;
            break;
        }
        temp = temp->next;
    }   
}
int search(struct node *head,int num)
{
    struct node *temp = head;
    int count=-1;
    while (temp)
    {
        count+=1;
        if(temp->data==num)
            return count;
        temp = temp->next;
    }
    return -1;
}
int sort(struct node *head)
{
    struct node *i,*j;
    i=head;
    while(i!=NULL)
    {
        j=head;
        while(j!=NULL)
        {
            if (i->data<=j->data)
            {
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}
int input()
{
    int item;
    printf("ENTER ANY NUMBER:");
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
    struct node *start;
    start=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    inserend(&start,input());
    inserend(&start,input());
    inserend(&start,input());
    inserend(&start,input());

    printf("\n\n\nAFTER INSERTION:\n================\n");
    display(start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(start));
    

    printf("\n\n\nAFTER DELETING 2nd INDEX ELEMENT:\n==================================\n");
    deletion(&start,2);
    display(start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n\n\n",count(start));
    

    int num;
    printf("\n\nENTER NUMBER WANT TO SEARCH IN LINKED LIST: ");
    scanf("%d",&num);
    printf("\nFOUND %d AT INDEX: %d\n\n",num,search(start,num));

    sort(start);
    printf("\n\nAFTER SORTING:\n===============\n");
    display(start);
    printf("\n\n");

    free_all_node(&start);
    return 0;
}
