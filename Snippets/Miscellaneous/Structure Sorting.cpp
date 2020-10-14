#include<bits/stdc++.h>
using namespace std;

struct node
{
    int a;
    int b;
    int c;

    bool operator<(node & x) const
    {
        if(a==x.a)
            if(b==x.b)
                return c<x.c;
            else
                return b<x.b;
        else
            return a<x.a;
    }
};

bool cmp(node x , node y)
{
    if(x.a==y.a)
        if(x.b==y.b)
            return x.c<y.c;
        else
            return x.b<y.b;
    else
        return x.a<y.a;
}
int main()
{
    node v[100];
    sort(v,v+100,cmp);
}
