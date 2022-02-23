#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

int n, m;
int f[101][101][101][2];
int find(int tot, int remain, int steve_take, int is_steve)
{
    if (remain == 0) return is_steve ? steve_take : tot - steve_take;
    if (f[tot][remain][steve_take][is_steve] != -1) return f[tot][remain][steve_take][is_steve];
    int res = 0;
    if (is_steve)
    {
        if (remain <= m) res = max(res, tot - find(tot - steve_take - remain, tot - steve_take - remain, 0, 0));
        for (int i = 1; i <= min(remain, m); i++)
            res = max(res, tot - find(tot, remain - i, steve_take + i, 0));
    }
    else
    {
        if (remain <= m) res = max(res, tot - find(steve_take, steve_take, 0, 1));
        for (int i = 1; i <= min(remain, m); i++)
            res = max(res, tot - find(tot, remain - i, steve_take, 1));
    }
    f[tot][remain][steve_take][is_steve] = res;
    return res;
}
int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        memset(f, 0xff, sizeof(f));
        printf("%d\n", find(n,n,0,1));
    }
    return 0;
}
