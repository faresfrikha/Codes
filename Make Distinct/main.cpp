#include<bits/stdc++.h>

using namespace std;
int N, k, i, j;
long long INF = (1LL<<62), dp[2][3009], mi[2][3009];
int a[3009], b[3009];
long long mod (long long x)
{
    if (x<0)
        return -x;
    return x;
}

int main()
{
    scanf ("%d", &N);
    for(i=1; i<=N; i++)
        scanf ("%d", &a[i]);
    sort(a + 1, a + N + 1);
    for(int i=1; i<=N; i++)
    {
        a[i] -= i;
        b[i] = a[i];
    }
    sort (b + 1, b + N + 1);
    mi[1][0]=INF;
    for(i=1; i<=N; i++)
    {
        dp[1][i]=mod(b[i]-a[1]);
        mi[1][i]=mi[1][i-1];
        if(dp[1][i]<mi[1][i])
            mi[1][i]=dp[1][i];
    }
    for(i=2; i<=N; i++)
    {
        mi[i&1][0]=INF;
        for(j=1; j<=N; j++)
        {
            mi[i&1][j]=mi[i&1][j-1];
            dp[i&1][j]=mod(b[j]-a[i])+mi[(i&1)^1][j];
            if(dp[i&1][j]<mi[i&1][j])
                mi[i&1][j]=dp[i&1][j];
        }
    }
    printf ("%I64d\n", mi[N&1][N]);
    return 0;
}
