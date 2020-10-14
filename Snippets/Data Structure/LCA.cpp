#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int LEVEL[SIZE];
int PARENT[SIZE];
int ST[SIZE][22];
vector <int> g[SIZE];
int n,e,a,b;

void dfs(int from, int u, int depth)
{
    PARENT[u] = from;
    LEVEL[u]  = depth;

    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if( v == from) continue;
        dfs(u, v, depth+1);
    }
}

int equalize(int p, int q)
{
    int log = log2(LEVEL[p]);

    for(int i = log; i >= 0; i--)
        if(LEVEL[p] - (1 << i) >= LEVEL[q])
            p = ST[p][i];
    return p;
}

int LCA(int p, int q)
{
    if(LEVEL[p] < LEVEL[q]) swap(p,q);

    p = equalize(p,q);

    if ( p == q ) return p;

    int log = log2(LEVEL[p]);

    for(int i = log; i >= 0; i--)
        if(ST[p][i] != ST[q][i])
            p = ST[p][i], q = ST[q][i];

    return PARENT[p];
}
void Compute_ST()
{
    memset(ST, -1, sizeof(ST));

    for (int i = 1; i <= n; i++)
        ST[i][0] = PARENT[i];

    for (int j = 1; (1 << j) < n; j++)
    {
        for(int i = 1; i <= n; i++)
            if(ST[i][j-1] != -1)
                ST[i][j] = ST[ ST[i][j-1] ] [j-1];
    }
}

int main()
{
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(-1, 1, 0);
    Compute_ST();

    while(cin >> a >> b)
    {
        cout << LCA(a,b) << endl;
    }
}
