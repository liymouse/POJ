#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

char a[200][200];
int main()
{
    int n;
    int ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &a[i][i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int maxL = 0;
            int L = 0;
            int m = (n - i) * 2 - 1;
            for (int j = 0; j < m; j++)
                if (a[i][j+i] == '-') L++;
                else
                {
                    maxL = max(maxL, L);
                    L = 0;
                }
            maxL = max(maxL, L);
            if (maxL % 2 == 0) maxL--;
            for (L = maxL; L > res; L -= 2)
            {
                int h = (L + 1) / 2;
                int found = 0;
                //up
                if (i - h + 1 >= 0)
                {
                    for (int j = 1; j <= m-L; j+=2)
                    {
                        found = 1;
                        for (int p = 0; p < h; p ++)
                        {
                            for (int q = p; q < L-p; q ++)
                                if (a[i - p][j + q + i] == '#') { found = 0; goto L1; }
                        }
                    L1:
                        if (found)
                        {
                            //printf("%d: %d %d\n", L, i, j);
                            break;
                        }
                    }
                }
                //down
                if (i + h - 1 < n && found == 0)
                {
                    for (int j = 0; j <= m-L; j+=2)
                    {
                        found = 1;
                        for (int p = 0; p < h; p++)
                        {
                            for (int q = p; q < L - p; q++)
                                if (a[i + p][j + q + i] == '#') { found = 0; goto L2; }
                        }
                    L2:
                        if (found) {
                            //printf("%d: %d %d\n", L, i, j);
                            break;
                        }
                    }
                }
                if (found) { res = L; break; }
            }
        }
        printf("Triangle #%d\n", ca++);
        res = (res + 1) / 2;
        printf("The largest triangle area is %d.\n\n", res * res);
    }
    return 0;
}
