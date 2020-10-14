#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
int n;
int residual[SIZE][SIZE];
int graph[SIZE][SIZE];
bool visited[SIZE];
int parent[SIZE];

bool findPath(int s, int t)
{
    memset(visited,0,sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++)
        {
            if(visited[v] == false && residual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);

}
int fordFulkerson(int s, int t)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            residual[i][j] = graph[i][j];
        }
    }

    int max_flow = 0;
    while(findPath(s,t))
    {
        int path_flow = INT_MAX;

        for(int v = t; v!=s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        for(int v = t; v!=s; v = parent[v])
        {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    
    return max_flow;
}
