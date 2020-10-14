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


#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int csum[100005];
bool check[100005];
string s;

void doCsum()
{
    for(int i=1;i<s.length();i++)
        csum[i]+=csum[i-1];
}
bool isRight ( char x, char y)
{
    if( (x=='(' && y==')') || (x=='[' && y==']') )
        return true;
    else
        return false;

}
int main()
{

    cin>>s;
    REP(i,s.length())
        if(s[i]=='[')
            csum[i]=1;
    doCsum();
    stack <int> st;
    vector <pii> v;
    vector <pii> f;
    vector <pii> a;
    bool flag=true;
    REP(i,s.length())
    {
        if(s[i]=='(' || s[i] == '[')
            st.push(i);
        else
        {
            if(!st.empty() && isRight(s[st.top()],s[i]))
            {
                v.pb({st.top(),i});
                st.pop();
            }
            else{
                st=stack <int> ();
            }
        }

    }

    SORT(v);
    REP(i,v.size())
    {
        int j=i;
        while(true)
        {
            if(v[i+1].ff>v[j].ff && v[i+1].ss<v[j].ss)
            {
                check[i+1]=true;
                i++;
                if(i==v.size()-1)
                    break;
            }
            else
                break;
        }
    }

    REP(i,v.size())
    {
        if(check[i]==false)
            f.pb({v[i].ff,v[i].ss});
    }
    MEM(check,0);
    int temp=0;

    for(int i=0;i<(int)f.size()-1;i++)
    {
        if(f[i].ss==f[i+1].ff-1)
        {
            check[i+1]=true;

            if(i+1==f.size()-1)
                f[temp].ss=f[i+1].ss;
        }
        else
        {
            f[temp].ss=f[i].ss;
            temp=i+1;
        }
    }

    for(int i=0;i<f.size();i++)
    {
        if(check[i]==false)
            a.pb({f[i].ff,f[i].ss});
    }

    int MAX=0;
    int r,l;
    REP(i,a.size())
    {
       if(f[i].ff==0)
            temp=csum[a[i].ss];
       else
            temp=csum[a[i].ss]-csum[a[i].ff-1];
       if(temp>MAX)
       {
           MAX=temp;
           r=a[i].ff;
           l=a[i].ss;

       }
    }

    if(f.size()==0)
        cout<<"0"<<endl;
    else
    {
        cout<<MAX<<endl;
        for(int i=r;i<=l;i++)
            cout<<s[i];
        cout<<endl;
    }
}
