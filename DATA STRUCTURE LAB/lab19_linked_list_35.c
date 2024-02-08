// Program for Polynomial subtraction using Linked List

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int coff;
    int exp;
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
        printf(" %dx^%d-->", temp->coff,temp->exp);
        temp = temp->next;
    }
    printf(" NULL\n");
}
void inserbeg(struct node **start, int coff,int exp)
{
    struct node *newnode;
    newnode = getnode();
    newnode->coff = coff;
    newnode->exp = exp;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, int coff,int exp)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), coff, exp);
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
        newnode->coff = coff;
        newnode->exp = exp;
        newnode->next = NULL;
        ptr->next = newnode;
    }
}
int input_coff()
{
    int item;
    printf("ENTER COFFICIENT:");
    scanf("%d", &item);
    return item;
}
int input_exp()
{
    int item;
    printf("\nENTER EXPONENT:");
    scanf("%d", &item);
    return item;
}
void initialise_ll(struct node **start,char name)
{
    printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        inserend(&(*start),input_coff(),input_exp());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(*start));
}

// recursive approach: in which we directly print the information
void polynomial_subtraction_LL_recursive(struct node *start1,struct node *start2)
{
    if(start1==NULL && start2==NULL)
    {
        return ;
    }
    if(start1->exp==start2->exp )
    {
        printf(" %dx^%d-->", start1->coff-start2->coff,start1->exp);
        polynomial_subtraction_LL_recursive(start1->next,start2->next);
    }
    if(start1->exp > start2->exp )
    {
        printf(" %dx^%d-->", start1->coff,start1->exp);
        polynomial_subtraction_LL_recursive(start1->next,start2);
    }
    if(start1->exp < start2->exp )
    {
        printf(" %dx^%d-->", -1*(start2->coff),start2->exp);
        polynomial_subtraction_LL_recursive(start1,start2->next);
    }
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
// approach similar to merging of ll
void polynomial_subtraction_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;

    p=*start1;
    q=*start2;

    int c,e;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp>q->exp)
        {
            inserbeg(&(*start3),p->coff,p->exp);
            p=p->next;
        }
        else if (p->exp<q->exp)
        {
            inserbeg(&(*start3),(q->coff)*-1,q->exp);
            q=q->next;
        }
        else
        {
            c=p->coff-q->coff;
            inserbeg(&(*start3),c,p->exp);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserbeg(&(*start3),p->coff,p->exp);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserbeg(&(*start3),(q->coff)*-1,q->exp);
        q=q->next;
    }
    reverse_ll(&(*start3));
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
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1,'A');
    initialise_ll(&start2,'B');

    printf("\n\n\n");
    // polynomial_subtraction_LL(&start1,&start2,&start3);
    // printf("POLYNOMIAL SUBTRACTION:");
    // display(start3);

    printf("POLYNOMIAL SUBTRACTION:");
    printf("\nLINKED LIST--> ");
    polynomial_subtraction_LL_recursive(start1,start2);
    printf(" NULL");
    

    free_all_node(&start1);
    free_all_node(&start2);
    free_all_node(&start3);
    return 0;
}




