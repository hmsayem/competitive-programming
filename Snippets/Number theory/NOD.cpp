int NOD ( int n ) {
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            int p = 0; // Counter for power of prime
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 ) {
        res *= 2; // Remaining prime has power p^1. So multiply with 2/
    }
    return res;
}

int NOD ( int n ) {
    int res = 0;
    int sqrtn = sqrt ( n );
     
    for ( int i = 1; i < sqrtn; i++ ) {
        if ( n % i == 0 ) res += 2; // Found a divisor pair {A,B}
    }
    // Need to check if sqrtn divides n
    if ( n % sqrtn == 0 ) {
        if ( sqrtn  sqrtn == n ) res++; // If n is perfect square
        else res += 2; // Not perfect square
    }
    return res;
}

