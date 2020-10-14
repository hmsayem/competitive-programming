#include<bits/stdc++.h>

using namespace std;
#define MX 10000
void counting_sort(int data[], int n)
{
    int cnt[MX];
    for(int i=0;i<n;i++)
        cnt[data[i]]++;
    for(int i=0;i<MX;i++)
        cnt[i]+=cnt[i-1];
    int res[n];
    for(int i=0;i<n;i++)
        res[cnt[data[i]]--]=data[i];
    for(int i=0;i<n;i++)
        data[i]=res[i+1];
}
int main()
{
    int data[]={0,0,4,2,10,6,6};
    counting_sort(data,7);
    for(int i=0;i<7;i++)
        cout<<data[i]<<" ";
}
