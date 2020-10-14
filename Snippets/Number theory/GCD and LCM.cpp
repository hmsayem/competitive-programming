int gcd ( int a, int b ) {
    while ( b ) {
        a = a % b;
        swap ( a, b );
    }
    return abs(a);
}

int lcm ( int a, int b ) {
    return ( a * b ) / gcd ( a, b );
}

