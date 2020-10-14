#include<bits/stdc++.h>
using namespace std;

int dis[10005];
int fuel[10005];

int main()
{

     int T;
     scanf( "%d", &T );

     while(T--)
     {
         int n, l, p;
         scanf( "%d", &n );
         for(int i=0;i<n;i++)   scanf( "%d %d", &dis[i], &fuel[i] );

         scanf( "%d %d", &l, &p );

         vector < pair < int, int > >v;

         for( int i=0; i < n; i++)  v.push_back( { l-dis[i], fuel[i] } );

         sort( v.begin(), v.end() );

         priority_queue < pair < int, int > > pq;

         int sum = p;
         int cnt = 0;
         bool flag = true;

         for( int i=0; i<v.size();)
         {
             if( sum >= l ) break;

             while( i<n && v[i].first <= sum )
             {
                 pq.push( { v[i].second, v[i].first } );
                 i++;

                 if(i==n)
                 {
                     break;
                 }
             }

             if( pq.empty() )
             {
                 cnt = -1;
                 break;
             }
             sum += pq.top().first;
             pq.pop();
             cnt++;
         }
        printf( "%d\n", cnt );
     }
}
