#include <stdio.h>
typedef long long i64d;

i64d f[1000003] = { 0 };
int main()
{
    int n;
    scanf("%d", &n);
    f[1] = 1; f[2] = 2;
    for (int i = 3; i <= n; i+=2)
    {
        f[i] = f[i - 1];
        f[i + 1] = (f[i - 1] + f[(i+1) / 2]) % 1000000000;
    }
    printf("%lld\n", f[n]);
    return 0;
}