#include <stdio.h>
#include <string.h>
int a[102][101][101];
int w, h;
int p[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
void check(int st, int et, int inc)
{
    for (int t = st; t != et; t += inc)
    {
        for (int y = 1; y <= h; y ++)
            for (int x = 1; x <= w; x++)
            {
                if (a[t][y][x] == 0)
                {
                    int ok = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        int xx = x + p[i][0];
                        int yy = y + p[i][1];
                        if (1 <= xx && xx <= w && 1 <= yy && yy <= h && a[t - inc][yy][xx] == 0)
                        {
                            ok = 1; break;
                        }
                    }
                    if (ok == 0) a[t][y][x] = 1;
                }
            }
    }
}
int main()
{
    int t;
    int ca = 1;
    while (scanf("%d %d %d", &w, &h, &t) == 3)
    {
        if (w == 0) break;
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int tt, sx, sy, ex, ey;
            scanf("%d %d %d %d %d", &tt, &sx, &sy, &ex, &ey);
            for (int y = sy; y <= ey; y++)
                for (int x = sx; x <= ex; x++)
                    a[tt][y][x] = 1;
        }
        check(1, t, 1);
        check(t, 1, -1);
        int ansx[101], ansy[101], num[101];
        int res = 2; //0 = solutions, 1=esp, 2=unknown
        for (int i = 1; i <= t; i++)
        {
            num[i] = 0;
            for (int y = 1; y <= h; y ++)
                for (int x = 1; x <= w; x ++)
                    if (a[i][y][x] == 0) { ansx[i] = x; ansy[i] = y; num[i]++; }
            if (num[i] == 0) { res = 1; break; }
            if (num[i] == 1) res = 0;
        }
        printf("Robbery #%d:\n", ca++);
        if (res == 1) printf("The robber has escaped.\n");
        else if (res == 2) printf("Nothing known.\n");
        else
        {
            for (int i = 1; i <= t; i++)
                if (num[i] == 1) printf("Time step %d: The robber has been at %d,%d.\n", i, ansx[i], ansy[i]);
        }
        printf("\n");

    }
}