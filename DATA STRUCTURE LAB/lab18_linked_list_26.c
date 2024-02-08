// Program to find the Merging point in the linked list

/*
1. double loop and check for first appreance in the next linked list

2. node change added key

3. len count of 1 and 2; take difference(c) and traverse the longest list c times and start both pointer and check for intersection.

4. make the first LL a loop and treat second LL as finding loop problem and solve the problem ... traverse the second LL as the length of first LL and start both from that point and find the interestion.

5.  use hashing

6. two pointer approach: 
    ptr1 -> head1 (if null) ptr1-> head2
    ptr2 -> head2 (if null) ptr2-> head1 
    (ptr1==ptr2) => merging point

7. 2 stack: PUSH LL1 elements to stack 1
            and LL2 elements to stack 2 
            if both top are not equal no intersection 
            else 
                if (top value same pop) and store to INTERESECTION
                else return INTERSECTION
*/

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

void detect_merging_point(struct node *start1,struct node *start2)
{
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    
    while(ptr1!=ptr2)
    {
        if (ptr1==NULL)
            ptr1=start2;
        if (ptr2==NULL)
            ptr2=start1;
        
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(ptr1==ptr2)
        printf("MERGING POINT IN THE LINKED LIST: %d",ptr1->data);
    else 
        printf("NO MERGING POINT EXIST !!!");    
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
    struct node *start1,*start2;
    start1=NULL;
    start2=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1,'A');
    initialise_ll(&start2,'B');

    struct node *temp;
    temp=start2;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=start1->next->next->next;

    printf("\n\nA: ");
    display(start1);
    printf("B: ");
    display(start2);

    printf("\n\n");
    detect_merging_point(start1,start2);

    free_all_node(&start1);
    free_all_node(&start2);
    return 0;
}



