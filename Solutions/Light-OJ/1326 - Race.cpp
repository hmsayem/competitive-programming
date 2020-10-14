#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define pb              push_back
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define FABS(x)         ((x)+eps<0?-(x):(x))
#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;
#define dump(x)         cerr<<"~ "<<#x<<" = "<<x<<endl
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)
#define ll              long long
const ll mod=10056;

ll fact[1000001];
ll nck[1001][1001];
ll dp[1001];
void generate_nck () {
    nck[0][0] = 1;
    for ( int n = 1; n <=1000; n++ ) {
        nck[n][0] = 1;
        for ( int k = 1;k<=n; k++ ) {
            nck[n][k] = (nck[n-1][k] + nck[n-1][k-1])%mod;
        }
    }
}

ll race(int n)
{
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        res=(res+(nck[n][i]*race(n-i)))%mod;
    }
    return dp[n]=res;
}
int main()
{
    FastRead;
    generate_nck();
    MEM(dp,-1);
    cases
    {
        int n;
        cin>>n;
        printCase(race(n));
    }
}

