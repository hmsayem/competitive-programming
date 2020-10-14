#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define mk              make_pair

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
#define foreach(v, c)   for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define FABS(x)         ((x)+eps<0?-(x):(x))

#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;
#define SIZE(v)         (int)v.size()
#define dump(x)         cerr<<"~ "<<#x<<" = "<<x<<endl

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())
#define minimum(a)      *min_element(a.begin(), a.end())
#define maximum(a)      *max_element(a.begin(), a.end())
#define all(v)          v.begin(),v.end()

#define Set(N,p)        N=((N)((1LL)<<(p)))
#define Reset(N,p)      N=((N)&(~((1LL)<<(p))))
#define Check(N,p)      (!(((N)&((1LL)<<(p)))==(0)))

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ll, ll > pll;
typedef pair < int,int> pii;

const ll inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

#ifdef FACT
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp debug ("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)
     #define bug printf("%d\n",__LINE__);

#else
    #define debug(args...)
    #define timeStamp

#endif

struct debugger{
    template<typename T> debugger & operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int timeCost[35];
int value[35];
int DP[35][1005];
int dir[35][1005];
int t,w,n,d,v;
vector <pii> ans;

int knapsack(int i,int rem)
{
    if(i==n)
        return 0;
    if(DP[i][rem]!=-1)
        return DP[i][rem];
    int profit1=0,profit2;
    if(rem-timeCost[i]>=0)
    {
        profit1=knapsack(i+1,rem-timeCost[i])+value[i];
    }
    profit2=knapsack(i+1,rem);
    if(profit1>profit2)
    {
        dir[i][rem]=1;
    }
    else
    {
        dir[i][rem]=2;
    }
    return DP[i][rem]=max(profit1,profit2);
}

void solution()
{
    ans.clear();
    int i=0,rem=t;

    while(dir[i][rem]!=-1)
    {
        if(dir[i][rem]==1)
        {
            ans.pb({timeCost[i]/(3*w),value[i]});
            rem-=timeCost[i];
            i++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    #ifdef FACT
    //fRead("input.txt");
    //fWrite("output.txt");
    #endif // FACT
    FastRead;
    bool flag=true;
    while(cin>>t>>w>>n)
    {
        MEM(DP,-1);
        MEM(dir,-1);
        for(int i=0;i<n;i++)
        {
            cin>>d>>v;
            value[i]=v;
            timeCost[i]=3*w*d;
        }
        if(flag)
            flag=false;
        else
            cout<<endl;
        cout<<knapsack(0,t)<<endl;
        solution();
        cout<<ans.size()<<endl;
        for(auto x : ans)
            cout<<x.ff<<" "<<x.ss<<endl;
    }
}
