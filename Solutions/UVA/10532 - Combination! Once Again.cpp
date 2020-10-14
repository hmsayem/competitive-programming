#include<bits/stdc++.h>
using namespace std;
#define pb              push_back
#define MEM(a,x)        memset(a,x,sizeof(a))
typedef long long ll;

int labels[51];
vector<int> v;
int n,m,x;
ll DP[51][51];

long long comb(int i, int sum)
{
    if(DP[i][sum]!=-1)
        return DP[i][sum];
    if(i==v.size())
    {
        if(sum==x)
            return 1;
        else
            return 0;
    }
    ll res=0;
    for(int j=0;j<=v[i];j++)
    {
        res+=comb(i+1,sum+j);
    }
    return DP[i][sum]=res;

}
void CLR()
{
    MEM(labels,0);
    v.clear();
}
int main()
{
    int TC=1;
    while(cin>>n>>m,n)
    {
        CLR();
        for(int i=0;i<n;i++)
        {
            cin>>x;
            labels[x]++;
        }
        for(int i=0;i<=50;i++)
            if(labels[i]>0)
                v.push_back(labels[i]);

        cout<<"Case "<<TC++<<":"<<endl;
        for(int i=0;i<m;i++)
        {
            MEM(DP,-1);
            cin>>x;
            cout<<comb(0,0)<<endl;
        }
    }
}

