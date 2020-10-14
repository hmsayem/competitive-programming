bool is_perfect_square(long long n) {

    long long root(round(sqrtl(n)));
    return n == root * root;
}

bool is_perfect_cube(long long n) {

    long long root(round(cbrtl(n)));
    return n == root * root * root;
}

bool is_perfect_quartic(long long n)
{

    long long temp (round(sqrtl(n)));

    long long root (round(sqrtl(temp)));

    return  n==root*root*root*root;
}
