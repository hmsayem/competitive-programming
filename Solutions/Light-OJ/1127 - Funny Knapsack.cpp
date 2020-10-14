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
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define cases           int T;sf("%d",&T);for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define bug()           cerr<<"**********\n";
#define printCase(x)    pf("Case %d: %d\n",TC,x)

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

int arr[35];
int n;
long long w;
vector <long long> v1;
vector <long long> v2;
void powerSet(int index,long long sum,int len)
{
    if(index==len){

        if(len==n/2)
            v1.pb(sum);
        else
            v2.pb(sum);
    }
    else{
        powerSet(index+1,sum,len);
        powerSet(index+1,sum+arr[index],len);
    }
}
int main()
{
   cases
   {
       v1.clear();
       v2.clear();
       sf("%d %lld",&n,&w);

       for(int i=0;i<n;i++)
        sf("%d",&arr[i]);

       powerSet(0,0,n/2);
       powerSet(n/2,0,n);

       sort(v2.begin(),v2.end());
       int cnt=0;

       for(int i=0;i<v1.size();i++)
       {
            long long diff=w-v1[i];
            cnt+=upper_bound(v2.begin(),v2.end(),diff)-v2.begin();
       }
       printCase(cnt);
   }
}
