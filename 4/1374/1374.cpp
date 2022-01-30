#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int m, n;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int a[25][25];
int skip[25][25];

void dfs(int x, int y)
{
    skip[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + p[i][0];
        int yy = y + p[i][1];
        if (0 <= xx && xx < m && 0 <= yy && yy < n && a[xx][yy] == 1 && skip[xx][yy] == 0) dfs(xx, yy);
    }
}
int main()
{
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0 && n == 0) break;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
        memset(skip, 0, sizeof(skip));
        for (int i = 0; i < m; i++)
        {
            if (a[i][0] == 1 && skip[i][0] == 0) dfs(i, 0);
            if (a[i][n - 1] == 1 && skip[i][n - 1] == 0) dfs(i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            if (a[0][j] == 1 && skip[0][j] == 0) dfs(0, j);
            if (a[m-1][j] == 1 && skip[m-1][j] == 0) dfs(m-1, j);
        }
        int label[25][25] = { 0 };
        int id = 1;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j++)
                if (skip[i][j] == 0 && a[i][j] == 0)
                {
                    if ((i == 0 && i + 1 < m && a[i + 1][j] == 0) ||
                        (i > 0 && i + 1 < m && a[i - 1][j] != 0 && a[i + 1][j] == 0) ||
                        (j == 0 && j + 1 < n && a[i][j + 1] == 0) ||
                        (j > 0 && j + 1 < n && a[i][j - 1] != 0 && a[i][j + 1] == 0))
                        label[i][j] = id++;
                }
        char s[80][130] = { 0 };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (skip[i][j])
                {
                    for (int y = i * 3; y <= (i + 1) * 3; y++)
                        for (int x = j * 5; x <= (j + 1) * 5; x++)
                            if (s[y][x] != '+') s[y][x] = ' ';
                }
                else
                {
                    if (label[i][j] > 0)
                    {
                        sprintf(s[i * 3 + 1] + j*5 + 1, "%03d ", label[i][j]);
                        for (int x = j * 5; x < (j + 1) * 5; x++) s[i * 3 + 2][x] = ' ';
                    }
                    else if (a[i][j] == 0)
                    {
                        for (int x = j * 5; x < (j + 1) * 5; x++)
                            s[i * 3 + 1][x] = s[i*3+2][x] = ' ';
                    }
                    else
                    {
                        for (int x = j * 5; x < (j + 1) * 5; x++)
                            s[i * 3 + 1][x] = s[i * 3 + 2][x] = '+';
                    }
                    for (int y = i * 3; y <= (i + 1) * 3; y++)
                        s[y][j * 5] = s[y][(j + 1) * 5] = '+';
                    for (int x = j * 5; x <= (j + 1) * 5; x++)
                        s[i * 3][x] = s[(i + 1) * 3][x] = '+';

                }
            }
            int ey = (i + 1) * 3;
            if (i == m - 1) ey++;
            for (int y = i * 3; y < ey; y++)
            {
                int t = n * 5;
                while (t >= 0 && s[y][t] == ' ') t--;
                s[y][t + 1] = 0;
            }
        }
        for (int i = 0; i <= m * 3; i++) printf("%s\n", s[i]);
        printf("\n\n");
    }

    return 0;
}