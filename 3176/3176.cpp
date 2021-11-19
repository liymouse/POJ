#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int n;
    int a[2][351] = { 0 }, x;
    scanf("%d", &n);
    scanf("%d", &x);
    a[0][0] = x;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        a[i & 1][0] = a[(i - 1) & 1][0] + x;
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &x);
            a[i & 1][j] = max(a[(i - 1) & 1][j - 1], a[(i - 1) & 1][j]) + x;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, a[(n - 1) & 1][i]);
    printf("%d\n", res);
    return 0;
}