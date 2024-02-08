// implementation of BFS using
// vectors and queue
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<bool> v;
vector<vector<int>> g;


// BFS Implementation
void edge(int a, int b)
{
    g[a].pb(b);
}
void bfs(int u)
{
    queue<int> q;

    q.push(u);
    v[u] = true;

    while (!q.empty())
    {

        int f = q.front();
        q.pop();

        cout << f << " ";
        for (auto i = g[f].begin(); i != g[f].end(); i++)
        {
            if (!v[*i])
            {
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}


// DFS Implementation
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v); 
}
int DFS(vector<int> adj[], int v, vector<bool> &vis)
{
    vis[v] = true;
    cout << v << " ";
    for (auto i : adj[v])
    {
        if (vis[i] == false)
            DFS(adj, i, vis);
    }
    return 0;
}

int main1()
{
    int n, e;
    cin >> n >> e;

    v.assign(n, false);
    g.assign(n, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge(a, b);
    }

    cout << "BFS Implementation:";
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
            bfs(i);
    }

    v.clear();
    g.clear();

    cout << "\n\nDFS Implementation:";
    vector<int> adj[5];
    vector<bool> visited(5, false);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);