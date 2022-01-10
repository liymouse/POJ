#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int linecross(int x1, int y1, int x2, int y2,
    int x3, int y3, int x4, int y4)
{
    //same line but not cross
    if (((x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) * ((x4 - x2)*(y1 - y2) - (y4 - y2)*(x1 - x2)) == 0 &&
        ((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) * ((x2 - x3)*(y4 - y3) - (y2 - y3)*(x4 - x3)) == 0)
    {
        if ((x3 - x1)*(x4 - x1) + (y3 - y1)*(y4 - y1) > 0 && (x3 - x2)*(x4 - x2) + (y3 - x2)*(y4 - y2) > 0) return 0;
        return 1;
    }
    else if (((x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) * ((x4 - x2)*(y1 - y2) - (y4 - y2)*(x1 - x2)) <= 0 &&
        ((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) * ((x2 - x3)*(y4 - y3) - (y2 - y3)*(x4 - x3)) <= 0)
        return 1;
    return 0;
}

int main()
{
    int n;
    int sx[20], sy[20], ex[20], ey[20];
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int a[20][20] = { 0 };
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &sx[i], &sy[i], &ex[i], &ey[i]);
            for (int j = 0; j < i; j ++)
                if (linecross(sx[i], sy[i], ex[i], ey[i], sx[j], sy[j], ex[j], ey[j]))
                {
                    a[i][j] = a[j][i] = 1;
                }
            a[i][i] = 1;
        }
        for (int k = 0; k < n; k ++)
            for (int i = 0; i < n; i ++)
                if (i != k)
                    for (int j = 0; j < n; j ++)
                        if (i != j && j != k && a[i][k] && a[k][j])
                        {
                            a[i][j] = a[j][i] = 1;
                        }
        int x, y;
        while (scanf("%d %d", &x, &y) == 2)
        {
            if (x == 0 && y == 0) break;
            if (a[x - 1][y - 1]) printf("CONNECTED\n");
            else printf("NOT CONNECTED\n");
        }
    }
    return 0;
}