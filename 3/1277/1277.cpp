#include <stdio.h>
typedef long long lld;

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        lld res = 0;
        if (n <= 3) res = 0;
        else if (n % 2 == 1) res = (n / 2 - 1) * n;
        else res = ((n - 1) / 2 - 1)*n + 1;
        printf("%lld\n", res);
    }
    return 0;
}