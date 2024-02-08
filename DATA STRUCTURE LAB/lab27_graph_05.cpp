// Traversal	Graph	Program for DFS on a Graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int DFSR(vector<int> Adj[],int i,vector<int>&status,int c)
{
    c++;
    status[i]=1;
    cout << i << " ";
    for(int j=0;j<Adj[i].size();j++)
    {
        if(status[Adj[i][j]]==0)
        {
            c=DFSR(Adj,Adj[i][j],status,c);
            // return c;
        }
    }
    return c;
}
void DFS(vector<int> Adj[],int N)
{
    int m=0,k=0;
    vector<int> status(N,0);
    vector<int> connected;
    for(int i=0;i<N;i++)
    {
        if(status[i]==0)
        {
            m++;
            k=DFSR(Adj,i,status,0);
            connected.push_back(k);
        }
    }

    cout << "CONNNECTED GRAPH:"<< m<<endl;
    for(int i=0;i<connected.size();i++)
    {
        cout << connected[i] << " ";
    }
}

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
        // adjlst[b].push_back(a);
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

    DFS(adjlst,v);
    return 0;
}
