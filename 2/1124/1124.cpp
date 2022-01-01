#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct
{
    int x, y;
}Point;
char a[23][23];
int p[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int w, h;
int main()
{
    int px[26], py[26];
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++)
    {
        scanf("%s", a[i]);
        for (int j = 0; j < w; j ++)
            if ('A' <= a[i][j] && a[i][j] <= 'O') { px[a[i][j] - 'A'] = j; py[a[i][j] - 'A'] = i; }
    }
    double res[23][23] = { 0 };
    char str[5];
    int people;
    while (scanf("%s %d", str, &people) == 2)
    {
        if (str[0] == 'X' && people == 0) break;
        int step[23][23] = { 0 };
        memset(step, 0xff, sizeof(step));
        queue<Point> qu;
        int si = str[0] - 'A';
        int ei = str[1] - 'A';
        Point x = { px[si], py[si] };
        step[py[si]][px[si]] = 0;
        qu.push(x);
        while (!qu.empty())
        {
            Point cur = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = cur.x + p[i][0];
                int yy = cur.y + p[i][1];
                if (0 <= xx && xx < w && 0 <= yy && yy <= h &&
                    step[yy][xx] == -1 && (a[yy][xx] == '.' || a[yy][xx] == str[1]))
                {
                    step[yy][xx] = step[cur.y][cur.x] + 1;
                    if (a[yy][xx] == '.')
                    {
                        Point nxt = { xx, yy };
                        qu.push(nxt);
                    }
                }
            }
        }
        int num[23][23] = { 0 };
        x.x = px[ei]; x.y = py[ei];
        num[py[ei]][px[ei]] = 1;
        qu.push(x);
        while (!qu.empty())
        {
            Point cur = qu.front();
            qu.pop();
            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int xx = cur.x + p[i][0];
                int yy = cur.y + p[i][1];
                if (0 <= xx && xx < w && 0 <= yy && yy <= h &&
                    step[yy][xx] == step[cur.y][cur.x] - 1)
                {
                    if (num[yy][xx] == 0 && a[yy][xx] == '.')
                    {
                        Point nxt = { xx, yy };
                        qu.push(nxt);
                    }
                    num[yy][xx] += num[cur.y][cur.x];
                }
            }
        }
        double b[23][23] = { 0 };
        x.x = px[si]; x.y = py[si];
        qu.push(x);
        b[py[si]][px[si]] = people;
        while (!qu.empty())
        {
            Point cur = qu.front();
            qu.pop();
            double pi = b[cur.y][cur.x] / num[cur.y][cur.x];
            for (int i = 0; i < 4; i++)
            {
                int xx = cur.x + p[i][0];
                int yy = cur.y + p[i][1];
                if (0 <= xx && xx < w && 0 <= yy && yy <= h &&
                    step[yy][xx] == step[cur.y][cur.x] + 1 &&
                    a[yy][xx] == '.' && num[yy][xx] > 0)
                {
                    if (b[yy][xx] == 0)
                    {
                        Point nxt = { xx, yy };
                        qu.push(nxt);
                    }
                    b[yy][xx] += num[yy][xx] * pi;
                }
            }
        }
        b[py[si]][px[si]] = 0;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) res[i][j] += b[i][j];
    }
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
            printf("%7.2lf", res[y][x]);
        printf("\n");
    }
    return 0;
}