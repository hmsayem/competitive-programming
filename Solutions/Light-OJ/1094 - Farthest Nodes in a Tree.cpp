#include <bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY  2
#define BLACK 3

const int inf = 0x3f3f3f3f;
int visit [30005];
int max1  [30005];
int max2  [30005];

vector < vector < pair <int,int > > > g;

int n, e, MAX;
int dfs(int x)
{
    visit[x] = 1;


    for (auto v = g[x].begin(); v != g[x].end(); v++)
    {
        int temp = 0;

        if (visit[v->first] == 0)
        {
           temp = v->second + dfs(v->first);
           if(temp > max1[x])
           {
               max2[x] = max1[x];
               max1[x] = temp;
           }
           else if( temp > max2[x])
           {
               max2[x] = temp;
           }
        }
    }

    MAX = max (MAX, max1[x] + max2[x]);

    return max1[x];


}

int main()
{

    int T;

    cin >> T;

    for(int k = 1; k <= T; k++)
    {
        cin >> n;

        memset(visit, 0, sizeof(visit));
        memset(max1, 0, sizeof(max1));
        memset(max2, 0, sizeof(max2));
        MAX = 0;

        g.assign(n+1, vector<pair <int,int> > () );

        int a, b, w;
        for (int i = 0; i < n-1; i++) {
            cin >> a >> b >> w;
            g[a].push_back({b,w});
            g[b].push_back({a,w});
        }

        dfs(0);

        cout << "Case " << k << ": " << MAX <<endl;

    }
    return 0;
}
