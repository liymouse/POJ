#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int x, y, t, dir;
}Elm;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int main()
{
    int m, n;
    int a[55][55], b[55][55];
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0 && n == 0) break;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &b[i][j]);
        for (int i = 0; i < m-1; i ++)
            for (int j = 0; j < n - 1; j++)
            {
                a[i][j] = b[i][j] | b[i + 1][j] | b[i][j + 1] | b[i + 1][j + 1];
            }
        int sx, sy, ex, ey;
        char s[10];
        scanf("%d %d %d %d %s", &sx, &sy, &ex, &ey, s);
        sx--; sy--; ex--; ey--;
        m--; n--;
        if (sx == ex && sy == ey) { printf("0\n"); continue; }
        if (a[sx][sy] == 1 || a[ex][ey] == 1 || sx < 0 || sx >= m || sy < 0 || sy >= n ||
            ex < 0 || ex >= m || ey < 0 || ey >= n) { printf("-1\n"); continue; }
        Elm x;
        x.x = sx; x.y = sy; x.t = 0;
        if (s[0] == 's') x.dir = 2;
        else if (s[0] == 'n') x.dir = 0;
        else if (s[0] == 'w') x.dir = 1;
        else x.dir = 3;
        queue<Elm> qu;
        qu.push(x);

        int res = -1;
        int t[55][55][4];
        memset(t, 0xff, sizeof(t));
        t[sx][sy][x.dir] = 0;
        int change[2] = { 3, 1 };
        while (!qu.empty())
        {
            x = qu.front();
            qu.pop();
            if (x.t > t[x.x][x.y][x.dir]) continue;
            for (int i = 0; i < 2; i++)
            {
                int dir = (x.dir + change[i]) % 4;
                if ((t[x.x][x.y][dir] == -1 || x.t + 1 < t[x.x][x.y][dir]))
                {
                    Elm y;
                    y = x;
                    y.dir = dir;
                    y.t++;
                    qu.push(y);
                    t[x.x][x.y][dir] = y.t;
                }
            }
            for (int i = 1; i <= 3; i ++)
            {
                int xx = x.x + p[x.dir][0] * i;
                int yy = x.y + p[x.dir][1] * i;
                if (0 <= xx && xx < m && 0 <= yy && yy < n && a[xx][yy] == 0)
                {
                    if (xx == ex && yy == ey) { res = x.t + 1; goto L_exit; }
                    if (t[xx][yy][x.dir] == -1 || x.t + 1 < t[xx][yy][x.dir])
                    {
                        Elm y;
                        y.x = xx; y.y = yy;
                        y.t = x.t + 1;
                        y.dir = x.dir;
                        qu.push(y);
                        t[xx][yy][y.dir] = y.t;
                    }
                }
                else break;
            }
        }
        L_exit:
        printf("%d\n", res);
    }
    return 0;
}
