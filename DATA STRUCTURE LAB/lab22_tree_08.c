// write a program or function to find the sum all nodes in a given binary tree.

#include "lab22_tree_00.h"

int sum_of_node(struct node *temp)
{
    if(temp!=NULL)
        return temp->data+sum_of_node(temp->left)+sum_of_node(temp->right);
    return 0;
}

int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);

    assert(root!=NULL);

    printf("\nSUM OF NODES: %d",sum_of_node(root));

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}