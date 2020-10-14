#include<bits/stdc++.h>

using namespace std;

const int MAX=100001;

int data[MAX];
struct info
{
    long long propagate=0;
    int c0=0;
    int c1=0;
    int c2=0;

}tree[MAX*4];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].c0=1;
        tree[node].c1=0;
        tree[node].c2=0;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].c0=tree[left].c0+tree[right].c0;
    tree[node].c1=tree[left].c1+tree[right].c1;
    tree[node].c2=tree[left].c2+tree[right].c2;
}
void update (int node, int b, int e, int i, int j, long long x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].propagate+=x;

        if(x%3==1)
        {
            int temp=tree[node].c1;
            tree[node].c1=tree[node].c0;
            tree[node].c0=tree[node].c2;
            tree[node].c2=temp;
        }
        else if(x%3==2)
        {
            int temp=tree[node].c0;
            tree[node].c0=tree[node].c1;
            tree[node].c1=tree[node].c2;
            tree[node].c2=temp;
        }
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);

    tree[node].c0=tree[left].c0+tree[right].c0;
    tree[node].c1=tree[left].c1+tree[right].c1;
    tree[node].c2=tree[left].c2+tree[right].c2;

    if(tree[node].propagate%3==1)
    {
        int temp=tree[node].c1;
        tree[node].c1=tree[node].c0;
        tree[node].c0=tree[node].c2;
        tree[node].c2=temp;
    }
    else if(tree[node].propagate%3==2)
    {
        int temp=tree[node].c0;
        tree[node].c0=tree[node].c1;
        tree[node].c1=tree[node].c2;
        tree[node].c2=temp;
    }

}
int query(int node, int b, int e, int i, int j, long long carry)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        if(carry%3==1)
            return tree[node].c2;
        else if(carry%3==2)
            return tree[node].c1;
        else
            return tree[node].c0;

    }

    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;

    int p1=query(left,b,mid,i,j,carry+tree[node].propagate);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].propagate);

    return p1+p2;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif
    int n,q;
    cin>>n>>q;
    init(1,0,n-1);
    for(int i=1;i<=q;i++)
    {
        int c,l,r;
        cin>>c>>l>>r;
        if(c==0)
            update(1,0,n-1,l,r,1);
        else
            cout<<query(1,0,n-1,l,r,0)<<endl;
    }
}
