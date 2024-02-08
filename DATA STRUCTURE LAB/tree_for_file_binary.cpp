#include <bits/stdc++.h>
using namespace std;

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

struct node *newnode_add(int data)
{
    struct node *n;
    n = getnode();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->father=NULL;
    return n;
}

void inorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        inorder_traversal(temp->left);
        cout << temp->data << " ";
        inorder_traversal(temp->right);
    }
}
void preorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        cout << temp->data << " ";
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
        cout << temp->data << " ";
    }
}
void print_all_traversal(struct node *root)
{
    cout << "\nINORDER TRAVERSAL: ";
    inorder_traversal(root);
    cout << "\nPRE-ORDER TRAVERSAL: ";
    preorder_traversal(root);
    cout << "\nPOST-ORDER TRAVERSAL: ";
    postorder_traversal(root);
}

int size(struct node *demo)
{
    if (demo!=NULL)
        return size(demo->left)+size(demo->right)+1;
    return 0;
}

struct node *min_bst(struct node *temp)
{
    while(temp->left!=NULL && temp)
        temp=temp->left;
    return temp;
} 
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

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = min_bst(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root;
    root=NULL;

    int choose,num;
    do{
        cout << "\nENTER THE DATA:";
        cin >> num;
        bst_recursive(&root,num);
        cout << "ENTER -1 TO STOP INSERTION: ";
        cin >> choose;
    }while(choose!=-1);


    cout << "\nSIZE OF BINARY TREE: " << size(root) << "\n";
    print_all_traversal(root);

    cout << "\n\n\nENTER DATA WANT TO DELETE:";
    cin >> num;
    
    root = deleteNode(root, num);
    print_all_traversal(root);
    return 0;
}