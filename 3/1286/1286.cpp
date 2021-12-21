#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef long long lld;

int gcd(int x, int y)
{
    while (y)
    {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

lld p3[24] = { 1 };
lld polya(int n)
{
    lld sum = 0;
    if (n == 0) return 0;
    for (int i = 1; i <= n; i++)
        sum += p3[gcd(i, n)];
    if (n % 2 == 0)
    {
        sum += p3[n / 2 + 1] * (n/2); //line middle flip
        sum += p3[n / 2] * (n / 2); //point flip
    }
    else
    {
        sum += p3[n / 2 + 1] * n;
    }
    return sum / n / 2;
}
int main()
{
    int n;
    p3[0] = 1;
    for (int i = 1; i < 24; i++) p3[i] = p3[i - 1] * 3;
    while (scanf("%d", &n) == 1)
    {
        if (n == -1) break;
        printf("%lld\n", polya(n));
    }
    return 0;
}