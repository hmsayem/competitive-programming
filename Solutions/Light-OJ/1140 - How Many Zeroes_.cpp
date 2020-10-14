#include<bits/stdc++.h>
using namespace std;

#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)
#define power(n,i)      (long long)ceil(pow(n,i))
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;

long long nck[12][12];
long long dp[12];

void generate_nck () {
    nck[0][0] = 1;
    for ( int n = 1; n <12; n++ ) {
        nck[n][0] = 1;
        for ( int k = 1;k<=n; k++ ) {
            nck[n][k] = nck[n-1][k] + nck[n-1][k-1];
        }
    }
}

long long count_zero(int len)
{
    long long temp,sum=0;
    for(int i=1;i<=len;i++){
        temp=nck[len][i]*power(9,len-i);
        sum+=i*temp;
    }

    return sum;
}

void DP()
{
    dp[1]=1;
    for(int i=2;i<12;i++)
        dp[i]=9*count_zero(i-1)+dp[i-1];
}
int digit_count(long long x)
{
    int cnt=0;
    while(x!=0)
    {
        x=x/10;
        cnt++;
    }
    return cnt;
}
int get_digit(long long x, int i)
{

    x=x%power(10,i);
    x/=power(10,i-1);
    return (int)x;
}

long long total(long long x)
{
    if(x<0)
        return 0;
    if(x<10)
        return 1;
    
    int digits=digit_count(x);
    long long ans=dp[digits-1];
    int msb=get_digit(x,digits);
    ans+=(msb-1)*count_zero(digits-1);
    
    for(int i=digits-1;i>=1;i--)
    {
        int d=get_digit(x,i);
        if(i==1)
            ans++;
        else if(d==0)
            ans+=x%power(10,i)+1;
        else if(d>0)
            ans+=power(10,i-1)+ d*count_zero(i-1);

    }
    return ans;
}
int main()
{
    FastRead;
    generate_nck();
    DP();
    cases
    {
        long long a,b;
        cin>>a>>b;
        printCase(total(b)-total(a-1));
    }
}


