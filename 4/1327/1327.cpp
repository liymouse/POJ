#include <stdio.h>

char a[257][260];
int maxs, sum, w, h;
double xx, yy;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void dfs(int x, int y)
{
    sum++;
    a[y][x] = '.';
    xx += x+0.5; yy += y+0.5;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + p[i][0];
        int ty = y + p[i][1];
        if (0 <= tx && tx < w && 0 <= ty && ty < h && a[ty][tx] == 'x')
            dfs(tx, ty);
    }
}
int main()
{
    while (scanf("%d %d", &w, &h) == 2)
    {
        if (w == 0 && h == 0) break;
        int n = 0;
        double cx[257] = { 0 }, cy[257] = { 0 };
        while (1)
        {
            for (int y = 0; y < h; y++) scanf("%s", a[y]);
            maxs = 0;
            for (int y = 0; y < h; y++)
                for (int x = 0; x < w; x++)
                    if (a[y][x] == 'x')
                    {
                        xx = 0; yy = 0; sum = 0;
                        dfs(x, y);
                        if (sum > maxs)
                        {
                            cx[n] = (double)xx / sum;
                            cy[n] = (double)yy / sum;
                            maxs = sum;
                        }
                    }
            scanf("%s", a[0]);
            n++;
            if (a[0][0] == '=') break;
        }
        int t = n / 2;
        double resx = 0, resy = 0;
        for (int i = 0; i < t; i++)
        {
            resx += (cx[i + t] - cx[i]) / t;
            resy += (cy[i + t] - cy[i]) / t;
        }
        resx /= t; resy /= t;
        printf("%.2lf %.2lf\n", resx, resy);
    }
}