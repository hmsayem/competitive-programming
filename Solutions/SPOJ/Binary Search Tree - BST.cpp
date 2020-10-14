#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define FastRead        ios_base::sync_with_stdio(0);
struct node
{
    int left=0;
    int right=0;
    long long counter=0;
}q[300001];

int main()
{
    int n,data;
    scanf("%d %d",&n,&data);
    printf("0\n");

    set < int > s;
    set < int > :: iterator it;

    s.insert(data);
    
    long long ans=0;

    for(int i=1;i<n;i++)
    {

        scanf("%d",&data);
        it=s.upper_bound(data);

        if(it==s.begin())
        {
            q[*it].left=data;
            q[data].counter=q[*it].counter+1;
        }
        else if(it!=s.end())
        {
            if(q[*it].left==0)
            {
                q[*it].left=data;
                q[data].counter=q[*it].counter+1;
            }
            else
            {
                it--;
                q[*it].right=data;
                q[data].counter=q[*it].counter+1;
            }
        }
        else
        {
            it--;
            q[*it].right=data;
            q[data].counter=q[*it].counter+1;
        }
        
        s.insert(data);
        ans+=q[data].counter;
        printf("%lld\n",ans);
    }
}
