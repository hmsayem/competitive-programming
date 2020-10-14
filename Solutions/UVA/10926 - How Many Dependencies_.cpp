#include<bits/stdc++.h>

using namespace std;

int DP[105][105];
vector <int> v[105];
int mark;

void depend(int i)
{
    if(DP[mark][i]==1)
        return;

    for(int j=0;j<v[i].size();j++)
    {
        depend(v[i][j]);
        DP[mark][v[i][j]]=1;
    }
}

int main()
{
    int n,x;
    while(cin>>n,n)
    {
        memset(DP,0,sizeof(DP));
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            v[i].resize(x);
            for(int j=0;j<x;j++)
                cin>>v[i][j];
        }

        for(int i=1;i<=n;i++)
        {
            mark=i;
            depend(i);
        }

        int MAX=0;
        int ans,cnt;
        for(int i=1;i<=n;i++)
        {
            cnt=0;

            for(int j=1;j<=n;j++)
                cnt+=DP[i][j];

            if(cnt>MAX)
                MAX=cnt,ans=i;
        }
        cout<<ans<<endl;
    }
}
