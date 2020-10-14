#include <bits/stdc++.h>
using namespace std;
#define SIZE 205
#define inf 1005
int residual[SIZE][SIZE];
int graph[SIZE][SIZE];
bool visited[SIZE];
int parent[SIZE];
int TC,n,m,c,u,v,a,b;
int source,sink;

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

        for(int v = 0; v <= (n*2+2); v++)
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
    for(int i = 1; i <= 2*n+2; i++)
    {
        for(int j = 1; j <= 2*n+2; j++)
        {
            residual[i][j] = graph[i][j];
        }
    }

    int max_flow = 0;
    while(findPath(s,t))
    {
        int path_flow = INT_MAX;

        for(int v = t; v != s; v = parent[v])
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
int main()
{

    scanf("%d",&TC);

    for(int T = 1; T <= TC; T++)
    {
        scanf("%d",&n);
        memset(graph,0,sizeof(graph));

        for(int i = 1; i <= n; i++ )
        {
            scanf("%d", &c);
            u = i*2;
            v = i*2 + 1;

            graph[u][v] = c;
            graph[v][u] = c;
        }

        scanf("%d", &m);

        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d",&a, &b, &c);

            int u = 2*a + 1;
            int v = 2*b;

            graph[u][v] = c;
        }

        source = 1;
        sink = 2*n + 2;

        scanf("%d %d", &a, &b);

        for(int i = 1; i <= a; i++)
        {
            scanf("%d",&v);
            graph[source][2*v] = inf;
        }

        for(int i = 1; i <= b; i++)
        {
            scanf("%d", &v);
            graph[2*v+1][sink] = inf;
        }

        printf("Case %d: %d\n",T, fordFulkerson(source,sink));

    }
}
