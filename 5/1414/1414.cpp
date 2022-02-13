#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, c, a[11][11];
int v[11][11];
int num, remov;

int p[6][2] = { {-1,0},{-1,-1},{0,-1},{1,0},{1,1},{0,1} };
void dfs(int x, int y, int k)
{
    v[x][y] = 1; num++;
    for (int i = 0; i < 6; i++)
    {
        int xx = x + p[i][0];
        int yy = y + p[i][1];
        if (0 <= xx && xx < n && 0 <= yy && yy <= xx && v[xx][yy] == 0)
        {
            if (a[xx][yy] == 0) remov = 0;
            else if (a[xx][yy] == k) dfs(xx, yy, k);
        }
    }
}
int calculatePoint()
{
    memset(v, 0, sizeof(v));
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            if (v[i][j] == 0 && a[i][j] != 0)
            {
                remov = 1; num = 0;
                dfs(i, j, a[i][j]);
                if (remov)
                {
                    if (a[i][j] != c) res += num;
                    else res -= num;
                }
            }
    return res;
}
int main()
{
    while (scanf("%d %d", &n, &c) == 2)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                scanf("%d", &a[i][j]);
        int res = -(1 << 30);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j <= i; j++)
                if (a[i][j] == 0)
                {
                    a[i][j] = c;
                    int p = calculatePoint();
                    if (p > res) res = p;
                    a[i][j] = 0;
                }
        printf("%d\n", res);
    }
    return 0;
}