#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int a[250][250];
    int bian[255][255] = { 0 };
    int has[255] = { 0 };
    int m, n, L;
    scanf("%d %d %d", &m, &n, &L);
    memset(a, 0xff, sizeof(a));
    for (int i = m + 1; i <= m + L; i++)
    {
        int x;
        scanf("%d", &x);
        has[x] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int num;
        scanf("%d", &num);
        int t0;
        scanf("%d", &t0);
        int pre = t0;
        for (int j = 1; j < num; j++)
        {
            int t;
            scanf("%d", &t);
            if (bian[t][pre] == 0)
            {
                bian[t][pre] = bian[pre][t] = i;
            }
            else
            {
                a[i][bian[t][pre]] = a[bian[t][pre]][i] = 1;
            }
            if (has[t]) a[has[t]][i] = 0;
            pre = t;
        }
        if (bian[t0][pre] == 0)
        {
            bian[t0][pre] = bian[pre][t0] = i;
        }
        else
        {
            a[i][bian[t0][pre]] = a[bian[t0][pre]][i] = 1;
        }
        if (has[t0]) a[has[t0]][i] = 0;
        a[i][i] = 0;
    }
    for (int k = 1; k <= m+L; k ++)
        for (int i = 1; i <= m+L; i ++)
            if (i != k)
            for (int j = 1; j <= m+L; j ++)
                if (i != j && k != j && a[i][k] != -1 && a[k][j] != -1 &&
                    (a[i][j] == -1 || (a[i][k] + a[k][j] < a[i][j])))
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
    int res = -1;
    for (int i = 1; i <= m; i++)
    {
        int sum = 0;
        for (int j = m + 1; j <= m + L; j++)
            sum += a[j][i];
        if (res == -1 || sum < res) res = sum;
    }
    printf("%d\n", res);
    return 0;
}
