#include <stdio.h>

int main()
{
    int n;
    int a[10][130];
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < (1 << n); i++) a[n][i] = i + 1;
        for (int t = n - 1; t >= 0; t--)
            for (int i = 0; i < (1 << t); i++)
                scanf("%d", &a[t][i]);
        int m;
        scanf("%d", &m);
        for (int t = 0; t < m; t ++)
        {
            int x;
            scanf("%d", &x);
            int high = 1;
            int low = 1<<n;
            int s = (x - 1)/2;
            int pre = x;
            for (int b = n-1; b >= 0; b --)
            {
                if (a[b][s] != pre)
                {
                    high++;
                    pre = a[b][s];
                }
                if (a[b][s] == x) low -= 1 << (n-b-1);
                s = s / 2;
            }
            printf("Player %d can be ranked as high as %d or as low as %d.\n", x, high, low);
        }
        printf("\n");
    }
    return 0;
}