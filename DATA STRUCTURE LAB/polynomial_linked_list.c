#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coff;
    int power;
    struct node *right;
    struct node *left;
};

int insertion(struct node *start)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->right=NULL;
    newnode->left=NULL;

    int c,p;
    printf("Enter coefficient and degree:");
    scanf("%d%d",&c,&p);
    newnode->coff=c;
    newnode->power=p;

    struct node *temp;
    temp=start;
    if (temp==NULL)
        temp=newnode;
    else
    {
        while(temp->right)
            temp=temp->right;
        newnode->left=temp;
        temp->right=newnode;
    }
    return 0;
}

int display(struct node *start)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp=start;
    printf("FORWARD ORDER:");
    while(temp)
    {
        printf("%d %d",temp->coff,temp->power);
        temp=temp->right;
    }

    printf("\n\nREVERSE ORDER:");
    temp=temp->left;
    while(temp)
    {
        printf("%d %d",temp->coff,temp->power);
        temp=temp->left;
    }
    return 0;
}

int main()
{
    struct node *start=NULL;
    insertion(start);
    insertion(start);
    insertion(start);
    display(start);
    return 0;

}