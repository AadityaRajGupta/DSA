// Program to implement Linear search.

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
void initialise_ll(struct node **start,char name)
{
    printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        inserend(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(*start));
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
int main()
{
    struct node *start1;
    start1=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1,'A');
    
    int num;
    printf("\n\nENTER NUMBER WANT TO SEARCH IN LINKED LIST: ");
    scanf("%d",&num);
    printf("\nFOUND %d AT INDEX: %d\n\n",num,search(start1,num));

    free_all_node(&start1);
    return 0;
}


