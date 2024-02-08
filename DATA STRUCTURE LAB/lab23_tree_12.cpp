// Program for Vertical Traversal

#include <bits/stdc++.h>
using namespace std;

#define CPP_TREE  // DEFINE this to use the value from the node
#include "lab22_tree_00.h"

int vertical_traversal(struct node *root)
{
    queue<struct node *> Q;
    int h=height(root)-1;
    vector<int> ht[2*h+1];

    // int value=0; // if this doesnot work then use a variable in side struct node
    root->value=0;

    Q.push(root);
    ht[root->value+h].push_back(root->data);

    while(Q.size()!=0)
    {
        struct node *temp;
        temp=Q.front();
        Q.pop();

        if(temp->left)
        { 
            temp->left->value=temp->value-1;
            Q.push(temp->left);
            ht[temp->left->value+h].push_back(temp->left->data);
        }
        if(temp->right)
        {
            temp->right->value=temp->value+1;
            Q.push(temp->right);
            ht[temp->right->value+h].push_back(temp->right->data);
        }
    }

    printf("VERTICAL TRAVERSAL:\n");
    for(int i=0;i<2*h+1;i++)
    {
        for(int j=0;j<ht[i].size();j++)
        {
            cout << ht[i][j] << " ";
        }
        cout << endl;

    }
    return 0;
}       
int main()
{
    struct node *root;
    root=NULL;
    
    predefine_tree(&root);
    vertical_traversal(root);

    free_all_nodes(&root);
    return 0;
}