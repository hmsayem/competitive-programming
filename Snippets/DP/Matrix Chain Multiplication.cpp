#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;

int row[1000];
int col[1000];
int dp[1000][1000];

int mcm(int BEG, int END)
{
    if(BEG==END)
        return 0;

    if(dp[BEG][END]!=-1)
        return dp[BEG][END];

    int ans=inf;
    for(int MID=BEG; MID<END; MID++)
    {
        int left = mcm(BEG,MID);
        int right= mcm(MID+1,END);
        int res  = left+right+ (row[BEG]*col[MID]*col[END]);
        ans=min(ans,res);
    }
    return dp[BEG][END]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>row[i]>>col[i];
    cout<<mcm(0,n-1)<<endl;
}
