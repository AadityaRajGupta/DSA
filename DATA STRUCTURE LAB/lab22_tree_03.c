// Program to find Node Count in the Binary Tree

#include "lab22_tree_00.h"

int node_count(struct node *temp)
{
    if(temp!=NULL)
        return node_count(temp->left)+node_count(temp->right)+1;
    return 0;
}

int main()
{
    struct node *root;
    root=NULL;
    predefine_tree(&root);

    assert(root!=NULL);

    printf("\nNODE-COUNT: %d",node_count(root));
    printf("\n\nINORDER TRAVERSAL: ");
    inorder_traversal(root);
    
    free_all_nodes(&root);
    return 0;
}
