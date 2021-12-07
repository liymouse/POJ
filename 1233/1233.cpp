#include <stdio.h>
#include <string.h>
#define min(x,y) ((x)<(y)?(x):(y))

char a[2][20][20] = { 0 };
int f[2][20][20] = { 0 };
int n, m;
int cur, nxt;
int d[2][7][2] = { { { 1, 0 },{ 1, 1 },{ 0, 1 },{ -1, 1 },{ -1, 0 },{ 0, -1 }, {0,0} } ,
{ {1, -1}, {1, 0}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {0,0}} };

void getNextMap()
{
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j++)
        {
            int c_num = 0;
            for (int k = 0; k < 6; k++)
            {
                if (a[cur][i + d[i%2][k][0]][j + d[i%2][k][1]] == 'C') c_num++;
            }
            if (a[cur][i][j] == 'H')
            {
                if (c_num == 3) a[nxt][i][j] = 'C';
                else a[nxt][i][j] = 'H';
            }
            else
            {
                if (c_num == 2 || c_num == 3) a[nxt][i][j] = 'C';
                else a[nxt][i][j] = 'H';
            }
        }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) scanf("%s", &a[0][i][1]);
        cur = 0;
        nxt = 1;
        for (int i = 1; i <= m; i ++)
            if (a[cur][1][i] == 'C') f[cur][1][i] = 1;
        int res = -1;
        for (int t = 1; t <= 1000; t++)
        {
            for (int j = 1; j <= m; j++)
                if (f[cur][n][j]) {res = t; break; }
            if (res != -1) break;
            getNextMap();
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    if (a[nxt][i][j] == 'C')
                    {
                        int id = i % 2;
                        f[nxt][i][j] = 0;
                        for (int dir = 0; dir < 7; dir++)
                            f[nxt][i][j] = f[nxt][i][j] | f[cur][i + d[id][dir][0]][j + d[id][dir][1]];
                    }
                    else f[nxt][i][j] = 0;
                }
            cur = 1 - cur;
            nxt = 1 - nxt;
        }
        if (res == -1) printf("impossible\n");
        else printf("%d\n", res);
    }
    return 0;
}