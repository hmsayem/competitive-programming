
#include<bits/stdc++.h>

using namespace std;


vector <int> prime;
char sieve[10000005];

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

long long phi[100005];
long long rem[100005];

void segmentedSieve ( long long a, long long b ) {

    if ( a == 1 ) a++;

    for(long long i=a;i<=b;i++){
        phi[i-a] = i;
        rem[i-a] = i;
    }

    int sqrtn = sqrt ( b );

    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {

        long long p = prime[i];
        long long j = p*p;

        if(p>=a && p<=b){
            phi[p-a]=p-1;
            rem[p-a]=1;
        }

        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p ) {

            while(rem[j-a]%p==0)
            {
                rem[j-a]/=p;
            }
            
            phi[j-a]/=p;
            phi[j-a]*=(p-1);
        }
    }
}


void computeTotient(long long a, long long b)
{
    if ( a == 1 ) a++;
    for(long long i=a;i<=b;i++)
    {
       if(rem[i-a]!=1)
       {
           phi[i-a]/=rem[i-a];
           phi[i-a]*=rem[i-a]-1;
       }
    }
}

int main()
{

    primeSieve(10000000);

    long long a,b,ans;
    scanf("%lld %lld",&a,&b);

    segmentedSieve(a,b);
    computeTotient(a,b);

    if(a==1){
        printf("1\n");
        a++;
    }
    for(long long i=a;i<=b;i++)
    {
        ans=phi[i-a];
        printf("%lld\n",ans);
    }
}
