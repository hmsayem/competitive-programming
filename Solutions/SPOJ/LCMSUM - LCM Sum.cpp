#include <bits/stdc++.h>
using namespace std;

long long phi[1000005];
long long res[1000005];

void preCal(int n)
{
    for (int i=1; i<=n; i++)
        phi[i] = i;

    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j <= n; j+=i )
        {
            res[j] += phi[i] * i;
        }
    }
}
int main()
{
    preCal( 1000000 );
    int T;
    scanf( "%d", &T );
    while( T-- )
    {
        int n;
        scanf( "%d", &n );

        long long ans = res[n] + 1;
        ans *= n;
        ans /= 2;
        printf( "%lld\n", ans );
    }
}
