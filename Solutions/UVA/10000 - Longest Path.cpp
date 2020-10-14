#include<bits/stdc++.h>
using namespace std;
#define FastRead  ios_base::sync_with_stdio(0);cin.tie(nullptr)
int n,s,p,q;
vector < vector <int> > v;
int dp[105];
int call(int x)
{

    if(dp[x]!=-1)
        return dp[x];
    int res=-1;
    for(int i=0;i<v[x].size();i++)
    {
        int temp=call(v[x][i])+1;
        res=max(temp,res);
    }
    return dp[x]=res;
}
int main()
{
   FastRead;
   int TC=1;
   while(cin>>n,n)
   {
        v.assign(n+1,vector<int>());
        cin>>s;
        int p=1,q=1;

        while(p||q)
        {
            cin>>p>>q;
            v[p].push_back(q);
        }
        int maximum=-1;
        int finish;
        for(int i=1;i<=n;i++)
        {
            memset(dp,-1,sizeof(dp));
            dp[i]=0;
            if(call(s)>maximum)
            {
                maximum=call(s);
                finish=i;
            }
        }
        cout<<"Case "<<TC++<<": The longest path from "<<s<<" has length "<<maximum<<", finishing at "<<finish<<"."<<endl<<endl;
   }
}
