#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int st[60], st_num = 0, num[60];
int n, m;
int a[101];
int f[101][60][60] = { 0 };

void getState(int m)
{
    st_num = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        int s = i;
        int pre = -10;
        int ok = 1;
        int j = 0;
        while (s)
        {
            if (s & 1) {
                if (j - pre <= 2) { ok = 0; break; }
                pre = j;
            }
            s >>= 1;
            j++;
        }
        if (ok)
        {
            int t = i;
            num[st_num] = 0;
            while (t) { num[st_num]++; t &= t - 1; }
            st[st_num++] = i;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    getState(m);
    for (int i = 1; i <= n; i++)
    {
        char s[15];
        scanf("%s", s);
        a[i] = 0;
        for (int j = 0; j < m; j++) if (s[j] == 'H') a[i] |= 1 << j;
    }
    for (int i = 1; i <= n; i ++)
        for (int as = 0; as < st_num; as ++)
            if ((st[as] & a[i]) == 0)
            for (int bs = 0; bs < st_num; bs ++)
                if ((st[as] & st[bs]) == 0)
                {
                    int maxv = 0;
                    for (int cs = 0; cs < st_num; cs++)
                        if ((st[as] & st[cs]) == 0 && (st[bs] & st[cs]) == 0)
                        {
                            maxv = max(maxv, f[i - 1][bs][cs]);
                        }
                    f[i][as][bs] = maxv + num[as];
                }
    int res = 0;
    for (int i = 0; i < st_num; i++)
        for (int j = 0; j < st_num; j++)
            if (f[n][i][j] > res) res = f[n][i][j];
    printf("%d\n", res);
    return 0;
}