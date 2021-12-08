#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 2000
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int a[MAX+1] = { 0 };
        int b[6];
        int n = 6;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            a[b[i]] = 1;
        }
        for (int i = 2; i <= MAX; i ++)
            if (a[i] == 0)
            {
                a[i] = a[i - 1] + 1;
                for (int j = 1; j < n; j++)
                    if (i - b[j] > 0 && a[i - b[j]] + 1 < a[i]) a[i] = a[i - b[j]] + 1;
            }
        for (int i = MAX; i >= 1; i--)
            for (int j = 0; j < n; j++)
                if (i - b[j] > 0 && a[i] + 1 < a[i - b[j]]) a[i - b[j]] = a[i] + 1;
        int tot = 0;
        int maxv = 0;
        for (int i = 1; i <= 100; i++)
        {
            tot += a[i];
            if (a[i] > maxv) maxv = a[i];
        }
        printf("%.2lf %d\n", (double)tot / 100, maxv);
    }
    return 0;
}