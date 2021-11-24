#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca --)
    {
        int c;
        int n[100], p[100];
        scanf("%d", &c);
        int res = 0;
        int f[100] = { 0 };
        for (int i = 0; i < c; i++)
        {
            scanf("%d %d", &n[i], &p[i]);
            res += (n[i]+10) * p[i];
            if (i > 0) f[i] = max(10 * p[i - 1] - (p[i] - p[i - 1]) * n[i], 0);
        }
        int dp[100] = { 0, f[1] };
        for (int i = 2; i < c; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + f[i]);
        res -= dp[c - 1];
        printf("%d\n", res);
    }
    return 0;
}