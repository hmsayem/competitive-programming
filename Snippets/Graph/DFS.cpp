
#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY  2
#define BLACK 3

const int inf = 0x3f3f3f3f;
vector < vector < int > > g;
vector < int > color;
int n,e;

void dfsVisit(int x)
{
    color[x] = GRAY;

    for (auto v = g[x].begin(); v != g[x].end(); v++)
    {
        if (color[*v]==WHITE)
        {
           dfsVisit(*v);
        }
    }
    color[x] = BLACK;

}
void dfs()
{

    for(int i = 0; i < n; i++)
    {
       if(color[i] == WHITE)
       {
           dfsVisit(i);
       }
    }
}


int main()
{

    cin >> n >> e;
    color.assign(n+1,1);
    g.assign(n+1, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    return 0;
}
