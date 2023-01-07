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
struct node *insert(struct node *root,int data)
{
    if (root==NULL)
        return newnode(data);
    if(root->data<data)
        root->right=insert(root->right,data);
    else if (root->data<data)
        root->left=insert(root->left,data);
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


int max_a(int a,int b)
{
    return (a>b) ? a : b;
}
int height(struct node *hello)
{
    if(hello!=NULL)
        return max_a(height(hello->left),height(hello->right))+1;
}

// time : O(n)    auxiliary space : O(h)
int size(struct node *demo)
{
    if (demo!=NULL)
        return size(demo->left)+size(demo->right)+1;
}

int node_sum(struct node *temp)
{
    if (temp!=NULL)
        return temp->data+node_sum(temp->right)+node_sum(temp->left);
}

// count no. of nodes 1 child 
int count_one(struct node* ratsasan)
{
    if (ratsasan==NULL)
        return 0;
    else
    {
        if (ratsasan->left!=NULL && ratsasan->right==NULL)
            return count_one(ratsasan->left)+1;
        else if (ratsasan->left==NULL && ratsasan->right!=NULL)
            return count_one(ratsasan->right)+1;
        return count_one(ratsasan->left)+count_one(ratsasan->right);
    }
}

int count_two(struct node* ratsasan)
{
    if (ratsasan==NULL)
        return 0;
    else
    {
        if (ratsasan->left!=NULL && ratsasan->right!=NULL)
            return count_two(ratsasan->left)+count_two(ratsasan->right)+1;
    }
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

    printf("\n\nHEIGHT: %d",height(root));

    printf("\n\nSIZE: %d",size(root));

    printf("\n\nSUM: %d",node_sum(root));

    printf("\n\nNO OF NODES HAVING 1 CHILD: %d",count_one(root));

    printf("\n\nNO OF NODES HAVING 2 CHILD: %d",count_two(root));
    
    return 0;
}