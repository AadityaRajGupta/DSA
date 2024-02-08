// Program to find if the given Binary Tree is strictly

#include "lab22_tree_00.h"

int strictly_binary_tree(struct node *temp)
{
    if (temp != NULL)
    {
        // degree zero node
        if (temp->left == NULL && temp->right == NULL)
            return 1;
        else
        {
            // degree two node
            if (temp->left != NULL && temp->right != NULL)
                return strictly_binary_tree(temp->left) + strictly_binary_tree(temp->right)+1;
        }
    }
    return 0;
}

int strictly_binary_tree_without_count(struct node *root)
{
    if (root==NULL)
        return 1;
    
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    if(root->left!=NULL && root->right!=NULL)
        return (strictly_binary_tree_without_count(root->left) & strictly_binary_tree_without_count(root->right));

    return 0;
}

int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);
    root->left->left->left=newnode_add(10);

    assert(root!=NULL);

    // if(size(root)==strictly_binary_tree(root))
    if(strictly_binary_tree_without_count(root))
    {
        printf("\nSTRICTLY BINARY TREE");
    }
    else
        printf("\nNOT STRICTLY BINARY TREE");

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}
