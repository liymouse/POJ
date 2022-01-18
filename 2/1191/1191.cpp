#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct
{
    double sigma;
    double avg;
    int cal;
}Elm;
int n;
int a[9][9];
int sum[9][9] = { 0 };
Elm res;
Elm f[9][9][9][9][15];

Elm cal(int sx, int sy, int ex, int ey, Elm e, int k)
{
    int s = sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1];
    double avg = (double)(e.avg * (k - 1) + s) / k;
    double s2_avg = (e.sigma*(k - 1) + (k - 1)*e.avg*e.avg + s*s) / k;
    Elm r;
    r.sigma = s2_avg - avg * avg;
    r.avg = avg;
    return r;
}

Elm find(int sx, int sy, int ex, int ey, int k)
{
    if (f[sx][sy][ex][ey][k].cal) return f[sx][sy][ex][ey][k];
    f[sx][sy][ex][ey][k].cal = 1;
    if (k == 1)
    {
        f[sx][sy][ex][ey][k].avg = sum[ex][ey] - sum[sx - 1][ey] - sum[ex][sy - 1] + sum[sx - 1][sy - 1];
        f[sx][sy][ex][ey][k].sigma = 0;
    }
    else
    {
        f[sx][sy][ex][ey][k].sigma = 1e100;
        for (int i = sx; i < ex; i ++)
        {
            if ((ex - i)*(ey - sy + 1) >= k - 1)
            {
                Elm s = cal(sx, sy, i, ey, find(i + 1, sy, ex, ey, k - 1), k);
                if (s.sigma < f[sx][sy][ex][ey][k].sigma)
                {
                    f[sx][sy][ex][ey][k].sigma = s.sigma;
                    f[sx][sy][ex][ey][k].avg = s.avg;
                }
            }
            if ((i - sx + 1)*(ey - sy + 1) >= k - 1)
            {
                Elm s = cal(i + 1, sy, ex, ey, find(sx, sy, i, ey, k - 1), k);
                if (s.sigma < f[sx][sy][ex][ey][k].sigma)
                {
                    f[sx][sy][ex][ey][k].sigma = s.sigma;
                    f[sx][sy][ex][ey][k].avg = s.avg;
                }
            }
        }
        for (int i = sy; i < ey; i++)
        {
            if ((ey - i)*(ex - sx + 1) >= k - 1)
            {
                Elm s = cal(sx, sy, ex, i, find(sx, i+1, ex, ey, k - 1), k);
                if (s.sigma < f[sx][sy][ex][ey][k].sigma)
                {
                    f[sx][sy][ex][ey][k].sigma = s.sigma;
                    f[sx][sy][ex][ey][k].avg = s.avg;
                }
            }
            if ((i - sy + 1)*(ex - sx + 1) >= k - 1)
            {
                Elm s = cal(sx, i+1, ex, ey, find(sx, sy, ex, i, k - 1), k);
                if (s.sigma < f[sx][sy][ex][ey][k].sigma)
                {
                    f[sx][sy][ex][ey][k].sigma = s.sigma;
                    f[sx][sy][ex][ey][k].avg = s.avg;
                }
            }
        }
    }
    return f[sx][sy][ex][ey][k];
}
int main()
{
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= 8; i ++)
        for (int j = 1; j <= 8; j++)
        {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
        }
    res = find(1, 1, 8, 8, n);
    printf("%.3lf\n", sqrt(res.sigma));
    return 0;
}
