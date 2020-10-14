#include<bits/stdc++.h>
using namespace std;

int data[100005];

int main()
{

     int n,x;
     while( scanf("%d",&n) && n)
     {
         queue < pair < int, int > > q1;
         queue < pair < int, int > > q2;

         for( int i = 0; i < n; i++ ) {
            cin >> x;
            if( x > 0 ) q1.push( { i, x } );
            else if( x < 0) q2.push( { i, x } );
         }

         long long sum=0;
         while( !q1.empty() )
         {
             int id = q1.front().first;
             int val = q1.front().second;
             
             while(!q2.empty())
             {
                 if( val + q2.front().second > 0 )
                 {
                     val += q2.front().second;
                     sum += -q2.front().second * abs( q2.front().first - id );
                     q2.pop();
                 }
                 else
                 {
                     q2.front().second += val;
                     sum += val * abs( q2.front().first - id );
                     q1.pop();
                     break;
                 }
             }
         }
         printf("%lld\n",sum);
     }
}
