#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char has[32768] = { 1 };
char a[32768] = { 0 };
int num[2], mask, n, found;

void dfs(int x, int pre)
{
    if (x == (1 << n))
    {
        //for (int i = 0; i < 1 << n; i++) printf("%d", a[i]); printf("\n");
        found = 1;
        return;
    }
    pre = (pre << 1) & mask;
    for (int i = 0; i < 2; i++)
        if (num[i])
        {
            int k = pre | i;
            if (has[k] == 0)
            {
                num[i] --;
                has[k] = 1;
                a[x] = i;
                dfs(x + 1, k);
                if (found) return;
                a[x] = 0;
                has[k] = 0;
                num[i] ++;
            }
        }
}
int main()
{
    int k;
    //freopen("ouroboros.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d %d", &n, &k) == 2)
    {
        if (n == 0) break;
        if (k == 0) { printf("0\n"); continue; }
        memset(has, 0, sizeof(has));
        memset(a, 0, sizeof(a));
        num[0] = (1 << (n - 1)) - n;
        num[1] = 1 << (n - 1);
        mask = (1 << n) - 1;
        has[0] = 1;
        found = 0;
        dfs(n, 0);
        int res = 0;
        for (int i = k; i < k + n; i++) res = (res << 1) | a[i%(1<<n)];
        printf("%d\n", res);
    }
    return 0;
}