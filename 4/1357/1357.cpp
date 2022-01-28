#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef struct {
    int x, y, t, predir;
}Elm;

int p[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
char a[105][105];
int getNext(int x, int y, int d, int curt)
{
    if (a[x][y] == '+') return 1;
    int change = a[x][y] - '0';
    int has[4] = { 0 };
    int n = 0;
    for (int i = 0; i < 4; i ++)
        if ((i % 2 == 0 && a[x + p[i][0]][y + p[i][1]] == '|') ||
            (i % 2 == 1 && a[x + p[i][0]][y + p[i][1]] == '-'))
        {
            has[i] = 1;
            n++;
        }
    d = (d + 2) % 4;
    int s = has[0] ? 0 : 2;
    int num = 0;
    while (s != d) {
        num++;
        s = (s + 1) % 4;
        while (has[s] == 0) s = (s + 1) % 4;
    }
    curt %= n * change;
    int curnum = curt / change;
    if (curnum == num) return 2;
    else if (curnum < num) return num*change - curt + 2;
    else return num*change - curt + n * change + 2;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, m;
        int t[105][105];
        scanf("%d %d", &n, &m); gets_s(a[0]);
        memset(t, 0xff, sizeof(t));
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
        {
            gets_s(a[i]);
            for (int j = 0; j < m; j ++)
                if (a[i][j] == 'S') { sx = i; sy = j; }
                else if (a[i][j] == 'D') { ex = i; ey = j; }
        }
        queue<Elm> qu;
        for (int i = 0; i < 4; i++)
        {
            if ((i % 2 == 0 && a[sx + p[i][0]][sy + p[i][1]] == '|') ||
                (i % 2 == 1 && a[sx + p[i][0]][sy + p[i][1]] == '-'))
            {
                Elm x;
                x.t = 1;
                x.x = sx + p[i][0];
                x.y = sy + p[i][1];
                x.predir = i;
                t[x.x][x.y] = 1;
                qu.push(x);
            }
        }
        while (!qu.empty())
        {
            Elm x = qu.front();
            qu.pop();
            if (x.t > t[x.x][x.y]) continue;
            int xx = x.x + p[x.predir][0];
            int yy = x.y + p[x.predir][1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (a[xx][yy] == '*' || a[xx][yy] == ' ' || a[xx][yy] == 'S') continue;
            if (x.predir % 2 == 0 && a[xx][yy] == '-') continue;
            if (x.predir % 2 == 1 && a[xx][yy] == '|') continue;
            if (a[xx][yy] == 'D') { t[xx][yy] = x.t + 1; goto L_exit; }
            if ((a[xx][yy] == '-' || a[xx][yy] == '|'))
            {
                if (t[xx][yy] == -1 || x.t + 1 < t[xx][yy])
                {
                    Elm y;
                    y.predir = x.predir;
                    y.x = xx;
                    y.y = yy;
                    y.t = x.t + 1;
                    t[xx][yy] = x.t + 1;
                    qu.push(y);
                }
            }
            else
            {
                int nextt = getNext(xx, yy, x.predir, x.t+1);
                for (int j = 0; j < 4; j++)
                    if (j != (x.predir + 2) % 4)
                    {
                        int nx = xx + p[j][0];
                        int ny = yy + p[j][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if ((j % 2 == 0 && a[nx][ny] == '|') ||
                            (j % 2 == 1 && a[nx][ny] == '-'))
                        {
                            if (t[nx][ny] == -1 || x.t + nextt < t[nx][ny])
                            {
                                Elm y;
                                y.predir = j;
                                y.x = nx;
                                y.y = ny;
                                y.t = x.t + nextt;
                                t[nx][ny] = x.t + nextt;
                                qu.push(y);
                            }
                        }
                    }
            }
        }
        L_exit:
        if (t[ex][ey] == -1) printf("impossible\n");
        else printf("%d\n", t[ex][ey]);
    }
    return 0;
}
