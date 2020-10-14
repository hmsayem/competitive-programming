#include<bits/stdc++.h>
using namespace std;
void compress(int data[],int compressed[],int size, map <int,int> &mp)
{
    int assign=0,c=0,temp;
    for(int i=0;i<size;i++)
    {
        temp=data[i];
        if(mp.find(temp)==mp.end())
            mp[temp]=assign++;

        temp=mp[temp];
        compressed[c++]=temp;
    }
}
int main()
{
    int size=10;
    int data[size]={-102,1,134565589,134565589,-102,66666668,134565589,66666668,-102,1};
    int compressed[size];
    map<int,int> mp;
    compress(data,compressed,size,mp);
    
    for(int i=0; i<size; i++)
        cout<<compressed[i]<<" ";
    cout<<endl;
}
