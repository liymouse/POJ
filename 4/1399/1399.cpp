#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
    int x, y;
}Node;

int a[201][201];
int step[201][201];
int p[4][2] = { {-1, 0}, {0, -1}, {1,0}, {0, 1} };
int see[201][201];

int check(int x1, int y1, int x2, int y2, int change)
{
    if (x1 == x2) return 1;
    else if (x1 > x2)
    { 
        int t = x1; x1 = x2; x2 = t; 
        t = y1; y1 = y2; y2 = t;
    }
    int z1 = (change == 0) ? a[x1][y1] : a[y1][x1];
    int z2 = (change == 0) ? a[x2][y2] : a[y2][x2];
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dz = z2 - z1;
    int y = 2 * dx * y1 + dy;
    int z = (2 * z1 + 1) * dx + dz;
    int offset = dy > 0;
    for (int x = x1 + 1; x <= x2; x++)
    {
        int ry0 = (y + dx - offset) / (2 * dx);
        int ry1 = (y + dx - 1 + offset) / (2 * dx);
        if (change == 0)
        {
            if (z < a[x - 1][ry0] * 2 * dx || z < a[x][ry1] * 2 * dx) return 0;
        }
        else
        {
            if (z < a[ry0][x - 1] * 2 * dx || z < a[ry1][x] * 2 * dx) return 0;
        }
        z += 2 * dz; y += 2 * dy;
    }
    return 1;
}
int visible(int x, int y, int x1, int y1, int x2, int y2)
{
    if (see[x][y] != -1) return see[x][y];
    see[x][y] = ((check(x, y, x1, y1, 0) && check(y, x, y1, x1, 1)) ||
        (check(x, y, x2, y2, 0) && check(y, x, y2, x2, 1)));
    return see[x][y];
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, m; //n = row, m = col
        int sx, sy, ex, ey;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        sx--; sy--; ex--; ey--;
        if (sx == ex && sy == ey) { printf("The shortest path is 0 steps long.\n"); continue; }
        memset(step, 0, sizeof(step));
        memset(see, 0xff, sizeof(see));
        queue<Node> go, back;
        Node x;
        x.x = sx; x.y = sy; go.push(x);
        x.x = ex; x.y = ey; back.push(x);
        int res = -1;
        while (!go.empty() || !back.empty())
        {
            if (!go.empty())
            {
                x = go.front();
                go.pop();
                for (int i = 0; i < 4; i++)
                {
                    int xx = x.x + p[i][0];
                    int yy = x.y + p[i][1];
                    if (0 <= xx && xx < n && 0 <= yy && yy < m && a[x.x][x.y] - 3 <= a[xx][yy] && a[xx][yy] <= a[x.x][x.y] + 1)
                    {
                        if (xx == ex && yy == ey) { res = step[x.x][x.y] + 1; goto L_exit; }
                        else if (step[xx][yy] < 0) //found
                        {
                            res = step[x.x][x.y] + 1 + (-step[xx][yy]);
                            goto L_exit;
                        }
                        else if (step[xx][yy] == 0) //add
                        {
                            if (visible(xx, yy, sx, sy, ex, ey))
                            {
                                Node y;
                                y.x = xx; y.y = yy;
                                step[xx][yy] = step[x.x][x.y] + 1;
                                go.push(y);
                            }
                        }
                    }
                }
            }
            if (!back.empty())
            {
                x = back.front();
                back.pop();
                for (int i = 0; i < 4; i++)
                {
                    int xx = x.x + p[i][0];
                    int yy = x.y + p[i][1];
                    if (0 <= xx && xx < n && 0 <= yy && yy < m && a[x.x][x.y] - 1 <= a[xx][yy] && a[xx][yy] <= a[x.x][x.y] + 3)
                    {
                        if (xx == sx && yy == sy) { res = (-step[x.x][x.y]) + 1; goto L_exit; }
                        else if (step[xx][yy] > 0) //found
                        {
                            res = (-step[x.x][x.y]) + 1 + step[xx][yy];
                            goto L_exit;
                        }
                        else if (step[xx][yy] == 0) //add
                        {
                            if (visible(xx, yy, sx, sy, ex, ey))
                            {
                                Node y;
                                y.x = xx; y.y = yy;
                                step[xx][yy] = step[x.x][x.y] - 1;
                                back.push(y);
                            }
                        }
                    }
                }
            }
        }
    L_exit:
        if (res == -1) printf("Mission impossible!\n");
        else printf("The shortest path is %d steps long.\n", res);
    }
    return 0;
}
