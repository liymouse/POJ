#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef long long lld;
lld f[52][105];
char a[50][105] = { 0 };
int n;

lld gcd(lld x, lld y)
{
    while (x % y)
    {
        lld r = x % y;
        x = y;
        y = r;
    }
    return y;
}
lld find(int L, int p)
{
    if (f[L][p] != -1) return f[L][p];
    if (p < n - L || p > n + L) return f[L][p] = 0;
    if (L == 0) return f[L][p] = 1;
    if (a[L - 1][p] == '*') return f[L][p] = 0;
    f[L][p] = 0;
    if (p > 0 && a[L - 1][p - 1] == '*') f[L][p] += find(L - 1, p - 1);
    if (p < 2*n && a[L-1][p+1] == '*') f[L][p] += find(L - 1, p + 1);
    if (a[L-1][p] != '*') f[L][p] += 2 * find(L - 1, p);

    return f[L][p];
}
int main()
{
    int m;
    char s[3];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%s", s);
            a[i][n - i + j * 2] = s[0];
        }
    }
    memset(f, 0xff, sizeof(f));
    lld fenmu = 1LL << n;
    lld fenzi = find(n, 2 * m);
    lld x = gcd(fenmu, fenzi);
    fenzi /= x; fenmu /= x;
    if (fenzi == 0) fenmu = 1;
    printf("%lld/%lld\n", fenzi, fenmu);
    return 0;
}