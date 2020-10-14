#include<bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int cp[1005][1005];
const int mod=1000007;
int n1,n2;

int main()
{
    string a;
    string b;
    cin>>a>>b;
    n1=a.length();
    n2=b.length();

    for(int i=0;i<=n1;i++)
    {

        for(int j=0;j<=n2;j++)
        {
            if(i==0 || j==0){
                dp[i][j]=0;
                cp[i][j]=1;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                cp[i][j]=cp[i-1][j-1];
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    cp[i][j]=cp[i-1][j];
                }
                else if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    cp[i][j]=cp[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    if(dp[i-1][j]==dp[i-1][j-1])
                        cp[i][j]=(((cp[i-1][j]+cp[i][j-1])%mod-cp[i-1][j-1])%mod+mod)%mod;
                    else
                        cp[i][j]=(cp[i-1][j]+cp[i][j-1])%mod;
                }
            }
        }
    }
    cout<<cp[n1][n2]<<endl;
}
