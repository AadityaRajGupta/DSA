// Program to find kth node from the last in a single link list

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

int print_Kth_element_from_end(struct node *start,int k)
{
    // reverse karke bhi kar sakte hai
    struct node *temp;
    temp=start;

    if (temp->next != NULL)
    {
        int count = print_Kth_element_from_end(temp->next, k) + 1;
        if (count == k)
            printf(" %d ", temp->data);
        return count;
    }
    else
        return 1;
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
    int k;
    printf("\nENTER THE VALUE OF K: ");
    scanf("%d",&k);
    printf("[%d]th NODE DATA FROM THE LAST: ",k);
    k=print_Kth_element_from_end(start1,k);
    if(k==1)
    {
        printf(" %d ",start1->data);
        printf("\n\nLINKED LIST HAD ONLY ONE NODE NOW DELETED!!!\n");
        start1=start1->next;
    }
    

    free_all_node(&start1);
    return 0;
}
