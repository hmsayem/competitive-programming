#include<bits/stdc++.h>
using namespace std;
#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n)
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int data[105];
double dp[105];

int main()
{
    FastRead;

    cases
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>data[i];
        for(int i=n;i>=1;i--)
        {
            int outcomes=6;
            if(n-i<6)
                outcomes=n-i;
            double sum=data[i];
            for(int j=i+1;j<=n && j<=i+6;j++)
                sum+=dp[j]/outcomes;
            dp[i]=sum;
        }
        precision(6);
        cout<<"Case "<<TC<<": "<<dp[1]<<endl;
    }
}


