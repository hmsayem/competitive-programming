#include <bits/stdc++.h>
using namespace std;

int data[1005][1005];
int aux[1005][1005];

void preprocess(int n, int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            aux[i+1][j+1]=data[i][j]+aux[i][j+1]+aux[i+1][j]-aux[i][j];
}

int query(int r1, int c1, int r2, int c2)
{

        r1++;
        c1++;
        r2++;
        c2++;

        return aux[r2][c2]-aux[r1-1][c2]-aux[r2][c1-1]+aux[r1-1][c1-1];
}

int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin>>data[i][j];

    preprocess(n,m);

    int r1,r2,c1,c2;
    while(cin>>r1>>c1>>r2>>c2)
    {
        cout<<query(r1,c1,r2,c2)<<endl;
    }
}
