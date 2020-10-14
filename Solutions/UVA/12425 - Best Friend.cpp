#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
char sieve[1000005];

void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1;

    prime.push_back(2);
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1;

    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }

    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}
long long eulerPhi ( long long n ) {

    long long res = n;
    long long sqrtn = sqrtl ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }
            sqrtn = sqrtl ( n );
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

vector <long long> divisors;
void genDivisors(long long n)
{
    for (int i=1; i<=sqrt(n); i++)
        if (n%i == 0)
            if (n/i == i)   divisors.push_back(i);
            else {divisors.push_back(i),divisors.push_back(n/i);}
}

int main()
{

    primeSieve(1000000);

    int T;
    scanf( "%d", &T );
    long long n,x;
    int q;
    for( int k = 1; k <= T; k++ )
    {
         scanf( "%lld %d", &n, &q );
         divisors.clear();
         genDivisors(n);

         map<long long , long long > mp;

         for( auto x : divisors )
            mp[x] = eulerPhi( n/x );

         auto prev = mp.begin();
         auto curr = prev; curr++;

         while( curr != mp.end() )
         {
             curr -> second += prev -> second;
             prev=curr;
             curr++;
         }

         printf("Case %d\n",k);
         while(q--)
         {

             scanf("%lld",&x);

             auto it = mp.lower_bound(x);
             long long ans;

             if( it == mp.end() || it -> first != x )   it--;

             ans = it -> second;
             if(x<1) ans = 0;

             printf( "%lld\n", ans );
         }
    }
}
