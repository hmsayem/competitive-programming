#include<bits/stdc++.h>
using namespace std;

int n1,n2;
string x,y,ans;
int dp[105][105];
string s[105][105];


int main()
{

    cin>>x>>y;
    n1=x.length();
    n2=y.length();

    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;

            else if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                s[i][j]=s[i-1][j-1]+x[i-1];
            }
            else{

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

                if(dp[i-1][j]>dp[i][j-1])
                    s[i][j]=s[i-1][j];

                else if(dp[i-1][j]<dp[i][j-1])
                    s[i][j]=s[i][j-1];

                else
                {
                    if(s[i-1][j]<s[i][j-1])
                        s[i][j]=s[i-1][j];
                    else
                        s[i][j]=s[i][j-1];
                }
            }
        }
    }

    cout<<s[n1][n2]<<endl;
}
