#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *n1 = (struct node *) malloc (sizeof(struct node));
    n1->data=data;
    n1->left=NULL;
    n1->right=NULL;
    return n1;
}

void inorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        inorder_traversal(temp->left);
        printf("%d ",temp->data);
        inorder_traversal(temp->right);
    }
}
void preorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}
void postorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->data);
    }
}

int menu()
{
    printf("ADD ELEMENT TO LEFT:");

    
    printf("ADD ELEMENT TO RIGHT:");

}

int main()
{
    struct node *root = (struct node *) malloc (sizeof(struct node));
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);

    inorder_traversal(root);
    return 0;
}