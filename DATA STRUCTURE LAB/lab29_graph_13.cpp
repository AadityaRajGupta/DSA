// Topological Sort	Program to find the Topological Sort of the DAG

// for characters
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,E;
    cout << "How many vertices use in graph: ";
    cin >> v;
    cout << "How many edges use in graph: ";
    cin >> E;

    map<char,list<char>> adjList;
    char vert;
    cout << "ENTER ONLY VERTICES:";
    for (int i = 0; i < v; i++)
    {
        cin >> vert;
        adjList[vert];
    }

    map<char,int> indeg;

    char a,b;
    // adjList['F'];   // inke outgoing kuch nhi hai tho phele se create karna hoga
    // adjList['I'];
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the end point of edge:";
        cin >> a>>b;
        adjList[a].push_back(b);
        indeg[b]++; 
    }
    
    cout << endl;

    map<char,list<char>>::iterator i;
    list<char>::iterator j;
    for(i=adjList.begin();i!=adjList.end();i++)
    {
        cout << "\nsize: "<< adjList[i->first].size() << endl;
        cout << "v[" << i->first << "]: ";

        for(j=adjList[i->first].begin();j!=adjList[i->first].end();j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }

    cout<< "\n\nPrint OUT-DEGREE:\n";
    for(i=adjList.begin();i!=adjList.end();i++)
    {
        cout << i->first << ": "<< adjList[i->first].size() <<endl;
    }
    
    cout << "\n\nPrint IN-DEGREE:\n";
    for(i=adjList.begin();i!=adjList.end();i++)
    {
        cout << i->first << ": ";
        cout << indeg[i->first];
        cout << endl;
    }


    // FOR TOPOLOGICAL SORT
    queue<char> tsq;
    for(i=adjList.begin();i!=adjList.end();i++)
    {
        if(indeg[i->first]==0)
            tsq.push(i->first);
    }
    cout << "\n\nTopological Sort:\n";
    while(!tsq.empty())
    {
        char x=tsq.front();
        tsq.pop();
        for(j=adjList[x].begin();j!=adjList[x].end();j++)
        {
            indeg[*j]--;
            if(indeg[*j]==0)
                tsq.push(*j);
        }
        cout << x << " ";
    }
    return 0;
}
