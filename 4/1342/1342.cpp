#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))

int a[2048][2048];
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int k;
        scanf("%d", &k);
        int n = 1 << k;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
        int res = 0;
        while (n > 1)
        {
            n >>= 1;
            for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j++)
                {
                    int minv = min(min(a[i * 2][j * 2], a[i * 2 + 1][j * 2]), min(a[i * 2][j * 2 + 1], a[i * 2 + 1][j * 2 + 1]));
                    res += a[i * 2][j * 2] + a[i * 2 + 1][j * 2] + a[i * 2][j * 2 + 1] + a[i * 2 + 1][j * 2 + 1] - 4 * minv + 4;
                    a[i][j] = minv;
                }
        }
        res += a[0][0] + 1;
        printf("%d\n", res);
    }
    return 0;
}