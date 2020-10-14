#include<bits/stdc++.h>
using namespace std;


vector <int> edges[100005];
int dp[100005][2];
int parent[100005];


int mvc(int u, int guard)
{

    
    if(dp[u][guard]!=-1) return dp[u][guard];
    int sum=0;

    for(int i=0;i<edges[u].size();i++) {

        int v=edges[u][i];

        if(parent[u]!=v){
            parent[v]=u;

            if(!guard) sum+=mvc(v,1);
            else       sum+=min(mvc(v,1),mvc(v,0));
        }
    }
    return dp[u][guard]=sum+guard;
}
int main()
{ 
    memset(dp,-1,sizeof(dp));
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout<<min(mvc(1,1),mvc(1,0))<<endl;
}
