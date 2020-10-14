#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int MAX = 1e5 + 5;
bool marked[MAX];
vector <PII> adj[MAX];

int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    int minimum_cost=0; 
    PII p;
    pq.push({0,x});

    while(!pq.empty())
    {
        p=pq.top();
        q.pop();
        u=p.second;

        if(marked[u]) continue;
        minimum_cost+=p.first;
        marked[u]=true;

        for(int i=0;i<adj[u].size();i++)
        {
            x=adj[u][i].first;
            if(!marked[x])pq.push{adj[u][i]};
        }
    }
    return minimum_cost;
}

int main()
{     
    int nodes,edges,x,y,weight;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back({weight,y});
        adj[y].push_back({weight,x});
    }
    cout<<prim(1)<<endl;
}
