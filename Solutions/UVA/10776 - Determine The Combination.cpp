#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int r;
string sub;
set <string> st;
void subs(int index)
{

    if(sub.length()==r){
       st.insert(sub);
        return;
    }
    while(index<n)
    {
        sub.push_back(s[index]);
        subs(index+1);
        char temp=sub.back();
        sub.pop_back();
        index++;
        if(s[index]==temp)
           index++;
    }
}
int main()
{
    while(cin>>s>>r)
    {
        st.clear();
        n=s.length();
        sort(s.begin(),s.end());
        subs(0);
        for(auto i: st)
            cout<<i<<endl;
    }
}
