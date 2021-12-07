#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        double a[20][20][20] = { 0 };
        int p[20][20][20] = { 0 };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j) scanf("%lf", &a[i][j][0]);
                else a[i][j][0] = 1.0;
        int ok = 0;
        for (int s = 1; s < n; s++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                        if (a[i][k][s - 1] * a[k][j][0] > a[i][j][s])
                        {
                            a[i][j][s] = a[i][k][s - 1] * a[k][j][0];
                            p[i][j][s] = k;
                        }
                    if (i == j && a[i][j][s] > 1.01)
                    {
                        ok = 1;
                        int t = s, k = i;
                        int path[21] = { i };
                        int L = 1;
                        while (t)
                        {
                            path[L++] = p[i][k][t];
                            k = p[i][k][t];
                            t--;
                        }
                        path[L] = i;
                        for (int i = L; i >= 0; i--) printf(" %d", path[i] + 1);
                        printf("\n");
                        goto L_end;
                    }
                }
        }
L_end:
        if (ok == 0) printf("no arbitrage sequence exists\n");
    }
    return 0;
}