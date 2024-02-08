#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode_add(int data)
{
    struct node *n;
    n = getnode();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
// struct node *insert(struct node *root,int data)
// {
//     if (root==NULL)
//         return newnode(data);
//     if(root->data<data)
//         root->right=insert(root->right,data);
//     else if (root->data<data)
//         root->left=insert(root->left,data);
// }

void inorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        inorder_traversal(temp->left);
        printf("%d ",temp->data);
        inorder_traversal(temp->right);
    }
}
void preorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}
void postorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->data);
    }
}


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

// time : O(n)    auxiliary space : O(h)
// total number of nodes in tree 
int size(struct node *demo)
{
    if (demo!=NULL)
        return size(demo->left)+size(demo->right)+1;
}

int node_sum(struct node *temp)
{
    if (temp!=NULL)
        return temp->data+node_sum(temp->right)+node_sum(temp->left);
}

// count no. of nodes 1 child 
int count_one(struct node* ratsasan)
{
    if (ratsasan==NULL)
        return 0;
    else
    {
        if (ratsasan->left!=NULL && ratsasan->right==NULL)
            return count_one(ratsasan->left)+1;
        else if (ratsasan->left==NULL && ratsasan->right!=NULL)
            return count_one(ratsasan->right)+1;
        return count_one(ratsasan->left)+count_one(ratsasan->right);
    }
}

int count_two(struct node* ratsasan)
{
    if (ratsasan==NULL)
        return 0;
    else
    {
        if (ratsasan->left!=NULL && ratsasan->right!=NULL)
            return count_two(ratsasan->left)+count_two(ratsasan->right)+1;
    }
}

// Maximum path sum in a Binary Tree
int maximum_path_sum(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        if(root->left==NULL && root->right==NULL)
            return root->data;
        else
        {
            int a=maximum_path_sum(root->left);
            int b= maximum_path_sum(root->right);
            int max=(a>b) ? a : b;
            return (root->data+max);
        }
}

// right side view and left side view 
// its a extension of level order traversal.....level decide karte hue chalenge
// use queue and maintain 2d hash table using vector and access its 0 index element and last index element for side view

// top view and bottom view 
// node ke left ke level -1 and right ke level +1 iske according 2d hash table maintain hoga 
// 0 index wale top view and last index wale bottom view hoga (bottom view me overlapping ka concept hoga)

// vertical view ke liye same assigned value wale ake saath show honge jaise ki 0 index me left most line and so on 

// diameter of tree
int Diameter_of_tree(struct node *root)
{
    int d1,d2,d3,m1,m2;
    if(root==NULL)
        return 0;
    else 
    {
        d1=Diameter_of_tree(root->left);
        d2=Diameter_of_tree(root->right);
        d3=height(root->left)+height(root->right)+1;
        m1=(d1>d2)?d1:d2;
        m2=(d3>m1)?d3:m1;
        return m2;
    }
}

// zig-zag traversal :  left->right then right to left and then left to right and so on 
// take a flag=0 if even then left to right else right to left  from 2d hash table made by vector



// BST insertion using (ITERATIVE APPROACH) while loop in which we take two pointers P=root and Q=NULL 
// while(p!=NULL) Q=P compare p.data with x and make p point accordingly
// loop end compare q.data and insert new node to its left right on comparison basics
// IN ORDER or BST is numbers in asecending order
void insertion_bst(struct node **root,int num)
{
    struct node *p,*q;
    p=*root;
    q=NULL;

    while(p!=NULL)
    {
        q=p;
        if(p->data>num)
            p=p->left;
        else    
            p=p->right;
    }
    if(q->data>num)
        q->left=newnode_add(num);
    else
        q->right=newnode_add(num);
}

// BST insertion (RECURSIVE APPROACH) 
void bst_recursive(struct node **root,int num)
{
    if((*root)==NULL)
        (*root)=newnode_add(num);
    else
    {
        if((*root)->data>num)
            bst_recursive(&(*root)->left,num);
        else
            bst_recursive(&(*root)->right,num);
    }
}

struct node *bst_recursive_a(struct node *T,int num)
{
    if(T==NULL)
        T=newnode_add(num);
    else
    {
        if(T->data>num)
            T->left=bst_recursive_a(T->left,num);
        else
            T->right=bst_recursive_a(T->right,num);
    }
    return T;
}

struct node *max_bst(struct node *temp)
{
    // ake pointer bana lo jisse hum root ka address de or iterate karle phir
    while(temp->right!=NULL)
        temp=temp->right;
    return temp;
}

struct node *min_bst(struct node *temp)
{
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}

// Successor, Predecessor in BST : 4 fields hai ake father naam se le lenge jho uske predecessor kho store karega
// successor ka matlub usse next bara node data


// this is bst insertion 
struct node *bst_recursive_fpr_successor_predecessor(struct node *T,int num)
{
    if(T==NULL)
        T=newnode_add(num);
    else
    {
        struct node *temp;
        if(T->data>num)
        {
            temp=bst_recursive_fpr_successor_predecessor(T->left,num);
            // temp->father= T;
            T->left=temp;
        }
        else
        {
            temp=bst_recursive_fpr_successor_predecessor(T->right,num);
            // temp->father= T;
            T->right=temp;
        }
    }
    return T;
}









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
    return 0;
}
int main()
{
    struct node *root;
    root = NULL;
    root=newnode_add(7); 
    form_tree(&root);


    // root=newnode_add(5);
    // root->left=newnode_add(1);
    // root->right=newnode_add(2);
    // root->left->left=newnode_add(3);
    // root->left->right=newnode_add(4);
    // root->right->left=newnode_add(7);
    // root->right->right=newnode_add(8);

    // root->left->left->left=newnode_add(10);    
    
    // insert(root,5);
    // insert(root,8);
    // insert(root,1);
    // insert(root,2);
    // insert(root,9);


    inorder_traversal(root);

    printf("\n\nHEIGHT: %d",height(root));

    printf("\n\nSIZE: %d",size(root));
    printf("\nMAXIMUM PATH SUM: %d",maximum_path_sum(root));

    // printf("\n\nSUM: %d",node_sum(root));

    // printf("\n\nNO OF NODES HAVING 1 CHILD: %d",count_one(root));

    // printf("\n\nNO OF NODES HAVING 2 CHILD: %d",count_two(root));
    
    return 0;
}

/*
Full Binary Tree Theorem
Theorem: Let T be a nonempty, full binary tree Then:
(a) If T has I internal nodes, the number of leaves is L = I + 1.
(b) If T has I internal nodes, the total number of nodes is N = 2I + 1.
(c) If T has a total of N nodes, the number of internal nodes is I = (N – 1)/2.
(d) If T has a total of N nodes, the number of leaves is L = (N + 1)/2.
(e) If T has L leaves, the total number of nodes is N = 2L – 1.
(f) If T has L leaves, the number of internal nodes is I = L – 1.


Depth First Search : INORDER , PREORDER , POSTORDER

Breadth first traversal:  (or can be said as level order traversal)
    For each node, first, the node is visited and then it’s child nodes are put in a FIFO queue. 
    Then again the first node is popped out and then it’s child nodes are put in a FIFO queue 
    and repeat until queue becomes empty.





*/