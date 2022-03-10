#include <stdio.h>

int main()
{
    int n, k;
    int a[10000];
    int x, y;
    int p, q, m, res;

    while (scanf("%d %d", &n, &k) == 2)
    {
        p = 1; q = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d.%d", &x, &y);
            a[i] = x * 100 + y;
            if (a[i] > q) q = a[i];
        }
        res = 0;
        while (p <= q)
        {
            m = (p + q) / 2;
            x = 0;
            for (int i = 0; i < n; i++)
                x += a[i] / m;
            if (x < k) q = m - 1;
            else if (x >= k) { if (m > res) res = m; p = m + 1; }
        }
        printf("%d.", res / 100);
        if (res % 100 < 10) printf("0");
        printf("%d\n", res % 100);
    }
}
