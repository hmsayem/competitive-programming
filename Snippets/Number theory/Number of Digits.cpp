int numberDigit ( int n ) {
    int wrongAnswer = log10(n) + 1; // This may give wrong answer sometimes.
    int rightAnswer = log10(n) + 1 + eps; // This is right.
    return rightAnswer;
}
int factorialDigit ( int n ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i );
    }
    int res = x + 1 + eps;
    return res;
}
int factorialDigitExtended ( int n, int base ) {
    double x = 0;
    for ( int i = 1; i <= n; i++ ) {
        x += log10 ( i ) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}
