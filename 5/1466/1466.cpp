#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n;
int a[500][500];
int num[500];
int v[500];
int match[500];
int dfs(int p)
{
    for (int i = 0; i < num[p]; i ++)
        if (v[a[p][i]] == 0)
        {
            v[a[p][i]] = 1;
            if (match[a[p][i]] == -1 || dfs(match[a[p][i]]))
            {
                match[a[p][i]] = p;
                return 1;
            }
        }
    return 0;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        int x;
        for (int i = 0; i < n; i ++)
        {
            scanf("%d: (%d)", &x, &num[i]);
            for (int j = 0; j < num[i]; j++) scanf("%d", &a[i][j]);
        }
        int res = 0;
        memset(match, 0xff, sizeof(match));
        for (int i = 0; i < n; i ++)
        {
            memset(v, 0, sizeof(v));
            res += dfs(i);
        }
        printf("%d\n", n - res/2);
    }

    return 0;
}
