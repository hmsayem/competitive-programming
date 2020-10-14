const ll inf = 2147383647;
int c[10];
int dp[10][100];
int len,to_make;
int coin(int i, int to_make)
{

    if(i==len)
    {
        if(to_make==0)
            return 0;
        else
            return inf;
    }

    if(dp[i][to_make]!=-1)
       return dp[i][to_make];

    int ans1=inf,ans2;

    if(to_make-c[i]>=0)
    {
       ans1= coin(i,to_make-c[i])+1;
    }

    ans2=coin(i+1,to_make);
    
    return dp[i][to_make]=min(ans1,ans2);
}


int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>len>>to_make;
    
    for(int i=0;i<len;i++)
        cin>>c[i];
    
    cout<<coin(0,to_make)<<endl;
}
