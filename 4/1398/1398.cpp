#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, c, a[100][110];
        scanf("%d %d", &n, &c);
        for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            int same = 1;
            for (int j = 1; j < n - i; j++) if (a[i][j] != a[i][0]) { same = 0; break; }
            if (same) { k = i; break; }
            for (int j = 0; j < n - i - 1; j++)
                a[i + 1][j] = a[i][j] - a[i][j + 1];
        }
        if (k == -1) k = n - 1;
        for (int i = n - k; i < n - k + c; i++) a[k][i] = a[k][0];

        for (int i = k - 1; i >= 0; i--)
        {
            for (int j = n - i; j < n - i + c; j++)
                a[i][j] = a[i][j - 1] - a[i + 1][j - 1];
        }
        printf("%d", a[0][n]);
        for (int i = n + 1; i < n + c; i++) printf(" %d", a[0][i]);
        printf("\n");
    }
    return 0;
}
