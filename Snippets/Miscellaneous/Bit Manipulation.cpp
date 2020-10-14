int Set(int N, int pos)   {return N = N | (1<<pos);}

int Reset(int N, int pos) {return N = N & ~(1<<pos);}

bool check(int N,int pos) {return (bool)(N & (1<<pos));}

int toggle(int n, int k)  {return n ^= 1 << k;}


bool isPowerOfTwo(long long x)
{
    return (x && !(x & (x - 1)));
}

long long largest_power( long long N)
{
      N = N| (N >> 1);
      N = N| (N >> 2);
      N = N| (N >> 4);
      N = N| (N >> 8);
      N = N| (N >> 16);
      N = N| (N >> 32);
    
      return (N+1)>>1;
}
