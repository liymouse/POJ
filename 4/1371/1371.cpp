#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[202][202];
int v[202][202];
int nx, ny;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
void dfs(int x, int y)
{
    v[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if ((a[x][y] & (1 << i)) == 0)
        {
            int xx = x + p[i][0];
            int yy = y + p[i][1];
            if (0 <= xx && xx <= nx && 0 <= yy && yy <= ny && v[xx][yy] == 0)
                dfs(xx, yy);
        }
}
void dfs2(int x, int y)
{
    v[x][y] = 1;
    for (int i = 0; i < 4; i++)
        if (v[x + p[i][0]][y + p[i][1]] == 0) dfs2(x + p[i][0], y + p[i][1]);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int x1[100], y1[100], x2[100], y2[100];
        int x[200], y[200];
        nx = 0, ny = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
            if (x1[i] == x2[i])
            {
                x[nx++] = x1[i]; y[ny++] = y1[i]; y[ny++] = y2[i];
            }
            else
            {
                y[ny++] = y1[i]; x[nx++] = x1[i]; x[nx++] = x2[i];
            }
        }
        sort(x, x + nx);
        sort(y, y + ny);
        int k = 0;
        for (int i = 1; i < nx; i ++)
            if (x[i] != x[k]) { k++; x[k] = x[i]; }
        nx = k + 1;
        k = 0;
        for (int i = 1; i < ny; i++)
            if (y[i] != y[k]) { k++; y[k] = y[i]; }
        ny = k + 1;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            if (x1[i] == x2[i])
            {
                int xx = 0;
                for (int j = 0; j < nx; j ++)
                    if (x[j] == x1[i]) { xx = j; break; }
                int sy = min(y1[i], y2[i]);
                int ey = max(y1[i], y2[i]);
                for (int yy = 0; yy < ny; yy++)
                    if (sy <= y[yy] && y[yy] < ey)
                    {
                        a[xx][yy + 1] |= 1 << 2;
                        a[xx + 1][yy + 1] |= 1 << 0;
                    }
            }
            else
            {
                int yy = 0;
                for (int j = 0; j < ny; j ++)
                    if (y[j] == y1[i]) { yy = j; break; }
                int sx = min(x1[i], x2[i]);
                int ex = max(x1[i], x2[i]);
                for (int xx = 0; xx < nx; xx++)
                    if (sx <= x[xx] && x[xx] < ex)
                    {
                        a[xx + 1][yy] |= 1 << 3;
                        a[xx + 1][yy + 1] |= 1 << 1;
                    }
            }
        }
        memset(v, 0, sizeof(v));
        dfs(0, 0);
        int res = 0;
        for (int i = 1; i < nx; i ++)
            for (int j = 1; j < ny; j ++)
                if (v[i][j] == 0)
                {
                    res++; dfs2(i, j);
                }
        printf("%d\n", res);
    }
    return 0;
}