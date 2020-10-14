#include<bits/stdc++.h>
using namespace std;

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
#define mod(x, m)       ((((x) % (m)) + (m)) % (m))

#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;
#define watch(x)        cerr << (#x) << " is " << (x) << endl

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())
#define minimum(a)      *min_element(a.begin(), a.end())
#define maximum(a)      *max_element(a.begin(), a.end())
#define all(v)          v.begin(),v.end()
#define power(n,i)      (long long)ceil(pow(n,i))

#define FastRead        ios_base::sync_with_stdio(0)


typedef long long ll;
typedef unsigned long long ull;
typedef pair < ll, ll > pll;
typedef pair < int,int> pii;

const int inf = 0x3f3f3f3f;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

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

int main()
{
    #ifdef FACT
    freopen("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif // FACT

}
