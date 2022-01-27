#include <stdio.h>
#include <string.h>
typedef long long lld;
lld f[17][16][2][4];
int st[4] = { 7, 11, 13, 14 };

lld find(int n, int s, int diff3, int last)
{
    if (f[n][s][diff3][last] != -1) return f[n][s][diff3][last];
    if (n == 1)
    {
        if (s == (1<<last) && diff3 == 0) f[n][s][diff3][last] = 1;
        else f[n][s][diff3][last] = 0;
        return f[n][s][diff3][last];
    }
    if ((s & (1 << last)) == 0) f[n][s][diff3][last] = 0;
    else
    {
        lld res = 0;
        if (last == 0 || last == 3)
        {
            if (diff3 == 0)
            {
                for (int i = 0; i < 16; i++)
                    if ((i | (1 << last)) == s)
                    {
                        for (int j = 0; j < 4; j++)
                            if (last != 3 - j)
                                res += find(n - 1, i, 0, j);
                    }
            }
            else
            {
                for (int i = 0; i < 16; i++)
                    if ((i | (1 << last)) == s)
                    {
                        for (int j = 0; j < 4; j++)
                            res += find(n - 1, i, 1, j);
                        res += find(n - 1, i, 0, 3 - last);
                    }
            }
        }
        else
        {
            for (int i = 0; i < 16; i++)
                if ((i | (1 << last)) == s)
                {
                    for (int j = 0; j < 4; j++)
                        res += find(n - 1, i, diff3, j);
                }
        }
        f[n][s][diff3][last] = res;
    }
    return f[n][s][diff3][last];
}
int main()
{
    int n;
    memset(f, 0xff, sizeof(f));
    while (scanf("%d", &n) == 1)
    {
        if (n == -1) break;
        lld res = 0;
        for (int i = 0; i < 4; i++)
        {
            res += find(n, 11, 1, i); //1011
            res += find(n, 13, 1, i); //1101
            res += find(n, 15, 1, i); //1111
        }
        printf("%d: %lld\n", n, res);
    }
    return 0;
}