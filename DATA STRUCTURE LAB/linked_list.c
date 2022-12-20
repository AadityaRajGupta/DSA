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
    
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = add_node;
    return 0;
}
int delete(int num)
{
    struct node *temp = head;
    while (temp->next->data!=num && temp!=NULL)
    {
        temp = temp->next;
    }
    temp->next=temp->next->next;
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
int count()
{
    struct node *temp = head;
    int count=0;
    while (temp)
    {
        count+=1;
        temp = temp->next;
    }
    printf("\nCOUNT: %d\n",count);
    return 0;
}
int search(int num)
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
    head->data=89;
    head->next=NULL;

    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(56);

    display();

    int num=8;
    count();
    printf("\n\nFOUND %d AT INDEX: %d\n\n",num,search(num));

    delete(7);

    display();
    return 0;
}