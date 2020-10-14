void factFactorize ( int n ) {
    for ( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
        int x = n;
        int freq = 0;
 
        while ( x / prime[i] ) {
            freq += x / prime[i];
            x = x / prime[i];
        }
 
        printf ( "%d^%d\n", prime[i], freq );
    }
}
