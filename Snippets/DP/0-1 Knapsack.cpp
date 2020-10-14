#include <bits/stdc++.h>
using namespace std;

int weight[1005];
int cost[1005];
int DP[1005][1005];
int dir[1005][1005];

int n,k;

int knapsack(int i, int w)
{
    if(i==n)
        return 0;

    if(DP[i][w]!=-1)
        return DP[i][w];

    int profit1=0,profit2=0;

    if(w-weight[i]>=0)
        profit1=knapsack(i+1,w-weight[i])+cost[i];

    profit2=knapsack(i+1,w);

    if(profit1>profit2) dir[i][w]=1;
    else dir[i][w]=2;

    DP[i][w]=max(profit1,profit2);

    return DP[i][w];
}

void solution()
{
    int i=0,w=k;

    while(dir[i][w]!=-1)
    {
        if(dir[i][w]==1)
        {
            cout<<i<<" "<<weight[i]<<" "<<cost[i]<<endl;
            w-=weight[i];
        }
        i++;
    }
}
int main()
{
    memset(DP,-1,sizeof(DP));
    memset(dir,-1,sizeof(dir));
    cin>>k>>n;

    for(int i=0;i<n;i++)
        cin>>weight[i]>>cost[i];

    cout<<"Maximum profit "<<knapsack(0,k)<<endl;
    solution();
}
