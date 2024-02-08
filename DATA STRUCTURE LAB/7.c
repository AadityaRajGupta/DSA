#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d\t", root->data);
        inordertraversal(root->right);
    }
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;
}
int heightoftree(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
        return (max(heightoftree(root->left), heightoftree(root->right)) + 1);
}
int numberofnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
        return (1 + numberofnodes(root->left) + numberofnodes(root->right));
}
int leafnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return (leafnodes(root->left) + leafnodes(root->right));
    }
}
int child1(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
            return 0;
        else
        {
            if (root->left != NULL && root->right != NULL)
            {
                return (child1(root->left) + child1(root->right));
            }
            else
                return (1 + child1(root->left) + child1(root->right));
        }
    }
}
int child2(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left != NULL && root->right != NULL)
    {
        return 1;
    }
    else
        return (child2(root->left) + child2(root->right));
}
int sumofnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
        return (root->data + sumofnodes(root->left)+ sumofnodes(root->right));
}
int main()
{
    int option;
    struct node *root;
    root = NULL;
    root = makenode(1);
    root->left = makenode(2);
    root->right = makenode(3);
    root->left->left = makenode(4);
    root->right->left = makenode(5);
    root->right->right = makenode(6);
    root->right->right->right = makenode(7);
    do
    {
        printf("1. Height of tree\n");
        printf("2. Number of nodes in tree\n");
        printf("3. Number of leaf nodes\n");
        printf("4. Nodes with 1 child\n");
        printf("5. Nodes with 2 children\n");
        printf("6. Sum of all nodes\n");
        printf("7. EXIT\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("the height of tree is %d\n", heightoftree(root));
            break;
        case 2:
            printf("Number of nodes in the tree is %d\n", numberofnodes(root));
            break;
        case 3:
            printf("number of leaf nodes is %d\n", leafnodes(root));
            break;
        case 4:
            printf("nodes with 1 child is %d\n", child1(root));
            break;
        case 5:
            printf("nodes with 2 child is %d\n", child2(root));
            break;
        case 6:
            printf("sum of nodes is %d\n", sumofnodes(root));
            break;
        }
    } while (option != 7);
}