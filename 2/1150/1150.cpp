#include <stdio.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        int res = 1;
        for (int i = n - m + 1; i <= n; i++)
        {
            res *= i;
            while (res % 10 == 0) res /= 10;
            res = res % 10;
        }
        printf("%d\n", res);
    }
    return 0;
}
