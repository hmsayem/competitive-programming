const int mod = 1000000007;
const int N  = 100005;
long long fact[N];

long long BigMod( long long b, long long p )
{
    long long ret = 1;
    while( p > 0 ){
        if( p % 2 == 1 )ret = ( ret * b ) % mod;
        p = p >> 1;
        b = ( b * b ) % mod;
    }
    return ret;
}
void PreProcess()
{
	fact[0] = 1;
	for( int i = 1; i < N; i++ )
		fact[i] = ( fact[i-1] * i ) % mod;
}
long long ncr( int n, int r )
{
	long long a = fact[n];
	long long b = ( fact[n-r] * fact[r] ) % mod;
	b = BigMod( b, mod - 2 );
	return ( a * b ) % mod;
}
