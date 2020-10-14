#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector <int> color;
bool bfs(int source)
{
    queue<int> q;
    color[source] = 1;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v = g[u].begin(); v != g[u].end(); v++) {
            if (color[*v]==-1) {
                color[*v]=(color[u]==1) ?  0 : 1 ;
                q.push(*v);
            }
            else if(color[*v]==color[u])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;

    color.assign(n+1, -1);
    g.assign(n+1, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    return 0;
}
