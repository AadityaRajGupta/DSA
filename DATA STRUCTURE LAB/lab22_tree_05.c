// Program to find count of nodes having 1 child

#include "lab22_tree_00.h"

int count_node_have_1_child(struct node *temp)
{
    if(temp!=NULL)
    {
        // degree zero node
        if(temp->left==NULL && temp->right==NULL)
            return 0;
        else
        {
            // degree two node
            if(temp->left!=NULL && temp->right!=NULL)
                return count_node_have_1_child(temp->left)+count_node_have_1_child(temp->right);
            // degree one node
            else
                return count_node_have_1_child(temp->left)+count_node_have_1_child(temp->right)+1;
        }
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
    root->left->left->left=newnode_add(8);
    root->right->right->right=newnode_add(9);

    assert(root!=NULL);

    printf("\nCOUNT OF NODES HAVING 1 CHILD: %d",count_node_have_1_child(root));
    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}