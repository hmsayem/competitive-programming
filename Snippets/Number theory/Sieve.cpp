#define SIZE 1000005   
vector <int> prime; // Stores generated primes
char sieve[SIZE]; // 0 means prime
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1; // 0 and 1 are not prime
 
    prime.push_back(2); // Only Even Prime
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = 1; // Remove multiples of 2
 
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == 0 ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = 1;
        }
    }
 
    for ( int i = 3; i <= n; i += 2 ) if ( sieve[i] == 0 ) prime.push_back(i);
}
