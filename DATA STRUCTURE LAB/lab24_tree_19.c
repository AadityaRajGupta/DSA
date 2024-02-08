// wrirte a program to check the two given binary tree is identical or not(structure as well as node value)

#include "lab22_tree_00.h"

int identical_binary_tree(struct node *original, struct node *copy)
{
    if (original == NULL && copy == NULL)
        return 1;

    int a,b;
    if (original->data == copy->data)
    {
        if (original->left && copy->left)
        {
            a=identical_binary_tree(original->left, copy->left);
        }
        if (original->right && copy->left)
        {
            b=identical_binary_tree(original->right, copy->right);
        }
        return a&b;
    }
    return 0;
}
int main()
{
    struct node *root,*copy;
    root=NULL;
    copy=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);
    predefine_tree(&copy);
    // copy->left->left->left=newnode_add(15);
    // copy->left->data=15;

    printf("ORIGINAL TREE:\n==============");
    print_all_traversal(root);

    printf("DUPLICATE TREE:\n==============");
    print_all_traversal(copy);

    if(identical_binary_tree(root,copy))
        printf("\n\nTREES ARE IDENTICAL");
    else
        printf("\n\nTREES ARE NOT IDENTICAL");

    free_all_nodes(&root);
    free_all_nodes(&copy);
    return 0;
}

