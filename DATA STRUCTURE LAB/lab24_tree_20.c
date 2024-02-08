// write a program to find out mirror image of given binary tree.

#include "lab22_tree_00.h"

void mirror_binary_tree(struct node *original,struct node **copy)
{
    if(original==NULL)
        return ;
    if(original->left)
    {
        (*copy)->right=newnode_add(original->left->data);
        copy_binary_tree(original->left,&((*copy)->right));
    }
    if(original->right)
    {
        (*copy)->left=newnode_add(original->right->data);
        copy_binary_tree(original->right,&((*copy)->left));
    }
}
int main()
{
    struct node *root,*copy;
    root=NULL;
    copy=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);

    printf("ORIGINAL TREE:\n==============");
    print_all_traversal(root);

    copy=newnode_add(root->data);
    mirror_binary_tree(root,&copy);

    assert(copy!=NULL);     // assertion that copy is not NULL
    printf("\n\nCOPIED TREE:\n============");
    print_all_traversal(copy);

    free_all_nodes(&root);
    free_all_nodes(&copy);
    return 0;
}


