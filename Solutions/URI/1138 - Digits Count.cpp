#include <bits/stdc++.h>
using namespace std;
#define power(n,i)      (long long)ceil(pow(n,i))

long long nck[12][12];
long long dp[12];
long long zero_dp[12];

void generate_nck () {
    nck[0][0] = 1;
    for ( int n = 1; n <12; n++ ) {
        nck[n][0] = 1;
        for ( int k = 1;k<=n; k++ ) {
            nck[n][k] = nck[n-1][k] + nck[n-1][k-1];
        }
    }
}
int get_digit(long long x, int i)
{
    x=x%power(10,i);
    x/=power(10,i-1);
    return (int)x;
}
long long count_digit(int len)
{
    long long temp,sum=0;
    for(int i=1;i<=len;i++){
        temp=nck[len][i]*power(9,len-i);
        sum+=i*temp;
    }
    return sum;
}
int NOD(long long x)
{
    int cnt=0;
    while(x!=0)
    {
        x=x/10;
        cnt++;
    }
    return cnt;
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
void ZERO_DP()
{
    zero_dp[1]=1;
    for(int i=2;i<12;i++)
        zero_dp[i]=9*count_zero(i-1)+zero_dp[i-1];
}
long long zero(long long x)
{
    if(x<0)
        return 0;
    if(x<10)
        return 1;

    int digits=NOD(x);
    long long ans=zero_dp[digits-1];
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
long long total(long long n,int x)
{
    if(n<10)
    {
        if(x<=n)
            return 1;
        else
            return 0;
    }
    int digits=NOD(n);
    long long ans=dp[digits-1];
    int msb=get_digit(n,digits);
    ans+=(msb-1)*dp[digits-1];
    if(msb-1>=x)
        ans+=power(10,digits-1);
    if(msb==x)
        ans+=n%power(10,digits-1)+1;
    for(int i=digits-1;i>=1;i--)
    {
        int d=get_digit(n,i);
        ans+=d*dp[i-1];
        if(d==x)
            ans+=n%power(10,i-1)+1;
        else if(d>x)
            ans+=power(10,i-1);
    }
    return ans;
}
void DP()
{
    dp[1]=1;
    for(int i=2;i<12;i++)
        dp[i]=count_digit(i);
}
int main()
{
    generate_nck();
    DP();
    ZERO_DP();
    long long l,r;
    while(cin>>l>>r)
    {
        if(l==0 and r==0)
            break;
       cout<<zero(r)-zero(l-1)<<" ";
       for(int i=1;i<=9;i++){
            if(i<9)
                cout<<total(r,i)-total(l-1,i)<<" ";
            else
                cout<<total(r,i)-total(l-1,i);
       }
        cout<<endl;
    }
}
