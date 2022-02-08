#include <stdio.h>
#include <string.h>
int c[200], L[200], n;
int memo[200][200][201];
int find(int sx, int ex, int len)
{
    if (memo[sx][ex][len]) return memo[sx][ex][len];
    if (sx == ex) memo[sx][ex][len] = (L[sx] + len)*(L[sx] + len);
    else
    {
        memo[sx][ex][len] = find(sx, ex - 1, 0) + (L[ex] + len)*(L[ex] + len);
        for (int k = sx; k < ex; k++)
            if (c[k] == c[ex])
            {
                int res = find(sx, k, L[ex] + len) + find(k + 1, ex - 1, 0);
                if (res > memo[sx][ex][len]) memo[sx][ex][len] = res;
            }
    }
    return memo[sx][ex][len];
}
int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int m;
        scanf("%d", &m);
        int a[200];
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        int n = 0;
        int pre = -1;
        memset(c, 0, sizeof(c));
        memset(L, 0, sizeof(L));
        memset(memo, 0, sizeof(memo));
        for (int i = 0; i < m; i++)
        {
            if (a[i] == pre) L[n-1] ++;
            else
            {
                pre = a[i];
                L[n] = 1;
                c[n] = a[i];
                n++;
            }
        }
        printf("Case %d: %d\n", ca, find(0, n - 1, 0));
    }
    return 0;
}