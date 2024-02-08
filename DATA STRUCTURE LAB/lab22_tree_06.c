// Program to find count of nodes having 2 children

#include "lab22_tree_00.h"

int count_node_have_2_child(struct node *temp)
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
                return count_node_have_2_child(temp->left)+count_node_have_2_child(temp->right)+1;
            // degree one node
            else
                return count_node_have_2_child(temp->left)+count_node_have_2_child(temp->right);
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

    assert(root!=NULL);

    printf("\nCOUNT OF NODES HAVING 2 CHILD: %d",count_node_have_2_child(root));

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}