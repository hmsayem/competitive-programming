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
#define bug()           cerr<<"**********\n";
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;
#define SIZE(v)         (int)v.size()

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())
#define minimum(a)      *min_element(a.begin(), a.end())
#define maximum(a)      *max_element(a.begin(), a.end())
#define all(v)          v.begin(),v.end()

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ll, ll > pll;
typedef pair < int,int> pii;

const ll inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;


int data[205][205];
long long DP[205][205];
int n,c,r;
bool valid(int i, int j)
{
    if(data[i][j]<=0)
        return false;
    else
        return true;

}
int call (int i, int j)
{
    if(valid(i,j))
    {

        if(DP[i][j]!=-1)
            return DP[i][j];
        int res=-inf;

        res= max(res,call(i+1,j)+data[i][j]);
        if(i<n)
            res= max(res,call(i+1,j+1)+data[i][j]);
        else if(j>1)
            res= max(res,call(i+1,j-1)+data[i][j]);

        DP[i][j]=res;

        return DP[i][j];
    }
    else
        return 0;

}
int main()
{
    
    cases
    {
        MEM(data,0);
        MEM(DP,-1);

        cin>>n;
        r=2*n-1;
        for(int i=1;i<=r;i++)
        {
            if(i<=n)
                c=i;
            else
                c=r-i+1;
            for(int j=1;j<=c;j++)
            {
                cin>>data[i][j];
            }
         }
         printCase(call(1,1));
    }
}
