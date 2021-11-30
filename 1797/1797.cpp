#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))

int a[1001][1001];
int n;

int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int mark[1001] = { 0 };
        int dist[1001] = { 0 };
        int n, m;
        memset(a, 0, sizeof(a));
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            a[x][y] = a[y][x] = z;
        }
        for (int i = 2; i <= n; i++) if (a[1][i]) dist[i] = a[1][i];
        mark[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int k = -1;
            int maxv = 0;
            for (int j = 1; j <= n; j ++)
                if (mark[j] == 0 && dist[j] > maxv)
                {
                    maxv = dist[j]; k = j;
                }
            if (k == -1) break;
            mark[k] = 1;
            for (int j = 1; j <= n; j ++)
                if (mark[j] == 0 && a[k][j] > 0 && min(dist[k], a[k][j]) > dist[j])
                {
                    dist[j] = min(dist[k], a[k][j]);
                }
        }
        printf("Scenario #%d:\n%d\n\n", ca, dist[n]);
    }
    return 0;
}