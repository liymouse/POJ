#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int m, n, R, C;
    int a[205][205];

    while (scanf("%d", &m) == 1)
    {
        if (m == 0) { printf("*\n"); break; }
        scanf("%d %d %d", &n, &R, &C);
        int b[205][205] = { 0 };
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
                b[i + 1][j + 1] = b[i][j + 1] + b[i + 1][j] - b[i][j] + a[i][j];
            }
        double res = 0;
        int r1, c1, r2, c2;
        for (int r = R; r <= m; r ++)
            for (int c = C; c <= n; c++)
            {
                double area = r * c;
                for (int i = r; i <= m; i ++)
                    for (int j = c; j <= n; j++)
                    {
                        int sum = b[i][j] - b[i - r][j] - b[i][j - c] + b[i-r][j-c];
                        if (sum / area > res)
                        {
                            res = sum / area;
                            r1 = i - r + 1; c1 = j - c + 1;
                            r2 = i; c2 = j;
                        }
                    }
            }
        printf("%d %d %d %d\n", r1, c1, r2, c2);
    }
    return 0;
}