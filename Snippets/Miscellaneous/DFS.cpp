#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int level[SIZE];
int parent[SIZE];
int child[SIZE];

vector <int> g[SIZE];
int n,a,b;

void dfs(int from, int u, int depth)
{
    parent[u] = from;
    level[u]  = depth;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if( v == from) continue;
        dfs(u, v, depth+1);

        child[u] += child[v] + 1;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(-1, 1, 0);
}
