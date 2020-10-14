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
#define SIZE(v)         (int)v.size()

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define all(v)          v.begin(),v.end()
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int  n,f;
int  data[50];
bool checkminus[50];
bool checkplus[50];

map <int,vector<int>> v;

bool check ( int n, int k)
{
    return n & (1<<k-1);
}
int bitOn(int n, int k)
{
    return n | (1<<k-1);
}
int bitOff(int n, int k)
{
    if(check(n,k))
        return n ^ (1<<k-1);
    else
        return n;
}
void cash(int i,int len,int mask, int m)
{

    if(i==len)
    {
        int sum=0;

        if(len==n/2){

            for(int j=(n/2)-1,m=1;j>=0;j--,m++)
            {
                if(check(mask,m))
                    sum+=data[j];
                else
                    sum-=data[j];
            }
            v[sum].pb(mask);
        }

        else{
                for(int j=n-1,m=1;j>=n/2;j--,m++)
                {
                    if(check(mask,m))
                        sum+=data[j];
                    else
                        sum-=data[j];
                }

            auto it1=v.find(f-sum);

            if(it1!=v.end())
            {
                for(auto it2 = it1->ss.cbegin();it2!=it1->ss.cend();it2++)
                {

                        int mask1=*it2;
                        for(int j= (n/2)-1,m=1; j>=0; j--,m++)
                        {
                            if(check(mask1,m))
                                checkplus[j]=true;
                            else
                                checkminus[j]=true;
                        }

                        int mask2=mask;

                        for(int j=n-1,m=1;j>=n/2;j--,m++)
                        {
                            if(check(mask2,m))
                                checkplus[j]=true;
                            else
                                checkminus[j]=true;
                        }
                    }
                }
        }
        return;
    }

    mask = bitOff(mask,m);
    cash(i+1,len,mask,m+1);
    mask = bitOn(mask,m);
    cash(i+1,len,mask,m+1);
}

int main()
{
    while(sf("%d %d",&n,&f))
    {
        if(n==0 && f==0)
            break;
            
        v.clear();
        MEM(checkplus,0);
        MEM(checkminus,0);

        REP(i,n)
        {
            cin>>data[i];
        }

        cash(0,n/2,0,1);
        cash(n/2,n,0,1);
        int cnt=0;

        REP(i,n)
        {
            if(checkminus[i]==false && checkplus[i]==false)
                cnt++;
        }

        if(cnt==n)
            pf("*\n");
            
        else{

            REP(i,n)
            {
                if(checkminus[i]==true && checkplus[i]==false)
                    pf("-");
                if(checkminus[i]==false && checkplus[i]==true)
                    pf("+");
                else if(checkminus[i]==true && checkplus[i]==true)
                    pf("?");
            }
            pf("\n");
        }
    }
}
