#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[10][1<<8][1<<8];

bool check ( int n, int k )
{
    return n & ( 1 << k );
}

int toggle ( int n, int k )
{
    return n ^= 1 << k;
}
int bitOn( int n, int k )
{
    return n | ( 1 << k );
}
int bitOff(int n, int k)
{
    if( check ( n, k ) )
        return n ^ ( 1 << k );
    else
        return n;
}


int T,n,m;
char s[10];
int  st[10];

int go( int row, int prevMask, int currMask)
{


    if( row == n ){

        for( int i = 0; i < m ; i++ )
        {
            if( !check( prevMask, i ) )
                return inf;
        }
        return 0;

    }
    if( dp[row][prevMask][currMask] !=- 1) return dp[row][prevMask][currMask];

    int  p1Mask = prevMask, p2Mask = prevMask;
    int  c1Mask = currMask, c2Mask = currMask;
    int  n1Mask = -1, n2Mask = -1;

    if( row < n - 1 )
        n1Mask = st[row+1], n2Mask = st[row+1];


    int cnt1 = 0, cnt2 = 0;
    int cnt = 0;
    int ans = inf;


    for( int j = 0; j < m; j++ )
    {
        int k = m - 1 - j;
        if( k == 0 )
        {
            if( !check( p1Mask, k ) )
                cnt = inf;
                break;
        }

        if( check ( p1Mask, k ) ) continue;
        cnt++;

        p1Mask = toggle( p1Mask, k );

        if( c1Mask != -1 )  c1Mask = toggle( c1Mask, k );
        if( n1Mask != -1 )  n1Mask = toggle( n1Mask, k );

        if( k - 1 >= 0)
        {
            p1Mask = toggle( p1Mask, k - 1 );
            if( c1Mask != -1 )  c1Mask = toggle( c1Mask, k - 1 );
            if( n1Mask != -1 )  n1Mask = toggle( n1Mask, k - 1 );
        }

        if( k-2 >= 0 )
        {
            p1Mask = toggle( p1Mask, k - 2 );
            if( c1Mask != -1 )  c1Mask = toggle( c1Mask, k - 2 );
            if( n1Mask != -1)   n1Mask = toggle( n1Mask, k - 2 );
        }
    }


    if( cnt != inf )    cnt1= cnt+go(row+1,c1Mask,n1Mask);
    else   cnt1 = inf;

    ans = min( ans, cnt1 );

    cnt=1;
    p2Mask = toggle( p2Mask, m - 1 );

    if( m > 1 ) p2Mask = toggle( p2Mask, m - 2 );


    if( c2Mask != -1 ){

        c2Mask = toggle( c2Mask, m - 1 );

        if(m>1) c2Mask = toggle( c2Mask, m - 2 );
    }

    if(n2Mask != -1 ){
        n2Mask = toggle( n2Mask, m - 1 );
        if( m > 1 ) n2Mask = toggle( n2Mask, m - 2 );
    }

    for(int j = 0; j < m; j++)
    {
        int k = m - 1 - j;
        if( k == 0)
        {
            if( !check( p2Mask, k ) )
                cnt = inf;
                break;
        }

        if( check( p2Mask, k ) ) continue;

        cnt++;

        p2Mask = toggle( p2Mask, k );

        if( c2Mask != -1 )  c2Mask = toggle( c2Mask, k );
        if( n2Mask != -1 )  n2Mask = toggle( n2Mask, k );

        if( k - 1 >= 0)
        {
            p2Mask = toggle( p2Mask, k - 1 );
            if( c2Mask != -1 )  c2Mask = toggle( c2Mask, k - 1 );
            if( n2Mask != -1 )  n2Mask = toggle( n2Mask, k - 1 );
        }

        if( k - 2 >= 0 )
        {
            p2Mask = toggle( p2Mask, k - 2 );
            if( c2Mask != -1 )  c2Mask = toggle( c2Mask, k - 2 );
            if( n2Mask != -1 )  n2Mask = toggle( n2Mask, k - 2 );
        }
    }


    if( cnt != inf )    cnt2 = cnt + go( row + 1, c2Mask, n2Mask );
    else  cnt2=inf;
    ans = min( ans, cnt2);

    return dp[row][prevMask][currMask] = ans;
}
int main()
{



    scanf( "%d\n", &T );

    for( int K = 1; K <= T; K++ )
    {
        scanf( "%d %d", &n, &m);
        memset( st, 0, sizeof(st) );
        memset( dp, -1, sizeof(dp) );

        for( int i = 0; i < n; i++ )
        {
            scanf( "%s", s);

            for( int j = 0; j < m; j++ )
            {
                if ( s[j] == '*' ) st[i] = bitOn ( st[i], m - 1 - j );
            }
        }

        int ans = inf, temp_ans;
        int prev, curr;

        for( int i = 0; i < (1<<m); i++)
        {
            prev = st[0];
            if( n > 1 ) curr = st[1];

            int cnt=0;

            for( int j = 0; j < m; j++)
            {
                int k = m -1 - j;

                if( check( i, k ) )
                {
                    cnt++;
                    prev = toggle( prev, k );

                    if( k != m - 1 )   prev = toggle( prev, k + 1 );
                    if( k != 0 ) prev = toggle( prev, k - 1 );

                    if( n > 1 )
                    {
                        curr = toggle( curr, k );
                        if( k != m - 1 ) curr = toggle( curr, k + 1 );
                        if( k != 0 ) curr = toggle( curr, k - 1 );
                    }
                }
            }

            temp_ans = cnt + go ( 1, prev, curr );
            ans = min( ans, temp_ans );
        }
        if( ans >= inf )
            printf( "Case %d: impossible\n", K );
        else
            printf( "Case %d: %d\n", K, ans );
    }
}
