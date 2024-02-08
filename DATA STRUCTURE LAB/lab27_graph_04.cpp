// Traversal	Graph	Program for BFS on a Graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int v,E;
    cout << "How many vertices use in graph: ";
    cin >> v;
    cout << "How many edges use in graph: ";
    cin >> E;

    vector<int> adjlst[v];
    int a,b;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the end point of edge:";
        cin >> a>>b;
        adjlst[a].push_back(b);
        adjlst[b].push_back(a);
    }
    cout << endl;
    for(int i=0;i<v;i++)
    {
        cout << "size: "<< adjlst[i].size() << endl;
        cout << "v[" << i << "]: ";
        for(int j=0;j<adjlst[i].size();j++)
        {
            cout << adjlst[i][j] << " ";
        }
        cout << endl << endl;
    }

    /* queue<int> Q;
    vector<int> status(v);

    Q.push(0);
    status[0]=1;
    cout << "BFS: ";
    while(Q.empty() != 1)
    {
        int x=Q.front();
        Q.pop();
        for(int j=0;j<adjlst[x].size();j++)
        {
            if(status[adjlst[x][j]]==0)
            {
                Q.push(adjlst[x][j]);
                status[adjlst[x][j]]=1;
            }
        }
        cout << x << " ";
    } */

    // single sort distance from source
    queue<int> Q;
    vector<int> status(v,-1);

    Q.push(0);
    status[0]=0;
    cout << "BFS: ";
    while(Q.empty() != 1)
    {
        int x=Q.front();
        Q.pop();
        for(int j=0;j<adjlst[x].size();j++)
        {
            if(status[adjlst[x][j]]==0)
            {
                Q.push(adjlst[x][j]);
                status[adjlst[x][j]]=status[x]+1;
            }
        }
        cout << x << " ";
    }
    printf("\n\nDISTANCE FROM SOURCE: ");
    for(auto i:status)
    {
        cout << i << " ";
    }
    return 0;
}
/*
How many vertices use in graph: 6
How many edges use in graph: 9
Enter the end point of edge:0 1
Enter the end point of edge:0 2
Enter the end point of edge:0 3
Enter the end point of edge:1 2
Enter the end point of edge:2 3
Enter the end point of edge:2 5
Enter the end point of edge:3 4
Enter the end point of edge:4 5
Enter the end point of edge:3 5

size: 3
v[0]: 1 2 3

size: 2
v[1]: 0 2

size: 4
v[2]: 0 1 3 5

size: 4
v[3]: 0 2 4 5

size: 2
v[4]: 3 5

size: 3
v[5]: 2 4 3

BFS: 0 1 2 3 5 4
*/