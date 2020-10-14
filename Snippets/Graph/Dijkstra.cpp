#include<bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
vector< vector<pair<int,int> > > g;
vector <long long> level;
int a,b,c,n,e;
void dijkstra(int source)
{
    priority_queue<pair<long long,int> >q;
    level[source] = 0;
    q.push({0,source});
    while (!q.empty()) {

        int u=q.top().second;
        q.pop();
        for (auto v = g[u].begin(); v != g[u].end(); v++) {

            if((level[u]+v->second)<level[v->first])
            {
                level[v->first]=level[u]+v->second;
                q.push({-level[v->first],v->first});
            }
        }
    }
}
int main()
{
    cin >> n >> e;
    level.assign(n+1, inf);
    g.assign(n+1, vector<pair<int,int>>());

    int a,b,c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    dijkstra(1);
}

