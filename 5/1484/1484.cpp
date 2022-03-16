#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int ca = 1, n, m, c;
    while (scanf("%d %d %d", &n, &m, &c) == 3)
    {
        if (n == 0 && m == 0 && c == 0) break;
        int a[22] = { 0 };
        int w[22];
        int cur = 0;
        int maxv = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            a[x] = 1 - a[x];
            if (a[x] == 0) cur -= w[x];
            else
            {
                cur += w[x];
                if (cur > maxv) maxv = cur;
            }
        }
        printf("Sequence %d\n", ca++);
        if (maxv > c) printf("Fuse was blown.\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", maxv);
        printf("\n");
    }
}
