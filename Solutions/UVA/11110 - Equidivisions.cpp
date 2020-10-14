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

#define cases           int T;sf("%d",&T);for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define bug()           cerr<<"**********\n";
#define printCase(x)    pf("Case %d: %d\n",TC,x)

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define all(v)          v.begin(),v.end()
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);

int arr[100][100];
int visited[100][100];
int n,cnt;
bool valid(int i, int j, int k)
{
    if(i==n+1 || j==n+1 || i<1 || j<1 || arr[i][j]!=k || visited[i][j]==true)
        return false;
    else
        return true;

}
void floodfill(int i,int j,int k)
{
    if(!valid(i,j,k))
        return;
    visited[i][j]=true;
    cnt++;
    floodfill(i-1,j,k);
    floodfill(i,j-1,k);
    floodfill(i,j+1,k);
    floodfill(i+1,j,k);

}
int main()
{

    int x,y;
    string s;
    while(sf("%d",&n) && n!=0)
    {
        MEM(visited,0);
        MEM(arr,0);
        getchar();
        for(int i=1;i<=n-1;i++)
        {
            getline(cin,s);
            stringstream ss(s);
            while(ss>>x>>y)
            {
                arr[x][y]=i;
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(visited[i][j]==false ){
                    cnt=0;
                    floodfill(i,j,arr[i][j]);
                    if(cnt!=n)
                        flag=false;
                }
            }
        }
        if(flag)
            pf("good\n");
        else
            pf("wrong\n");
    }
}
