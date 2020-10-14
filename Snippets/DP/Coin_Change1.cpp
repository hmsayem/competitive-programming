int coin[]={5,8,11,15,18};
int N,make;
int DP[6][100];
int call(int i,int amount)
{
    if(i>=N) {

        if(amount==0)return 1;
        else return 0;
    }
    if(DP[i][amount]!=-1)
        return DP[i][amount];

    int ret1=0,ret2=0;
    if(amount-coin[i]>=0)
        ret1=call(i,amount-coin[i]);

    ret2=call(i+1,amount);

    return DP[i][amount]=ret1+ret2;

}
int main()
{
    memset(DP,-1,sizeof(DP));
    N=5;
    while(cin>>make)
    {
        cout<<call(0,make)<<endl;
    }
    return 0;
}
