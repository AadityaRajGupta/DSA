// Reading Graph	Graph	Program to read a graph and print the adjacency List

#include<iostream>
#include<vector>
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
    return 0;
}