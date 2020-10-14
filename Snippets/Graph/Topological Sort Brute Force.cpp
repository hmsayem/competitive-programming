
#include <bits/stdc++.h>
using namespace std;

int task[105];
bool vis[105];
vector < int > v[105];

int main()
{
    int n, m, a, b;
    for( int i = 1; i <= m; i++ )
    {
        cin >> a >> b;
        task[b]++;
        v[a].push_back(b);
    }

    int t=n;
    vector < int > order;

    for(int i = 1; i <= n; i++)
    {
        if( task[i] == 0 && vis[i] == 0 )
        {
            vis[i] = 1;
            order.push_back(i);

            for(int j = 0; j < v[i].size(); j++)
            task[v[i][j]]--;
            i = 0;
        }
        else if( i == n )    break;
    }

    for ( auto x : order ) cout << x << " ";
    cout << endl;

}
