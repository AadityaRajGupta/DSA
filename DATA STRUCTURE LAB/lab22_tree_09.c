// Program to Find if the given Binary Tree is complete

#include "lab22_tree_00.h"
#include <stdbool.h>

bool isComplete(struct node *root, unsigned int index,unsigned int number_nodes)
{
    if (root == NULL)
        return (true);

    printf("\nindex: %d",index);
    if (index >= number_nodes)
        return (false);

    return (isComplete(root->left, 2 * index + 1, number_nodes) && isComplete(root->right, 2 * index + 2, number_nodes));
}


#define MAX_Q_SIZE 10
struct node** createQueue(int* front, int* rear)
{
	struct node** queue = (struct node**)malloc(sizeof(struct node*) * MAX_Q_SIZE);

	*front = *rear = 0;
	return queue;
}
void enQueue(struct node** queue, int* rear,struct node* new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}
struct node* deQueue(struct node** queue, int* front)
{
	(*front)++;
	return queue[*front - 1];
}
bool isQueueEmpty(int* front, int* rear)
{
	return (*rear == *front);
}

bool isCompleteBT_simple_queue(struct node *root)
{
    // Base Case: An empty tree is complete Binary Tree
    if (root == NULL)
        return true;

    // Create an empty queue
    int rear, front;
    struct node **queue = createQueue(&front, &rear);

    // Create a flag variable which will be set true
    // when a non full node is seen
    bool flag = false;

    enQueue(queue, &rear, root);
    while (!isQueueEmpty(&front, &rear))
    {
        struct node *temp_node = deQueue(queue, &front);

        if (temp_node->left)
        {
            if (flag == true)
                return false;

            enQueue(queue, &rear,temp_node->left); 
        }
        else 
            flag = true;

        if (temp_node->right)
        {
            if (flag == true)
                return false;

            enQueue(queue, &rear,temp_node->right); 
        }
        else
            flag = true;
    }

    // If we reach here, then the tree is complete Binary Tree
    return true;
}

bool isCompleteBT(struct node* root)
{
	if (root == NULL)
		return true;

	// Create an empty queue
	int rear, front;
	struct node** queue = createQueue(&front, &rear);
	enQueue(queue, &rear, root);

	// Create a flag variable which will be set true
	// when a non full node is seen
	bool flag = false;

	while (!isQueueEmpty(&front, &rear)) 
    {
		struct node* temp_node = deQueue(queue, &front);

        // if(temp_node!=NULL)
        //     printf("\ntemp: %d",temp_node->data);
        // else
        //     printf("\nnull");

		if (!temp_node) {
			// If we have seen a NULL node, we set the flag to true
			flag == true;
		}
		else {
			// If that NULL node is not the last node then return false
			if (flag == true) {
				return false;
			}

			// Push both nodes even if there are null
			enQueue(queue, &rear,temp_node->left);
			enQueue(queue, &rear,temp_node->right);
		}
	}
	return true;
}


int main()
{
    struct node *root;
    root=NULL;

    // root=newnode_add(1);
    // form_tree(&root);

    // predefine_tree(&root);
    // root->left->left->right=newnode_add(10);

    root=newnode_add(1);
    root->left=newnode_add(2);
    root->right=newnode_add(3);
    // root->left->left=newnode_add(4);
    root->left->right=newnode_add(5);
    root->right->left=newnode_add(6);
    root->right->right=newnode_add(7);

    assert(root!=NULL);

    int node_count=size(root);
    int index=0;
    // if (isComplete(root, index, node_count))
    if (isCompleteBT(root)==true)
        printf("\nTHE BINARY TREE IS COMPLETE");
    else
        printf("\nTHE BINARY TREE IS NOT COMPLETE");

    print_all_traversal(root);

    free_all_nodes(&root);
    return 0;
}