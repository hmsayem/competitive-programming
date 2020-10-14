#include<bits/stdc++.h>

using namespace std;

const int MAX=100001;
int data[MAX];
struct info
{
    long long sum;
    long long propagate=0;
}tree[MAX*4];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].sum=data[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update (int node, int b, int e, int i, int j, long long x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].propagate+=x;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+ (e-b+1)*tree[node].propagate;

}
long long query(int node, int b, int e, int i, int j, long long carry)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    long long p1=query(left,b,mid,i,j,carry+tree[node].propagate);
    long long p2=query(right,mid+1,e,i,j,carry+tree[node].propagate);
    return p1+p2;
}
int main()
{
    
}
