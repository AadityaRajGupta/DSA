// Shortest Path	Program for Warshall's Algorithm for APSP






// Write a program in C for finding shortest path in a Graph
#include <stdio.h>
#define infinity 999
void dij(int n, int v, int cost[10][10], int dist[])
{
    int i, u, count, w, flag[10], min;
    for (i = 1; i <= n; i++)
        flag[i] = 0, dist[i] = cost[v][i];
    count = 2;
    while (count <= n)
    {
        min = 99;
        for (w = 1; w <= n; w++)
            if (dist[w] < min && !flag[w])
                min = dist[w], u = w;
        flag[u] = 1;
        count++;
        for (w = 1; w <= n; w++)
            if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
                dist[w] = dist[u] + cost[u][w];
    }
}
int main2()
{
    int n, v, i, j, cost[10][10], dist[10];
    printf("\n\nNAME: AADITYA RAJ GUPTA\n");
    printf("ROLL NO.: 2100320100001\n\n");

    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = infinity;
        }
    printf("\nEnter the source matrix:");
    scanf("%d", &v);
    dij(n, v, cost, dist);
    printf("\n\nShortest path:\n");
    for (i = 1; i <= n; i++)
        if (i != v)
            printf("\n%d->%d,cost=%d", v, i, dist[i]);
    printf("\n");
    return 0;
}

// Write a program in C for minimum cost spanning tree
#include <stdio.h>
int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];
int main1()
{
    printf("\n\nNAME: AADITYA RAJ GUPTA\n");
    printf("ROLL NO.: 2100320100001\n\n");
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    visited[1] = 1;
    printf("\n");
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\nEdge %d:(%d %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\nMinimun cost=%d", mincost);
    return 0;
}
