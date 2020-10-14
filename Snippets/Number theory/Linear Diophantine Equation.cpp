bool linearDiophantine ( int A, int B, int C, int *x, int *y ) {
    int g = gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution
 
    int a = A / g, b = B / g, c = C / g;
    ext_gcd( a, b, x, y ); //Solve ax + by = 1
 
    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }
 
    *x *= c; *y *= c; //ax + by = c
    return true; //Solution Exists
}
 
int main () {
    int x, y, A = 2, B = 3, C = 5;
    bool res = linearDiophantine ( A, B, C, &x, &y );
 
    if ( res == false ) printf ( "No Solution\n" );
    else {
        printf ( "One Possible Solution (%d %d)\n", x, y );
 
        int g = gcd ( A, B );
 
        int k = 1; //Use different value of k to get different solutions
        printf ( "Another Possible Solution (%d %d)\n", x + k * ( B / g ), y - k * ( A / g ) );
    }
 
 return 0;
}
