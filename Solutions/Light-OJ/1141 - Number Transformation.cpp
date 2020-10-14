#include<bits/stdc++.h>
using namespace std;
#define sz 100
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};


int visit[1005];
vector <int> prime;
vector <int> factor[1005];

int bfs(int s, int t)
{
    memset(visit, 0, sizeof(visit));
    queue< pair <int,int> > q;

    q.push({s,0});
    visit[s] = 1;

    int ans = 1000;

    while (!q.empty())
    {
        pair <int,int> u = q.front();
        q.pop();

        if( u.first == t) ans = min(ans, u.second);

        for(int i = 0; i < factor[u.first].size(); i++)
        {
            int v = u.first + factor[u.first][i];

            if( v <= t && visit[v] == 0)
            {
               visit[v] = 1;
               q.push({v,u.second+1});
            }
        }
    }
    return ans;
}
void gen_primes()
{
    for(int i = 2; i <= 1000; i++)
    {
        bool flag = true;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i%j == 0) flag = false;
        }
        if(flag) prime.push_back(i);
    }
}

void gen_factors()
{
    for(int i = 2; i <= 1000; i++)
    {
      for(int j: prime)
      {
        if(i % j == 0 && j < i)
            factor[i].push_back(j);
      }
    }
}
int main()
{
    int tc,s,t;
    gen_primes();
    gen_factors();

    cin >> tc;
    for(int k = 1; k <= tc; k++)
    {
        cin >> s >> t;
        int ans = bfs(s,t);
        if(ans == 1000) ans = -1;
        cout << "Case " << k << ": " << ans << endl;
    }
}
