#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int a[500501];
bool has[500501];
int bush[1001];
int num[10001];
int n, m, res;

void dfs(int x)
{
    if (x == n)
    {
        res = 1;
        for (int i = 0; i < n; i++) res *= bush[i];
        return;
    }
    for (int i = 0; i < m; i ++)
        if (!has[i])
        {
            bush[x] = a[i];
            int sum = 0;
            int ok = 1;
            int t = -1;
            for (int j = x; j >= 0; j--)
            {
                sum += bush[j];
                if (num[sum] == 0) { t = j;  ok = 0; break; }
                num[sum] --;
            }
            if (ok)
            {
                has[i] = true;
                dfs(x + 1);
                if (res > 0) return;
                has[i] = false;
            }
            sum = 0;
            for (int j = x; j > t; j--)
            {
                sum += bush[j];
                num[sum] ++;
            }
            bush[x] = 0;
        }
}
int main()
{
    //freopen("1457.in", "r", stdin);
    while (scanf("%d", &m) == 1)
    {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]); num[a[i]] ++;
        }
        n = (int)(sqrt((double)m * 8 + 1) + 0.5);
        if (n * n != m * 8 + 1 || (n-1)%2 != 0 || n-1 <= 0) printf("No solution\n");
        else
        {
            n = (n - 1) / 2;
            res = 0;
            memset(has, 0, sizeof(has));
            dfs(0);
            if (res > 0) printf("%d\n", res);
            else printf("No solution\n");
        }
    }
    return 0;
}