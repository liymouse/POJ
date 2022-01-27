#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n, m, k;
    while (scanf("%d,%d,%d", &n, &m, &k) == 3)
    {
        int a[2][130] = { 0 };
        for (int i = 0; i < m; i++) a[0][i] = 1;
        int p = 0;
        for (int t = 0; t < k; t++)
        {
            for (int i = 0; i < n; i++)
                if (a[p][i] == a[p][(i + 1) % n]) a[1 - p][i] = 0;
                else a[1 - p][i] = 1;
            p = 1 - p;
        }
        int res = 0;
        for (int i = 0; i < n; i++) res += a[p][i];
        printf("%d,%d,%d: %d\n", n, m, k, res);
    }
    return 0;
}