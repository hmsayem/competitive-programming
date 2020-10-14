#include<bits/stdc++.h>

using namespace std;

#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int data[201];
int n,q,d,m;
int dp[201][21][11];

int div(int i, int sum, int cnt)
{
    if(cnt==m)
    {
        if(sum==0)
            return 1;
        else
            return 0;
    }
    if(i==n)
        return 0;

    if(dp[i][sum][cnt]!=-1)
        return dp[i][sum][cnt];

    int res1=0,res2=0;
    int mod=(sum+data[i])%d;
    if(mod<0) mod+=d;
    res1=div(i+1,mod,cnt+1);
    res2=div(i+1,sum,cnt);

    return dp[i][sum][cnt]=res1+res2;

}
int main()
{
    FastRead;
    int SET=1;
    while(cin>>n>>q && (n||q))
    {
        REP(i,n)
            cin>>data[i];
        cout<<"SET "<<SET++<<":"<<endl;
        REP(i,q)
        {
            cin>>d>>m;
            MEM(dp,-1);
            cout<<"QUERY "<<i+1<<": "<<div(0,0,0)<<endl;
        }
    }
}


