// Program to Detect if there is ay cycle in the linked list, starting point of cycle, length of cycle

// checks whether a given Linked List contains a loop eg: 1-> 2 -> 3 -> 4 -> 2  this is loop and loop head is 2

// Floyd’s loop detection algorithm.

/* for checking loop or head also
https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
1. Hashing

2. Modification In Node Structure

3. Floyd’s Cycle-Finding Algorithm

4. Marking visited nodes without modifying Node structure (i.e pointing each node->next to temp created node)

5. Storing length (current no of nodes > previous no of nodes if false than we reached end of loop return)(first pointer and last pointer and calculate distance between than each time)  O(N^2)

6. Modifying Value (means data value change say -1)

*/

/* for head of loop:
Distance traveled by fast pointer = 2 * (Distance traveled by slow pointer)
                    (m + n*x + k) = 2*(m + n*y + k)

Note: that before meeting the point shown above, fast was moving at twice speed.

x -->  Number of complete cyclic rounds made by fast pointer before they meet first time
y -->  Number of complete cyclic rounds made by slow pointer before they meet first time

From the above equation, we can conclude below:
    m + k = (x-2y)*n
Which means m+k is a multiple of n.

So if we start moving both pointers again at the same speed such that one pointer (say slow) begins from the head node of the linked list and other pointers (say fast) begins from the meeting point. When the slow pointer reaches the beginning of the loop (has made m steps), the fast pointer would have made also moved m steps as they are now moving the same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No, because the slow pointer enters the cycle first time after m steps.
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

int loop_check(struct node *start)
{
    struct node *first,*second;
    first=start;
    second=start;

    while(second!=NULL && second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
        if(first==second)
            return 1;
    }
    return 0;
}
int count_loop(struct node *start,struct node *last)
{
    int count=0;
    while(start!=last)
    {
        count++;
        start=start->next;
    }
    return count;
}
struct node *loop_head(struct node *head)
{
    struct node *start,*lp_h,*temp;
    start=head;
    temp=head;

    int current_count=0;
    int previous_count=0;
    int length=0;

    if(loop_check(start))
    {
        while(temp!=NULL)
        {
            current_count=count_loop(start,temp->next);
            previous_count=count_loop(start,temp);

            if(previous_count>current_count)
            {
                lp_h=temp->next;
                length=previous_count-current_count+1;
                break;
            }
            temp=temp->next;
        }
        printf("\nLOOP HEAD: %d\n",lp_h->data);
        printf("LENGTH OF LOOP: %d",length);
        return lp_h;
    }
    else
    {
        printf("\nNO LOOP EXIST !!!\n");
        return NULL;
    }
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
    struct node *start1,*start2,*temp;
    start1=NULL;
    start2=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1);
    temp=start1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=start1->next->next->next;
    // printf("%d ",temp->next->data);
    // display(temp);   // infinite loop

    printf("\n\n\n");
    start2=loop_head(start1);

    
    if(start2!=NULL)
    {
        printf("\nLOOP : ");
        printf(" %d ",start2->data);

        temp=start2->next;
        while(temp!=start2)
        {
            printf("--> %d ",temp->data);
            temp=temp->next;
        }
    }
    
    free_all_node(&start1);
    free_all_node(&start2);
    return 0;
}



