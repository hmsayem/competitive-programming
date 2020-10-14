#include <bits/stdc++.h>
using namespace std;

int n,e,n1,n2,MAX;
vector < vector < pair <int, int > > > g;
int visit[30005];
int dis1[30005];
int dis2[30005];

void dfs1(int u, int cost, int flag)
{

    visit[u] = 1;
    
    if( cost > MAX)
    {
        MAX = cost;
        if(flag == 0) n1 = u;
        else n2 = u;
    }

    for (auto it = g[u].begin(); it != g[u].end(); it++)
    {
        int v  = it -> second;
        if(visit[v] == 1) continue;
        dfs1( v, cost + it-> first, flag );
    }
}

void dfs2(int u, int cost, int flag)
{
    visit[u] = 1;

    if( flag == 0) dis1[u] = cost;
    else dis2[u] = cost;

    for (auto it = g[u].begin(); it != g[u].end(); it++)
    {
        int v = it -> second;
        if(visit[v] == 1) continue;
        dfs2(v, cost + it -> first, flag);
    }
}
int main()
{
    int TC;
    scanf("%d", &TC);

    for ( int T = 1; T <= TC; T++)
    {
        scanf("%d", &n);

        g.assign(n+1, vector < pair < int, int > >());
        memset(visit, 0, sizeof(visit));


        int a, b, w;
        for (int i = 0; i < n-1; i++) {
            scanf("%d %d %d",&a,&b,&w);
            g[a].push_back({w,b});
            g[b].push_back({w,a});
        }

        MAX = 0;
        dfs1(0, 0, 0);
        MAX = 0;
        memset(visit, 0, sizeof(visit));
        dfs1(n1, 0, 1);
        memset(visit, 0, sizeof(visit));
        dfs2(n1, 0, 0);
        memset(visit, 0, sizeof(visit));
        dfs2(n2, 0, 1);

        printf("Case %d:\n",T);
        for(int i=0; i <= n-1; i++)
        {
            printf("%d\n",max(dis1[i], dis2[i]));
        }
    }
}
