// Program to find leaf node Count in the Binary Tree

#include "lab22_tree_00.h"

int leaf_node_count(struct node *temp)
{
    if(temp!=NULL)
    {
        if(temp->left==NULL && temp->right==NULL)
            return 1;
        else
            return leaf_node_count(temp->left)+leaf_node_count(temp->right);
    }
    return 0;
}

int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);

    // root->left->left->left=newnode_add(8);
    // root->left->left->right=newnode_add(9);

    assert(root!=NULL);

    printf("\nLEAF NODE COUNT: %d",leaf_node_count(root));

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}