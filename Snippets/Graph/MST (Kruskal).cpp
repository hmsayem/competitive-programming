#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+5;
pair< int, pair<int,int> > p[MAX];
int parent[MAX],nodes,edges;


int Find(int r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}

void Union(int a, int b)
{
    int u=Find(a);
    int v=Find(b);
    parent[u]=v;
}
void init()
{
    for(int i=0;i<MAX;i++)
        parent[i]=i;
}

long long kruskal()
{

    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
}
int main()
{

    int x,y,weight;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>x>>y>>weight;
        p[i]={weight,{x,y}};
    }
    sort(p,p+edges);
}
