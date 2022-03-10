#include <stdio.h>

int main()
{
long tot1 , tot2;
long x , y;
long t , h;

    scanf("%ld" , &t);
    for (h = 1; h <= t; h ++)
    {
        scanf("%ld %ld" , &x , &y);
        printf("Scenario #%d:\n" , h);
        tot1 = 0; tot2 = 0;
        while (1)
        {
            if (x % y == 0) {tot1 += x / y - 1; break;}
            if (y % x == 0) {tot2 += y / x - 1; break;}
            if (x > y) {tot1 += x / y; x = x % y;}
            else if (x < y) {tot2 += y / x; y = y % x;}
        }
        printf("%ld %ld\n\n" , tot1 , tot2);
    }
    return 0;
}
