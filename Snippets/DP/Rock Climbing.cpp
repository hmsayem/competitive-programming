int DP[3][10];
int r = 3, c = 3;
int call(int i, int j)
{
    if (i >= 0 && i < r && j >= 0 && j < c)
    {
        if (DP[i][j] != -1)
            return DP[i][j];
        int ret = -inf;
        ret = max(ret, call(i + 1, j) + mat[i][j]);
        ret = max(ret, call(i + 1, j - 1) + mat[i][j]);
        ret = max(ret, call(i + 1, j + 1) + mat[i][j]);

        return DP[i][j] = ret;
    }
    else
        return 0;
}
int main()
{
    memset(DP,-1,sizeof(DP));
    int ans=-inf;
    ans=max(ans,call(0,0));
    ans=max(ans,call(0,1));
    ans=max(ans,call(0,2));

    printf("%d\n", ans);

    return 0;
}
