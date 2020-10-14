#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<vector<int> > g;
vector <int> level;
map <long long, int> mp;
int bfs(int source, int ttl)
{
    queue<int> q;
    level[source] = 0;
    q.push(source);
    int cnt=0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v = g[u].begin(); v != g[u].end(); v++) {
            if (level[*v]==inf) {
                level[*v]=level[u]+1;
                if(level[*v]<=ttl) cnt++;
                q.push(*v);
            }
        }
    }
    return cnt;
}
int main()
{
    int nc, e;
    int TC=1;
    while(cin>>nc,nc)
    {
        g.assign(30, vector<int>());
        mp.clear();
        int a, b,assign=0;
        for (int i = 0; i < nc; i++)
        {
            cin >> a >> b;
            if(mp.find(a)==mp.end())  mp[a]=assign++;
            if(mp.find(b)==mp.end())  mp[b]=assign++;
            g[mp[a]].push_back(mp[b]);
            g[mp[b]].push_back(mp[a]);
        }
        int start,ttl;
        while(cin>>start>>ttl)
        {
            if(start==0 && ttl==0)
                break;
            level.assign(30, inf);
            if(a==0 && b==0)
                break;
            int ans= mp.size()-bfs(mp[start],ttl)-1;
            cout<<"Case "<<TC++<<": "<<ans<<" nodes not reachable from node "<<start<<" with TTL = "<<ttl<<"."<<endl;
        }
    }
}
