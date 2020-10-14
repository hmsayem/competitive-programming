vector <long long> divisors;
void gen_Divisors( int n )
{
    divisors.clear();
    for ( int i = 1; i <= sqrt(n); i++ ) {
        if ( n % i == 0 ) {
            if ( n / i == i ) {
                divisors.push_back( i );
            }
            else {
                divisors.push_back( i );
                divisors.push_back( n / i );
            }
        }
    }
}
