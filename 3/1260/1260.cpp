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
        int n[101], p[101];
        scanf("%d", &c);
        int res = 0;
        for (int i = 1; i <= c; i++)
        {
            scanf("%d %d", &n[i], &p[i]);
            res += (n[i]+10) * p[i];
        }
        int dp[101] = { 0 };
        for (int i = 1; i <= c; i++)
            for (int j = 0; j < i; j++)
            {
                //use i to replace j~i-1
                int sum = 0;
                for (int k = j+1; k < i; k++)
                    sum += 10 * p[k] - (p[i] - p[k]) * n[k];
                dp[i] = max(dp[i], dp[j] + sum);
            }
        res -= dp[c];
        printf("%d\n", res);
    }
    return 0;
}