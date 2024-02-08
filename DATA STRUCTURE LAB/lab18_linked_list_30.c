// Program to Delete kth node from end of a linked list in a single scan and O(n) time

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

/*slow and fast pointer approach is simple to implement 
        first traverse fast to k times 
        and now start both pointer till fast reach end 
        then slow pointer will we at kth node from end 
*/
// recursive approach 
int delete_Kth_element_from_end(struct node *start,int k)
{
    if (!start)
        return k;
    k=delete_Kth_element_from_end(start->next, k);
    k -= 1;
    if (k == -1)
    {
        struct node *temp = start->next;
        printf(" %d ",temp->data);
        start->next = start->next->next;
        free(temp);
    }
    return k;
}
struct node *remove_Nth_Node_From_End(struct node *start, int n)
{
    if (!start || !start->next)
    {
        printf(" %d ",start->data);
        printf("\n\nLINKED LIST HAD ONLY ONE NODE NOW DELETED!!!\n");
        return NULL;
    }

    struct node *newnode;
    newnode = getnode();
    newnode->next = start;

    delete_Kth_element_from_end(newnode, n);

    return newnode->next;
}
/* one node and k = 1 edge case (fails)
int delete_Kth_element_from_end(struct node *start,int k)
{
    struct node *temp;
    temp=start;

    if (temp->next != NULL)
    {
        int count = delete_Kth_element_from_end(temp->next, k) + 1;
        if (count == k)
            printf(" %d ", temp->data);
        if (count == k+1)
            temp->next=temp->next->next;
        return count;
    }
    else
        return 1;
    return 0;
}*/



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
    start1=remove_Nth_Node_From_End(start1,k);
    display(start1);

    free_all_node(&start1);
    return 0;
}



