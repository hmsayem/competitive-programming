#include<bits/stdc++.h>

using namespace std;

const int MAX=100001;
long long data[MAX];
long long tree[MAX*4];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=data[b];
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

long long query(int node, int b, int e, int i, int j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
       return tree[node];
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    long long p1=query(left,b,mid,i,j);
    long long p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update (int node, int b, int e, int i, long long x)
{
    if(b>i || e<i)
        return;
    if(b==i && e==i)
    {
        tree[node]=x;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node]=tree[left]+tree[right];
}
int main()
{

}
