#include<bits/stdc++.h>
using namespace std;

int n1,n2,MAX,start=-1;
int a1[5005];
int a2[5005];
int data[5005];
int dp[5005];
vector<pair<int,int>>parent[5005];

void path_print()
{
    vector <int> v;
    while(start!=-1)
    {
        v.push_back(a2[start]);
        MAX--;
        for(int i=0;i<(int)parent[start].size();i++)
        {
            if(parent[start][i].second==MAX)
            {
                start=parent[start][i].first;
                break;
            }
        }
    }

    reverse(v.begin(),v.end());

    for(int i=0; i<(int)v.size();i++)
        printf("%d ",v[i]);
}
int main()
{

    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
        scanf("%d",&a1[i]);
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
        scanf("%d",&a2[i]);

    for(int i=0;i<n1;i++)
    {
        int take=0;
        int p=-1;
        for(int j=0;j<n2;j++)
        {
            if(a1[i]==a2[j]){
                parent[j].push_back({p,take}); 
                dp[j]=take+1;
                data[j]=a1[i];
                if(dp[j]>MAX){
                    start=j;
                    MAX=dp[j];
                }
            } 
            else if(dp[j]>take && data[j]<a1[i]){
                take=dp[j];
                p=j;
            }
        }
    }

    printf("%d\n",MAX);
    path_print();
}
