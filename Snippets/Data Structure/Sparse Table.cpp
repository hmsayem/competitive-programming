#define Max 10000005
int ST[24][Max];
int A[Max];
void Compute_ST(int N)
{
    for (int i=0;i<N;i++)ST[0][i] = A[i];
    for (int k = 1;(1 << k)<N; k++)
    {
        for (int i=0;i+(1<<k)<=N;i++)
        {
            int x = ST[k-1][i];
            int y = ST[k-1][i+(1<<k-1)];
            ST[k][i]= min(x,y);
        }
    }
}

int RMQ(int i, int j) // 0 index
{
    int k;
    if(j>i)
        k=log2(j-i);
    else
        k=0;
    int x = ST[k][i];
    int y = ST[k][j-(1<<k)+1];
    return min(x,y);
}
