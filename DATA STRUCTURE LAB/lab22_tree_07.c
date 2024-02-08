// Program to Find the height of the Binary Tree 

#include "lab22_tree_00.h"

#define HELLO_TREE

// because these function are already declared in header file
#ifndef HELLO_TREE
int max_a(int a,int b)
{
    return (a>b) ? a : b;
}
int height(struct node *hello)
{
    if(hello!=NULL)
        return max_a(height(hello->left),height(hello->right))+1;
    return 0;
}
#endif


int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);

    assert(root!=NULL);

    printf("\nHEIGHT OF BINARY TREE: %d",height(root));

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}