#include <stdio.h>

int main()
{
int m , n , k , i , j , t;
double tot1 , tot2 , av1 , av2;
double a[10001];

    scanf("%d %d %d" , &m , &n , &k);
    tot1 = 0; tot2 = 0;
    for (i = 1; i <= n; i ++)
    {
        scanf("%lf" , &a[i]);
        tot2 += a[i];
        if (i > n - m) tot1 += a[i];
    }
    av1 = tot1 / m; av2 = tot2 / n;
    if (av1 > av2) {printf("BUY ON DAY %d\n" , n); t = 1;}
    else {printf("SELL ON DAY %d\n" , n); t = -1;}
    for (i = n + 1; i <= k; i ++)
    {
        scanf("%lf" , &a[i]);
        tot1 -= a[i-m]; tot1 += a[i];
        tot2 -= a[i-n]; tot2 += a[i];
        av1 = tot1 / m; av2 = tot2 / n;
        if ((av1 > av2) && (t == -1))
        {
            t = 1;
            printf("BUY ON DAY %d\n" , i);
        }
        else if ((av1 < av2) && (t == 1))
        {
            t = -1;
            printf("SELL ON DAY %d\n" , i);
        }
    }
    return 0;
}
