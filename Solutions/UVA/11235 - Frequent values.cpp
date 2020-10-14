#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define pb              push_back
typedef pair < int,int> pii;

const int MAX=100001;
int data[MAX];
int tree[MAX*4];
map <int, pii> range;

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=1;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);

    unordered_map <int,int> mp;
    int MAX=0;
    for(int i=b;i<=e;i++)
    {
        mp[data[i]]++;
        if(mp[data[i]]>MAX)
            MAX=mp[data[i]];
    }
    tree[node]=MAX;
}

int query(int node, int b, int e, int i, int j)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
        return max(tree[node],min(range[data[e]].ss,j)-max(range[data[e]].ff,i)+1);
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    int n,q;
    while(cin>>n,n)
    {
        cin>>q;
        for(int i=1;i<=n;i++){
            cin>>data[i];
            if(range.find(data[i])==range.end())
            {
                range[data[i]].ff=i;
                range[data[i]].ss=i;
            }
            else
                range[data[i]].ss++;
        }
        init(1,1,n);
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r)<<endl;
        }
        range.clear();
    }
}
