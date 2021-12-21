#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int a[10];
int s[55][105];
int tp[55][105];

int check()
{
    int c[626] = { 0 };
    c[0] = 1;
    for (int i = 0; i <= m * m; i++)
        if (c[i])
        {
            for (int j = 0; j < n; j++)
                if (i + a[j] * a[j] <= m*m)
                    c[i + a[j] * a[j]] = 1;
        }
    if (c[m*m]) return 1;
    else return 0;
}

int find(int x, int y)
{
    int ok = 0;
    for (int i = n-1; i >= 0; i --)
        if (tp[x][y] == 0) //up
        {
            int can = 1;
            //can_put
            if (x + (a[i] - 1) >= 2 * m) can = 0;
            if (can)
            {
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = -1*xx; yy <= xx; yy ++)
                        if (y+yy < 0 || y+yy >= 4*m-1 || s[x + xx][y + yy] != 0) { can = 0; break; }
                    if (can == 0) break;
                }
            }
            //if can, put and check next
            if (can)
            {
                //fill
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = -1 * xx; yy <= xx; yy++)
                        s[x + xx][y + yy] = 1;
                }
                //find next
                int xx = x;
                int yy = y + 1;
                if (yy >= 4 * m - 1) {
                    xx++; yy = 0;
                }
                while ((xx < 2 * m - 1 || (xx == 2 * m - 1 && yy < 3 * m)) && s[xx][yy] != 0)
                {
                    yy++;
                    if (yy >= 4 * m - 1)
                    {
                        xx++;
                        yy = 0;
                    }
                }
                if (xx == 2 * m - 1 && yy >= 3 * m)
                {
                    return 1;
                }
                ok = find(xx, yy);
                if (ok) return 1;
                //revert
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = -1 * xx; yy <= xx; yy++)
                        s[x + xx][y + yy] = 0;
                }
            }
        }
        else //down
        {
            int can = 1;
            //can_put
            if (x + (a[i] - 1) >= 2 * m) can = 0;
            if (can)
            {
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = xx; yy < 2 *a[i]-1-xx; yy ++)
                        if (y+yy >= 4*m-1 || s[x + xx][y + yy] != 0) { can = 0; break; }
                    if (can == 0) break;
                }
            }
            //if can, put and check next
            if (can)
            {
                //fill
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = xx; yy < 2 * a[i] - 1 - xx; yy++)
                        s[x + xx][y + yy] = 1;
                }
                //find next
                int xx = x;
                int yy = y + 1;
                if (yy >= 4 * m - 1) {
                    xx++; yy = 0;
                }
                while ((xx < 2 * m - 1 || (xx == 2 * m - 1 && yy < 3 * m)) && s[xx][yy] != 0)
                {
                    yy++;
                    if (yy >= 4 * m - 1)
                    {
                        xx++;
                        yy = 0;
                    }
                }
                if (xx == 2 * m - 1 && yy >= 3 * m)
                {
                    return 1;
                }
                ok = find(xx, yy);
                if (ok) return 1;
                //revert
                for (int xx = 0; xx < a[i]; xx++)
                {
                    for (int yy = xx; yy < 2 * a[i] - 1 - xx; yy++)
                        s[x + xx][y + yy] = 0;
                }
            }
        }
        return 0;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int x, y;
        n = 0;
        scanf("%d %d", &m, &x);
        for (int i = 0; i < x; i++)
        {
            scanf("%d", &y);
            int insert = 1;
            if (y > m) insert = 0;
            else
            {
                for (int j = 0; j < n; j++)
                    if (y % a[j] == 0) insert = 0;
            }
            if (insert) a[n++] = y;
        }
        int ok = 0;
        for (int i = 0; i < n; i++) if (m % a[i] == 0) ok = 1;
        if (!ok)
        {
            sort(a, a + n);
            //check area is ok or not
            ok = check();

            if (ok)
            {
                int out = m - 1;
                int in = 2 * m + 1;
                for (int i = 0; i < m; i++)
                {
                    int t = 0;
                    for (int k = 0; k < out; k++)
                    {
                        s[i][t] = 2;
                        tp[i][t] = 9;
                        t++;
                    }
                    for (int k = 0; k < in; k++)
                    {
                        s[i][t] = 0;
                        tp[i][t] = k % 2;
                        t++;
                    }
                    for (int k = 0; k < out; k++)
                    {
                        s[i][t] = 2;
                        tp[i][t] = 9;
                        t++;
                    }
                    out--;
                    in += 2;
                }
                out++;
                in -= 2;
                for (int i = m; i < 2 * m; i++)
                {
                    int t = 0;
                    for (int k = 0; k < out; k++)
                    {
                        s[i][t] = 2;
                        tp[i][t] = 9;
                        t++;
                    }
                    for (int k = 0; k < in; k++)
                    {
                        s[i][t] = 0;
                        tp[i][t] = (k % 2 == 0);
                        t++;
                    }
                    for (int k = 0; k < out; k++)
                    {
                        s[i][t] = 2;
                        tp[i][t] = 9;
                        t++;
                    }
                    out++;
                    in -= 2;
                }
                ok = find(0, m-1);
            }
        }

        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}