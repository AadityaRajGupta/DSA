#include <stdio.h>
#include <stdlib.h>

// Program to implement Linear search.

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
int main()
{
    head=(struct node *)malloc(sizeof(struct node));
    head->data=4;
    head->next=NULL;

    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(56);

    int num;
    printf("ENTER NUMBER WANT TO SEARCH:");
    scanf("%d",&num);
    printf("\n\nFOUND %d AT INDEX: %d\n\n",num,search(num));


    display();
    return 0;
}