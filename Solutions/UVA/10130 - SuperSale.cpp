#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             2e16
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>

#define sf              scanf
#define pf              printf
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define One(x)          __builtin_popcount(x)
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define bug()           cerr<<"**********\n";
#define printCase(x)    pf("Case %d: %d\n",TC,x)
#define SIZE(v)         (int)v.size()

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define all(v)          v.begin(),v.end()
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int weight[1000];
int cost[1000];
int DP[1000][35];

int T,sum,n,c,g;

int knapsack(int i, int w, int cap)
{
    if(i==n)
        return 0;

    if(DP[i][w]!=-1)
        return DP[i][w];
    
    int profit1=0,profit2=0;

    profit1=knapsack(i+1,w,cap);

    if(w-weight[i]>=0)
        profit2=knapsack(i+1,w-weight[i],cap)+cost[i];

    DP[i][w]=max(profit1,profit2);

    return DP[i][w];

}
int main()
{
    FastRead;

    cases
    {
        MEM(DP,-1);
        cin>>n;

        REP(i,n)
            cin>>cost[i]>>weight[i];

        cin>>g;

        sum=0;
        while(g--)
        {
            cin>>c;
            sum+=knapsack(0,c,c);
        }
        cout<<sum<<endl;
    }

}
