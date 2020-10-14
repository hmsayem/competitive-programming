#include<bits/stdc++.h>

using namespace std;
#define MAX 100005
int data[MAX];
long long tree[MAX];

long long query(int idx)
{
    long long sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-= idx&(-idx);
    }
    return sum;
}
void update(int idx, int x,int n)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+=idx&(-idx);
    }
}

int main()
{
    int n=5;
    for(int i=1;i<=n;i++){
        cin>>data[i];
        update(i,data[i],n);
    }
    cout<<query(5)<<endl;
    update(3,100,5);
    update(1,200,5);
    cout<<query(5);
}
