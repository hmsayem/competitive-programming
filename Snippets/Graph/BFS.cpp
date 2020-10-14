#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<vector<int> > g;
vector <int> level;
void bfs(int source)
{
    queue<int> q;
    level[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v = g[u].begin(); v != g[u].end(); v++) {
            if (level[*v]==inf) {
                level[*v]=level[u]+1;
                q.push(*v);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    level.assign(n+1, inf);
    g.assign(n+1, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    return 0;
}
