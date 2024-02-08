// Program for Pre-Order, In-Order, Post-Order Traversal

#include "lab22_tree_00.h"

#define HELLO_TREE

// because these function are already declared in header file
#ifndef HELLO_TREE
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
#endif


int main()
{
    struct node *root;
    root=NULL;
    root=newnode_add(1);
    form_tree(&root);

    assert(root!=NULL);

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}
