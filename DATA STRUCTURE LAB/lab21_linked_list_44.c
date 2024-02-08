// Program for Circular Doubly Linked List Primitive Operations

// Traversal
// Insertion
// Deletion 
// Search 
// Sort 

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
int count(struct node *last)
{
    struct node *temp = last->next;
    int count=0;
    do
    {
        count+=1;
        temp = temp->next;
    }
    while (temp!=last->next);
    return count;
}
int display(struct node *last)
{
    struct node *temp,*ptr;
    temp = last->next;
    printf("\nFROM START:\n===========");
    printf("\nCIRCULAR DOUBLY LINKED LIST -->");
    do
    {
        printf(" %d -->", temp->data);
        // printf("\nprev: %u and data:%u and temp: %u and next: %u\n",temp->prev,temp->data,temp,temp->next);
        temp = temp->next;
    }
    while (temp!=last->next);
    printf(" . . . . .\n\n");
    

    printf("\nFROM END:\n=========");
    printf("\nCIRCULAR DOUBLY LINKED LIST -->");
    ptr=temp->prev;
    do 
    {
        printf(" %d -->", ptr->data);
        ptr = ptr->prev;
    }while(ptr!=temp->prev);
    printf(" . . . . .\n\n");

    // printf(" \n");
    // printf(" %d -->", temp->data);
    // temp=temp->next;
    // printf(" %d ", temp->data);
    // temp=temp->next;
}
void insert_beginning(struct node **last,int x)
{
    struct node *ptr, *newnode;
    if (*last == NULL)
    {
        newnode = getnode();
        newnode->data = x;
        newnode->next = newnode;
        newnode->prev = newnode;
        (*last) = newnode;
    }
    else
    {
        newnode = getnode();
        newnode->data = x;
        newnode->prev = (*last);
        newnode->next = (*last)->next;
        (*last)->next = newnode;
    }
}
void insert_end(struct node **last, int x)
{
    struct node *newnode;
    if (*last == NULL)
    {
        insert_beginning(&(*last),x);
    }
    else
    {
        newnode = getnode();
        newnode->data = x;
        newnode->prev = (*last);
        newnode->next = (*last)->next;
        (*last)->next->prev=newnode;
        (*last)->next = newnode;
        (*last)=newnode;
    }
}
int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
}
// void initialise_circular_ll(struct node **last,char name)
void initialise_circular_ll(struct node **last)
{
    // printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        insert_end(&(*last),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    // display(*last);
    printf("\nNUMBER OF ELEMENT PRESENT IN CIRCULAR DOUBLY LINKED LIST: %d\n",count(*last));
}

int delete(struct node **last,int A)
{
    struct node *ptr,*temp;
    ptr=(*last)->next;

    do
    {
        if(ptr->next->data==A)
        {
            temp=ptr->next;
            ptr->next=temp->next;
            temp->next->prev=ptr;
            if(temp==*last)
                *last=ptr;
            free(temp);
            printf("DELETED SUCCESFULLY\n");
            return 0;
        }
        ptr=ptr->next;
    } while (ptr!=(*last)->next);
    printf("DATA NOT FOUND IN THE CIRCULAR DOUBLY LINKED LIST!!!\n");
    return 0;
}

int search(struct node *last,int A)
{
    struct node *ptr,*newnode;
    ptr=(last)->next;
    int count =0;
    do
    {
        count++;
        if(ptr->data==A)
        {
            printf("DATA FOUND AT %d POSITION\n",count);
            return 0;
        }
        ptr=ptr->next;
    } while (ptr!=(last)->next);
    printf("DATA NOT FOUND IN THE CIRCULAR LINKED LIST!!!\n");
    return 0;
}

void sort(struct node *last)
{
    struct node *i,*j,*start;
    start=last->next;
    i=start;
    do
    {
        j=start;
        do
        {
            if(i->data<=j->data)
            {
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
            

            j=j->next;
        } while (j!=start);

        i=i->next;
    } while (i!=start);
}

void free_all_node(struct node **last)
{
    struct node *temp,*start;
    start=(*last);
    (*last)=(*last)->next;
    start->next=NULL;

    while((*last)!=NULL)
    {
        temp=(*last);
        (*last)=(*last)->next;
        free(temp);
    }
}

int main()
{
    struct node *last1;
    last1=NULL;

    printf("\nCIRCULAR DOUBLY LINKED LIST:\n============================\n\n");
    
    initialise_circular_ll(&last1);
    printf("\n\n\nAFTER INSERTION:\n================\n");
    display(last1);

    printf("\n\n\n");
    int A;
    printf("ENTER NUMBER WANT TO SEARCH:");
    scanf("%d",&A);
    search(last1,A);

    
    printf("\n==========================================================\n\nENTER NUMBER WANT TO DELETE:");
    scanf("%d",&A);
    delete(&last1,A);

    display(last1);

    printf("\n==========================================================\n\nAFTER SORTING:\n===============\n");
    sort(last1);
    display(last1);

    free_all_node(&last1);
    return 0;
}

