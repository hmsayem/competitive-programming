int baseToDecimal ( string x, int base ) {
    int res = 0;
    int len = x.length();
 
    for ( int i = 0; i < len; i++ ) {
        res = ( res * base ) + (x[i]-'0');
    }
    return res;
}
