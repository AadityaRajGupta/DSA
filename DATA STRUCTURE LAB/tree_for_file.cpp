#include <bits/stdc++.h>
using namespace std;

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

int form_tree(struct node **root)
{
    struct node *hello;
    char choose;
    int num;

    fflush(stdin);
    cout << "\nNode " << (*root)->data <<" contain left node(Y/N): ";
    cin >> choose;
    if(choose=='Y' || choose=='y')
    {
        hello=getnode();
        cout << "Enter data: ";
        cin >> num;
        hello=newnode_add(num);
        (*root)->left=hello;
        form_tree(&hello);
    }

    fflush(stdin);
    cout << "Node "<< (*root)->data << " contain right node(Y/N): ";
    cin >> choose;
    if(choose=='Y' || choose=='y')
    {
        hello=getnode();
        cout << "Enter data: ";
        cin >> num;
        hello=newnode_add(num);
        (*root)->right=hello;
        form_tree(&hello);
    }
    else
        cout << "\n";
    return 0;
}
struct node* deletion(struct node* root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    node* key_node = NULL;
    node* temp;
    node* last;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left) {
            last = temp; 
            q.push(temp->left);
        }
        if (temp->right) {
            last = temp;
            q.push(temp->right);
        }
    }
    if (key_node != NULL) {
        key_node->data = temp->data;
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    }
    return root;
}
int main()
{
    struct node *root;
    root=NULL;

    root=newnode_add(1);
    form_tree(&root);

    cout << "\nSIZE OF BINARY TREE: " << size(root) << "\n";
    print_all_traversal(root);

    int num;
    cout << "\n\n\nENTER DATA WANT TO DELETE:";
    cin >> num;
    deletion(root,num);
    print_all_traversal(root);
    return 0;
}