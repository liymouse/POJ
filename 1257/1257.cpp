#include <stdio.h>
#include <stdlib.h>

int a[210][210] = { 0 };
int map[210][210] = { 0 };
int v[210][210] = { 0 };
int n, m;
// \=1 /=2 X=3
//point -> grid
int mapd[4][3] = { {-1, -1, 1}, {-1,0, 2}, {0,-1, 2}, {0,0, 1} };
//point -> point shift
int pointd[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
int tot;
void dfs(int x, int y)
{
    tot += abs(a[x][y]);
    v[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + mapd[i][0];
        int yy = y + mapd[i][1];
        if (0 <= xx && xx < n && 0 <= yy && yy < m && (map[xx][yy] & mapd[i][2]))
        {
            int ii = x + pointd[i][0];
            int jj = y + pointd[i][1];
            if (v[ii][jj] == 1) dfs(ii, jj);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int ii = 0; ii < 2*n; ii++)
    {
        char s[210];
        scanf("%s", s);
        int inc = (ii < n) ? 1 : -1;
        int i = ii % n;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '\\')
            {
                map[i][j] |= 1;
                a[i][j] += inc; a[i + 1][j + 1] += inc;
                v[i][j] = v[i + 1][j + 1] = 1;
            }
            else if (s[j] == '/')
            {
                map[i][j] |= 2;
                a[i][j + 1] += inc; a[i + 1][j] += inc;
                v[i][j + 1] = v[i + 1][j] = 1;
            }
            else if (s[j] == 'X')
            {
                map[i][j] = 3;
                a[i][j]+= inc; a[i + 1][j + 1]+=inc; a[i][j + 1]+= inc; a[i + 1][j]+= inc;
                v[i][j] = v[i + 1][j + 1] = v[i][j + 1] = v[i + 1][j] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= m; j++)
            if (v[i][j] == 1)
            {
                tot = 0;
                dfs(i, j);
                if (tot == 0) res++;
                else res += tot / 2;
            }
    printf("%d\n", res);
    return 0;
}