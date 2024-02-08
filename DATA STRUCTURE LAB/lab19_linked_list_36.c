// Program for Polynomial Multiplication using Linked List

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
        // if(temp->exp==0)
        //     printf(" %d-->", temp->coff);
        // else
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

int dat[101];
void free_all_node(struct node **start);
void polynomial_multiplication_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;

    p=*start1;
    q=*start2;

    int c,e;
    while (p!=NULL)
    {
        q=*start2;
        while(q!=NULL)
        {
            c=p->coff*q->coff;
            e=p->exp+q->exp;
            inserbeg(&(*start3),c,e);
            q=q->next;
        }
        p=p->next;
    }

    struct node *temp;
    temp=*start3;
    e=0;
    while(temp)
    {
        if(temp->exp>e)
            e=temp->exp;

        if(dat[temp->exp]==0)
            dat[temp->exp]=temp->coff;
        else
            dat[temp->exp]=dat[temp->exp] + temp->coff;
        temp=temp->next;
    }

    free_all_node(&(*start3));

    for(int i=0;i<=e;i++)
    {
        if(dat[i]!=0)
            inserbeg(&(*start3),dat[i],i);
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
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    
    initialise_ll(&start1,'A');
    initialise_ll(&start2,'B');

    printf("\n\n\n");
    polynomial_multiplication_LL(&start1,&start2,&start3);
    printf("POLYNOMIAL MULTIPLICATION:");
    display(start3);    

    free_all_node(&start1);
    free_all_node(&start2);
    free_all_node(&start3);
    return 0;
}





