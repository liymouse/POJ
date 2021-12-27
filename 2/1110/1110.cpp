#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[40][10][90];
int main()
{
    int n, r, c, ca = 1;
    while (scanf("%d %d %d", &n, &r, &c) == 3)
    {
        if (n == 0) break;
        for (int i = 0; i < r; i++)
        {
            for (int t = 0; t < n; t++)
                scanf("%s", a[t][i]);
        }
        int imp = 0;
        for (int t = 0; t < n; t++)
        {
            //1 pixel
            int find = 0;
            for (int i = 0; i < r; i ++)
                for (int j = 0; j < c; j ++)
                    if (a[t][i][j] == 'o')
                    {
                        find = 1;
                        for (int k = 0; k < n; k ++)
                            if (k != t && a[k][i][j] != '.') { find = 0; break; }
                        if (find) {
                            a[t][i][j] = '#';  goto L1;
                        }
                    }
        L1:
            if (find == 0)
            {
                //2 pixels
                for (int i1 = 0; i1 < r; i1 ++)
                    for (int j1 = 0; j1 < c; j1 ++)
                        if (a[t][i1][j1] == 'o')
                        {
                            for (int i2 = i1; i2 < r; i2 ++)
                                for (int j2 = 0; j2 < c; j2 ++)
                                    if ((i2 > i1 || (i2 == i1 && j2 > j1)) && a[t][i2][j2] == 'o')
                                    {
                                        find = 1;
                                        for (int k = 0; k < n; k ++)
                                            if (k != t && a[k][i1][j1] != '.' && a[k][i2][j2] != '.') { find = 0; break; }
                                        if (find)
                                        {
                                            a[t][i1][j1] = a[t][i2][j2] = '#'; goto L2;
                                        }
                                    }
                        }
            L2:
                if (find == 0) {
                    imp = 1; break;
                }
            }
        }
        printf("Test %d\n", ca++);
        if (imp) printf("impossible\n");
        else
        {
            for (int i = 0; i < r; i++)
            {
                printf("%s", a[0][i]);
                for (int j = 1; j < n; j++) printf(" %s", a[j][i]);
                printf("\n");
            }
        }
    }
    return 0;
}