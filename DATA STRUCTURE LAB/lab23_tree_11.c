// Program for Level Order Traversal

#include "lab22_tree_00.h"

#define HELLO_TREE

#ifndef HELLO_TREE
    // use the height for the traversal
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
#else
    void printLevelOrder(struct node *root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            // for(int j=h-1-i;j>=0;j--)
            //     printf("  ");
            printCurrentLevel(root, i);
            printf("\n");
        }
    }
#endif

// use of queue for the level order traversal 
#define MAX_Q_SIZE 10
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

// Breadth first traversal
int level_order_traversal(struct node *root)
{
    int rear,front;
    struct node *temp_data_node=root;
    struct node **queue=createQueue(&front,&rear);

    while(!isQueueEmpty(&front,&rear))
    {
        printf("%d ",temp_data_node->data);

        if(temp_data_node->left)
            enQueue(queue,&rear,temp_data_node->left);
        if(temp_data_node->right)
            enQueue(queue,&rear,temp_data_node->right);
        
        temp_data_node=deQueue(queue,&front);
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
    printf("\nLEVEL ORDER TRAVERSAL:\n");
    // printLevelOrder(root);
    level_order_traversal(root);

    printf("\n\nINORDER TRAVERSAL: ");
    inorder_traversal(root);
    printf("\nPRE-ORDER TRAVERSAL: ");
    preorder_traversal(root);
    printf("\nPOST-ORDER TRAVERSAL: ");
    postorder_traversal(root);

    free_all_nodes(&root);
    return 0;
}

