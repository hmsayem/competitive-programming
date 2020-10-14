#include<iostream>
#include<vector>
using namespace std;
#define ABS(x)          ((x)<0?-(x):(x))
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

int main()
{

    FastRead;
    int n,x,y;
    cin>>n;
    vector <int> v[4];

    for(int i=1;i<=5*n;i++)
    {
        cin>>x>>y;

        if(ABS(x)%2==0 && ABS(y)%2==0)    v[0].push_back(i);
        if(ABS(x)%2==1 && ABS(y)%2==1)    v[1].push_back(i);
        if(ABS(x)%2==1 && ABS(y)%2==0)    v[2].push_back(i);
        if(ABS(x)%2==0 && ABS(y)%2==1)    v[3].push_back(i);
    }

    for(int i=0;i<4;i++)
    {
        if(v[i].size()>=n)
        {
            cout<<"OK"<<endl;
            for(int j=0;j<n;j++)
                cout<<v[i][j]<<" ";
            return 0;
        }
    }
}


