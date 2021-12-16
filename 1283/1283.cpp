#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long lld;

int main()
{
    int n, k;
    lld f[201][201] = { 0 };
    for (int i = 0; i <= 200; i++) {
        f[i][1] = 1; f[i][i] = 1;
    }
    for (int i = 2; i <= 200; i++)
        for (int j = 2; j < i; j++)
        {
            for (int k = 1; k <= j; k++)
                f[i][j] += f[i - j][k];
        }
    while (scanf("%d %d", &n, &k) == 2)
    {
        if (n == 0) break;
        printf("%lld\n", f[n][k]);
    }
}