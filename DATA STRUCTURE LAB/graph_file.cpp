// , BFS, DFS, Minimum cost spanning tree, shortest path algorithm.

// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <bits/stdc++.h>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph {
	int V; // No. of vertices

	// Pointer to an array containing adjacency
	// lists
	vector<list<int> > adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
	visited.resize(V, false);

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto adjecent : adj[s]) {
			if (!visited[adjecent]) {
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}


/*
-> Generic Function for BFS traversal of a Graph
(valid for directed as well as undirected graphs
which can have multiple disconnected components)
-- Inputs --
-> V - represents number of vertices in the Graph
-> adj[] - represents adjacency list for the Graph
-- Output --
-> bfs_traversal - a vector containing bfs traversal
for entire graph
*/

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
	vector<int> bfs_traversal;
	vector<bool> vis(V, false);
	for (int i = 0; i < V; ++i) {

		// To check if already visited
		if (!vis[i]) {
			queue<int> q;
			vis[i] = true;
			q.push(i);

			// BFS starting from ith node
			while (!q.empty()) {
				int g_node = q.front();
				q.pop();
				bfs_traversal.push_back(g_node);
				for (auto it : adj[g_node]) {
					if (!vis[it]) {
						vis[it] = true;
						q.push(it);
					}
				}
			}
		}
	}
	return bfs_traversal;
}


//DFS 

// C++ program to print DFS
// traversal for a given
// graph
#include <bits/stdc++.h>
using namespace std;

class Graph {

	// A function used by DFS
	void DFSUtil(int v);

public:
	map<int, bool> visited;
	map<int, list<int> > adj;
	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints DFS traversal of the complete graph
	void DFS();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v)
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i);
}

// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
	// Call the recursive helper function to print DFS
	// traversal starting from all vertices one by one
	for (auto i : adj)
		if (visited[i.first] == false)
			DFSUtil(i.first);
}

// Driver's Code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal \n";

	// Function call
	g.DFS();

	return 0;
}
// Improved By Priyank Namdeo
