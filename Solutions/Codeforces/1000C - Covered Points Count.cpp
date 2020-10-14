#include <bits/stdc++.h>
using namespace std;
vector < pair<long long, int> > v;
long long answer[200005];
int main()
{
    int n;
    scanf("%d",&n);
    long long l,r;

    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&l,&r);
        v.push_back({l,1});
        v.push_back({r+1,-1});
    }

    sort(v.begin(),v.end());
    int count=1;

    for(int i=1;i<v.size();i++)
    {
        answer[count]+=v[i].first-v[i-1].first;
        count+=v[i].second;
    }

    for(int i=1;i<=n;i++)
        printf("%lld ",answer[i]);

    cout<<endl;
}
