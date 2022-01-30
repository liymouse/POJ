#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int n;
int a[32768];
int has[32768];

int rshift(int st, int k)
{
    for (int i = 0; i < k; i++)
        st = (st >> 1) | ((st & 1) << n - 1);
    return st;
}
int getMin(int st)
{
    int res = st;
    for (int i = 0; i < n; i++)
    {
        st = rshift(st, 1);
        if (st < res) res = st;
    }
    return res;
}
int convert(int st, int change[])
{
    int res = 0;
    int k0 = rshift(st, 2);
    int k1 = st;
    int k2 = rshift(st, n - 1);
    for (int i = 0; i < n; i++)
    {
        res = res | (change[((k0&1) << 2) + ((k1&1) << 1) + (k2&1)] << i);
        k0 >>= 1; k1 >>= 1; k2 >>= 1;
    }
    return getMin(res);
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        char s[17];
        scanf("%s", s);
        int st = 0;
        int change[8] = { 0 };
        for (int i = 0; i < n; i++)
            st = (st << 1) + s[i] - 'a';
        for (int i = 0; i < 8; i++)
        {
            scanf("%s", s);
            int id = ((s[0] - 'a') << 2) + ((s[1] - 'a') << 1) + s[2] - 'a';
            change[id] = s[3] - 'a';
        }
        int t;
        scanf("%d", &t);
        memset(has, 0xff, sizeof(has));
        a[0] = getMin(st);
        has[a[0]] = 0;
        int res = -1;
        for (int i = 1; i <= t; i++)
        {
            a[i] = convert(a[i - 1], change);
            if (has[a[i]] != -1)
            {
                res = (t - has[a[i]]) % (i-has[a[i]]) + has[a[i]]; break;
            }
            has[a[i]] = i;
        }
        if (res == -1) res = t;
        for (int i = n - 1; i >= 0; i--)
        {
            s[i] = (a[res] & 1) + 'a';
            a[res] >>= 1;
        }
        s[n] = 0;
        printf("%s\n", s);
    }
    return 0;
}