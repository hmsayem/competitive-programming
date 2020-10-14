#include<bits/stdc++.h>
using namespace std;
long long phi[1000005];

void computeTotient(int n)
{
    for (int i=1; i<=n; i++)
        phi[i] = i;

    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}

int dp[1000005];

int go(int n)
{

    if(n==1)
        return 0;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n]=1+go(phi[n]);


}
vector <int> v[1000005];

int main()
{

    computeTotient(1000000);
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=1000000;i++)
        v[go(i)].push_back(i);

    int T,m,n,k;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d %d",&m,&n,&k);

        auto st=lower_bound(v[k].begin(),v[k].end(),m);
        int L=st-v[k].begin();
        auto lt=lower_bound(v[k].begin(),v[k].end(),n);
        int R=lt-v[k].begin();

        if(st!=v[k].end())
        {
            if(*st<=n)
            {
                if(lt==v[k].end())  printf("%d\n",v[k].size()-L);

                else if(*lt==n) printf("%d\n",R-L+1);

                else  printf("%d\n",R-L);
            }
            else  printf("0\n");
        }
        else  printf("0\n");
    }
}
