// Program for Left View Traversal

#include <bits/stdc++.h>
using namespace std;

#define CPP_TREE  // DEFINE this to use the value from the node
#include "lab22_tree_00.h"

int left_view_traversal(struct node *root)
{
    queue<struct node *> Q;
    int h=height(root)-1;
    vector<int> ht[h+1];

    root->value=0;

    Q.push(root);
    ht[root->value].push_back(root->data);

    while(Q.size()!=0)
    {
        struct node *temp;
        temp=Q.front();
        Q.pop();

        if(temp->left)
        {
            temp->left->value=temp->value+1;
            Q.push(temp->left);
            ht[temp->left->value].push_back(temp->left->data);
        }
        if(temp->right)
        {
            temp->right->value=temp->value+1;
            Q.push(temp->right);
            ht[temp->right->value].push_back(temp->right->data);
        }
    }

    printf("LEFT VIEW TRAVERSAL:\n");
    for(int i=0;i<h+1;i++)
    {
        cout << ht[i][0] << " ";
    }
    return 0;
}
int main()
{
    struct node *root;
    root=NULL;
    
    predefine_tree(&root);
    left_view_traversal(root);

    free_all_nodes(&root);
    return 0;
}

