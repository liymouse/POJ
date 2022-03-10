#include <stdio.h>
typedef long long i64d;
int main()
{
    int n, s;
    scanf("%d %d", &n, &s);
    i64d tot = 0;
    i64d low_p = -1, low_i = -1;
    for (int i = 0; i < n; i++)
    {
        int c, y;
        scanf("%d %d", &c, &y);
        if (low_p == -1)
        {
            low_p = c; low_i = i;
        }
        if (low_p + (i64d)(i - low_i)*s < c)
        {
            tot += (i64d)y * (low_p + (i64d)(i - low_i)*s);
        }
        else
        {
            tot += (i64d)c * y;
            low_p = c; low_i = i;
        }
    }
    printf("%lld\n", tot);
    return 0;
}