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
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    DFS(adj, 1, visited);

    printf("hello");
    return 0;
}



// Minimum Cost Spanning Tree

const int V = 6;

// Function to find the vertex with minimum key value
int min_Key(int key[], bool visited[])
{
    int min = 999, min_index; // 999 represents an Infinite value

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            // vertex should not be visited
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the final MST stored in parent[]
int print_MST(int parent[], int cost[V][V])
{
    int minCost = 0;
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
        minCost += cost[i][parent[i]];
    }
    cout << "Total cost is: " << minCost<<"\n\n";
    return 0;
}

// Function to find the MST using adjacency cost matrix representation
void find_MST(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = 999; // 99 represents an Infinite value
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;     // Include first vertex in MST by setting its key vaue to 0.
    parent[0] = -1; // First node is always root of MST

    // The MST will have maximum V-1 vertices
    for (int x = 0; x < V - 1; x++)
    {
        // Finding the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = min_Key(key, visited);

        visited[u] = true; // Add the minimum key vertex to the MST

        // Update key and parent arrays
        for (int v = 0; v < V; v++)
        {
            // cost[u][v] is non zero only for adjacent vertices of u
            // visited[v] is false for vertices not yet included in MST
            // key[] gets updated only if cost[u][v] is smaller than key[v]
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    // print the final MST
    print_MST(parent, cost);
}

int main2()
{
    int cost[V][V];
    cout << "Enter the vertices for a graph with 6 vetices:";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
        }
    }
    find_MST(cost);

    return 0;
}




// Shortest path implementation
#define max 10
#define infi 99
using namespace std;
int p[max][max];
// All Pairs Shortest Path using Floyd's Algorithm
void allpairshort(int a[max][max], int n)
{
    int k, i, j;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}
// Storing the shortest path
void shortest(int i, int j)
{
    int k = p[i][j];
    if (k > 0)
    {
        shortest(i, k);
        cout << "  " << k << "  ";
        shortest(k, j);
    }
}
// Display the Shortest Path
void findpath(int a[max][max], int i, int j, int n)
{
    cout << "\n\nPath from " << i << " to " << j << ":";
    if (a[i][j] < infi)
    {
        cout << "  " << i << "  ";
        shortest(i, j);
        cout << "  " << j << " "<< "\n";
    }
}
int main3()
{
    int i, j;
    int a[][10] = {
        {0, 10, infi, 30, 100},
        {infi, 0, 50, infi, infi},
        {infi, infi, 0, infi, 10},
        {infi, infi, 20, 0, 60},
        {infi, infi, infi, infi, 0},
    };
    allpairshort(a, 5);
    findpath(a, 0, 3, 5);
    return 0;
}

int main()
{
    int choose=0;

    while (1)
    {
        cout << "\n1. BFS and DFS Implementation";
        cout << "\n2. Minimum Cost Spanning Tree";
        cout << "\n3. Shortest path implementation.";
        cout << "\n4. Exit\n";
        cout << "Enter your choose:";
        cin >> choose;
        switch (choose)
        {
            case 1:
                main1();
                break;
            case 2:
                main2();
                break;
            case 3:
                main3();
                break;
            case 4:
                return 0;
        }
    }
}
