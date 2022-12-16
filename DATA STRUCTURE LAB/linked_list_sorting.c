#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*head;

int insert(int data)
{
    struct node *add_node = (struct node *)malloc(sizeof(struct node));
    if(add_node==NULL)
    {
        printf("\n\nNOT ABLE TO ADD NEW NODE!!!\n\n");
        return 0;
    }
    add_node->data = data;
    add_node->next = NULL;

    struct node *temp = head;
    
    while (temp!=NULL)
    {
        temp = temp->next;
    }
    temp = add_node;
    return 0;
}
int display()
{
    struct node *temp = head;
    printf("LINKED LIST-->");
    while (temp)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
int sort()
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
int main()
{
    head=(struct node *)malloc(sizeof(struct node));
    // head->data=89;
    head->next=NULL;

    insert(46);
    insert(35);
    insert(12);
    insert(19);
    insert(73);
    insert(56);
    insert(34);

    display();

    sort();

    display();
    
    return 0;
}