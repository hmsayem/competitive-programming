#include<bits/stdc++.h>

using namespace std;

#define SIZE 1000005
vector <int> prime;
char sieve[SIZE];
int NOD[SIZE];
int CNT[SIZE];
int LP[SIZE];


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


int main()
{
   primeSieve(1000000);

   for(int i = 1; i <= 1000000; i++)
        NOD[i] = 1;

   for(int i = 0; i < prime.size(); i++)
   {

       int p = prime[i];
       long long temp = p;

       while(temp <= 1000000)
       {
           for(int j = temp; j <= 1000000; j += temp)
           {

                if(LP[j]!=p)
                {
                    NOD[j] *= (CNT[j] + 1);
                    CNT[j]=0;
                }

                CNT[j]++;
                LP[j] = p;

           }
           temp *= p;
       }
   }

   for( int i = 1; i<=1e6; i++)
   {
        NOD[i] *= CNT[i] + 1;
   }

   int t;
   scanf("%d",&t);
   while(t--)
   {
       int n, m;
       scanf("%d %d", &n, &m);
       int s = __gcd(n,m);
       printf("%d\n", NOD[s]);
   }
}
