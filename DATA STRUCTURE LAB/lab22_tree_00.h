#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// # define NDEBUG  // to run the code without assertions

// This macro is for memory allocation using malloc
#define getnode() (struct node *)malloc(sizeof(struct node))

// Basic structure of node used in tree (i.e data,left pointer, right pointer)
#ifndef CPP_TREE
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
#else
struct node 
{
    int data;
    int value;
    struct node *left;
    struct node *right;
};
#endif


// This funtion is used create a node with given data
struct node *newnode_add(int data)
{
    struct node *n;
    n = getnode();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}




// This function is used print the tree in IN-ORDER
void inorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        inorder_traversal(temp->left);
        printf("%d ",temp->data);
        inorder_traversal(temp->right);
    }
}

// This function is used print the tree in PRE-ORDER
void preorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}

// This function is used print the tree in POST-ORDER
void postorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->data);
    }
}

// This function print the current level data by using height
void printCurrentLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf(" %d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(struct node *hello);
// This function is used for level order traversal  
void levelorder_traversal_using_height(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        // for(int j=h-1-i;j>=0;j--)
        //     printf("  ");
        printCurrentLevel(root, i);
        // printf("\n");
        printf("----");
    }
}

void print_all_traversal(struct node *root)
{
    printf("\nINORDER TRAVERSAL: ");
    inorder_traversal(root);
    printf("\nPRE-ORDER TRAVERSAL: ");
    preorder_traversal(root);
    printf("\nPOST-ORDER TRAVERSAL: ");
    postorder_traversal(root);
    printf("\nLEVEL-ORDER TRAVERSAL: ");
    levelorder_traversal_using_height(root);
}


/*
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
*/
void degree_of_nodes()
{
    printf("\nsee code from comment\n");
}

// This is max funtion for finding height of tree
int max_a(int a,int b)
{
    return (a>b) ? a : b;
}
// This function is used to find the height of tree
int height(struct node *hello)
{
    if(hello!=NULL)
        return max_a(height(hello->left),height(hello->right))+1;
    return 0;
}

// This funtion is for the count of node in tree
int size(struct node *demo)
{
    if (demo!=NULL)
        return size(demo->left)+size(demo->right)+1;
    return 0;
}


// This function is used to construct the tree after creating a root node and taking its address
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

// pre-defined tree of inorder: 4251637
void predefine_tree(struct node **root)
{
    (*root)=newnode_add(1);
    (*root)->left=newnode_add(2);
    (*root)->right=newnode_add(3);
    (*root)->left->left=newnode_add(4);
    (*root)->left->right=newnode_add(5);
    (*root)->right->left=newnode_add(6);
    (*root)->right->right=newnode_add(7);
}

// This queue is used to take the node in it
#define MAX_Q_SIZE 20
struct node **createQueue(int *front, int *rear)
{
    struct node **queue = (struct node **)malloc(sizeof(struct node *) * MAX_Q_SIZE);

    *front = *rear = 0;
    return queue;
}
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
struct node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}
int isQueueEmpty(int *front, int *rear)
{
    if (*rear+1 == *front)
        return 1;
    return 0;
}

// free all nodes from memory
void free_all_nodes(struct node **root)
{
    int rear,front;
    struct node *temp_data_node=(*root);
    struct node **queue=createQueue(&front,&rear);

    (*root)=NULL;

    while(!isQueueEmpty(&front,&rear))
    {
        if(temp_data_node->left)
            enQueue(queue,&rear,temp_data_node->left);
        if(temp_data_node->right)
            enQueue(queue,&rear,temp_data_node->right);
        
        free(temp_data_node);
        temp_data_node=deQueue(queue,&front);
    }
}