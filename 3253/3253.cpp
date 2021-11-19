#include <stdio.h>
typedef long long i64d;
int main()
{
    int n;
    int a[20001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    i64d res = 0;
    while (n > 1)
    {
        int m1 = 0, m2 = 1;
        if (a[m1] > a[m2]) { int t = m1; m1 = m2; m2 = t; }
        for (int i = 2; i < n; i ++)
            if (a[i] < a[m1])
            {
                m2 = m1;
                m1 = i;
            }
            else if (a[i] < a[m2])
            {
                m2 = i;
            }
        int s = a[m1] + a[m2];
        res += s;
        if (m1 == n - 1) { int t = m1; m1 = m2; m2 = t; }
        a[m1] = s;
        a[m2] = a[n - 1];
        n--;
    }
    printf("%lld\n", res);
    return 0;
}