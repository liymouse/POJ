#include <stdio.h>

typedef long long i64d;

int gcd(int a , int b)
{
    if (b == 0) return a;
    return gcd(b , a % b);
}
int main()
{
    int w , h;
    while (scanf("%d %d" , &w , &h) == 2)
    {
        if (w == 0 && h == 0) break;
        int t = gcd(w , h);
        printf("%lld\n" , (i64d)(w / t) * (h / t));
    }
    return 0;
}
