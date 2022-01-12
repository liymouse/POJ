#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n;
int a[55][55];
int v[55];
int split = 1;

void dfs(int x)
{
    v[x] = 1;
    for (int i = 0; i < n; i ++)
        if (a[x][i] && v[i] == 0)
        {
            dfs(i);
        }
}
void dfs2(int x)
{
    v[x] = 2;
    for (int i = 0; i < n; i ++)
        if (a[x][i] && v[i] != 2)
        {
            if (v[i] == 1) {
                split = 0; return;
            }
            else dfs2(i);
        }
}
int main()
{
    int full_map[55][55] = { 0 };
    n = 0;
    int x;
    while (scanf("%d", &x) == 1)
    {
        if (x == -1) break;
        if (x == -2) n++;
        else full_map[n][x] = 1;
    }
    n++;
    int res[55] = { 0 };
    for (int i = 1; i < n-1; i++)
    {
        memcpy(a, full_map, sizeof(full_map));
        for (int j = 0; j < n; j++)
            a[i][j] = a[j][i] = 0;
        memset(v, 0, sizeof(v));
        dfs(0);
        if (v[n - 1] == 0) res[i] = 1;

        split = 0;
        for (int j = 0; j < n; j++)
            if (full_map[i][j] && v[j] != 2)
            {
                if (v[j] == 1) { split = 0; break; }
                else
                {
                    split = 1;
                    dfs2(j);
                    if (split == 0) break;
                }
            }
        if (split) res[i] = 2;
    }
    int num = 0;
    for (int i = 0; i < n; i++) if (res[i] > 0) num++;
    printf("%d", num);
    for (int i = 0; i < n; i++) if (res[i] > 0) printf(" %d", i);
    printf("\n");
    num = 0;
    for (int i = 0; i < n; i++) if (res[i] == 2) num++;
    printf("%d", num);
    for (int i = 0; i < n; i++) if (res[i] == 2) printf(" %d", i);
    printf("\n");
    return 0;
}