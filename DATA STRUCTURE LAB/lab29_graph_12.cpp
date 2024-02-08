// Indegree, outdegree	Program to find the InDegree and OutDegree of all nodes in a graph

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,E;
    cout << "How many vertices use in graph: ";
    cin >> v;
    cout << "How many edges use in graph: ";
    cin >> E;

    vector<int> adjlst[v];
    vector<int> indeg(v,0);

    int a,b;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the end point of edge:";
        cin >> a>>b;
        adjlst[a].push_back(b);
        indeg[b]++;
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

    cout<< "Print OUT-DEGREE:\n";
    for(int i=0;i<v;i++)
    {
        cout << i << ": "<< adjlst[i].size()<<endl;
    }
    
    cout << "Print IN-DEGREE:\n";
    for(int i=0;i<v;i++)
    {
        cout << i << ": ";
        cout << indeg[i];
        cout << endl;
    }

    return 0;
}
