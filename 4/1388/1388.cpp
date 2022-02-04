#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n, i, j, k;
    while (scanf("%d", &n) == 1)
    {
        char a[101][103];
        int res = 0;
        char c[105] = { 0 };
        char p[101][101] = { 0 };
        if (n == 0) break;
        for (i = 1; i <= n; i++)
        {
            scanf("%s", a[i]+1);
            for (j = 1; j <= n; j++) a[i][j] -= '0';
        }
        for (k = 1; k <= n; k ++)
            for (i = 1; i <= n; i ++)
                if (i != k)
                    for (j = 1; j <= n; j ++)
                        if (j != i && j != k && a[i][k] && a[k][j])
                        {
                            if (a[i][j] == 0 || a[i][k] + a[k][j] < a[i][j])
                            {
                                a[i][j] = a[i][k] + a[k][j];
                                p[i][j] = k;
                            }
                            else if (a[i][k] + a[k][j] == a[i][j])
                            {
                                p[i][j] = 0;
                            }
                        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (p[i][j]) c[p[i][j]] = 1;
        for (i = 1; i <= n; i++) res += c[i];
        printf("%d\n", res);
    }
    return 0;
}