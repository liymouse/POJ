#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define INF (0x7fffffff)

int f[1001][1001];
int main()
{
    int ca = 1;
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int L, C;
        scanf("%d %d", &L, &C);
        int a[1001], d[1001] = { 0 };
        int minL[1001] = { 1 };
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            d[i] = d[i - 1] + a[i];
            if (cur + a[i] <= L)
            {
                cur += a[i];
                minL[i] = minL[i - 1];
            }
            else
            {
                cur = a[i];
                minL[i] = minL[i - 1] + 1;
            }
        }
        for (int i = 0; i <= n; i++) for (int j = 0; j <= minL[n]; j++) f[i][j] = INF;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = minL[i]; j <= minL[n]; j++)
            {
                for (int k = i - 1; k >= 0 && d[i] - d[k] <= L; k--)
                    if (f[k][j - 1] != INF)
                    {
                        int rest = L - (d[i] - d[k]);
                        int c = 0;
                        if (rest == 0) c = 0;
                        else if (rest <= 10) c = -C;
                        else c = (rest - 10)*(rest - 10);
                        if (f[k][j - 1] + c < f[i][j])
                            f[i][j] = f[k][j - 1] + c;
                    }
            }
        printf("Case %d:\n\n", ca++);
        printf("Minimum number of lectures: %d\n", minL[n]);
        printf("Total dissatisfaction index: %d\n\n", f[n][minL[n]]);
    }
    return 0;
}
