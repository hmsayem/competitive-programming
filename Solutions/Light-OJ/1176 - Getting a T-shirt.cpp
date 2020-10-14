#include <bits/stdc++.h>
using namespace std;
#define SIZE 200
#define inf 1000

int residual[SIZE][SIZE];
int graph[SIZE][SIZE];
bool visited[SIZE];
int parent[SIZE];
int TC,n,m,c,sink,source;

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

        for(int v = 0; v <= sink; v++)
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
    for(int i = 0; i <= sink; i++)
    {
        for(int j = 0; j <= sink; j++)
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
int main()
{

    map < string, int > mp;

    mp["XS"]  = 2;
    mp["S"]   = 4;
    mp["M"]   = 6;
    mp["L"]   = 8;
    mp["XL"]  = 10;
    mp["XXL"] = 12;


    cin >> TC;

    for(int T = 1; T <= TC; T++)
    {
        memset(graph, 0, sizeof(graph));
        cin >> n >> m;

        c = 13;
        source = 0;
        sink = c + m;
        string a,b;


        for(int i = 1; i <= 11; i += 2)
        {
            graph[0][i] = inf;
            graph[i][i+1] = n;
        }

        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;

            graph[mp[a]][c]  = 1;
            graph[mp[b]][c]  = 1;
            graph[c][sink]   = 1;

            c++;
        }

        int ans = fordFulkerson(source, sink) ;

        if (ans >= m )
            cout << "Case "<< T << ": " << "YES" << endl;
        else
            cout << "Case "<< T << ": " << "NO" << endl;
    }
}
