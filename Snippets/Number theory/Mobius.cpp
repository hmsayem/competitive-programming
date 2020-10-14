const int SIZE = 1000000;
int mob[1000005];
vector <int> prime;
void mobius()
{
    for(int i = 2; i <= SIZE; i++){
        if(mob[i] == 0){
            prime.pb(i);
            for(int j = i*2; j <= SIZE; j += i){
                mob[j]++;
            }
        }
    }
    int l = sqrt(SIZE);
    for(int p : prime){
        mob[p] = 1;
        if(p > l) continue;
        int m = p * p;
        for(int j = m; j <= SIZE; j += m){
            mob[j] = 0;
        }
    }
    mob[1] = 1;
    for(int i = 2; i <= SIZE; i++){
        if(mob[i] == 0) continue;
        if(mob[i] % 2 == 1) mob[i] = -1;
        else mob[i] = 1;
    }
}
