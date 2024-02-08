// write a program to delete to entire binary tree.

#include "lab22_tree_00.h"
#define HELLO

#ifndef HELLO
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
#endif
int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    predefine_tree(&root);

    printf("ORIGINAL TREE:\n==============");
    print_all_traversal(root);

    free_all_nodes(&root);
    
    if(root==NULL)
        printf("\n\nTREE DELETED SUCCESSFULLY");
    else
        printf("\n\nTREE NOT DELETED");
    return 0;
}

