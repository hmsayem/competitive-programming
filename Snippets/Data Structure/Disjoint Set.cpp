#include<bits/stdc++.h>
using namespace std;
int parent[100005];
int Find(int r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}
void Union(int a, int b)
{
    int u=Find(a);
    int v=Find(b);
    parent[u]=v;
}
int main()
{

}
