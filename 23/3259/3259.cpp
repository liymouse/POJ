#include <stdio.h>
#include <algorithm>
using namespace std;
int a[505][505];
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, m, c;
        int x, y, z;
        scanf("%d %d %d", &n, &m, &c);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
            a[i][j] = (i == j) ? 0 : 20000;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            if (a[x][y] > z)
            {
                a[x][y] = a[y][x] = z;
            }
        }
        for (int i = 0; i < c; i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            a[x][y] = -z;
        }
        int has = 0;
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    if (a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
                if (a[i][i] < 0) { has = 1; goto L_exit; }
            }
    L_exit:
        if (has) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}