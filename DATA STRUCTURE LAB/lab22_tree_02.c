// Recursive Creation of Binary Tree

#include "lab22_tree_00.h"

#define HELLO_TREE

// because these function are already declared in header file
#ifndef HELLO_TREE
int form_tree(struct node **root)
{
    struct node *hello;
    char choose;
    int num;

    fflush(stdin);
    printf("\nNode %d contain left node(Y/N): ",(*root)->data);
    scanf("%c",&choose);
    if(choose=='Y' || choose=='y')
    {
        hello=getnode();
        printf("Enter data: ");
        scanf("%d",&num);
        hello=newnode_add(num);
        (*root)->left=hello;
        form_tree(&hello);
    }

    fflush(stdin);
    printf("Node %d contain right node(Y/N): ",(*root)->data);
    scanf("%c",&choose);
    if(choose=='Y' || choose=='y')
    {
        hello=getnode();
        printf("Enter data: ");
        scanf("%d",&num);
        hello=newnode_add(num);
        (*root)->right=hello;
        form_tree(&hello);
    }
    else
        printf("\n");
    return 0;
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



