#include <stdio.h>

int gcd(int a , int b)
{
    if (b == 0) return a;
    return gcd(b , a%b);
}
int main()
{
    char s[10];
    while (scanf("%s" , s) == 1)
    {
        int a1 , b1 , a2 , b2;
        char c;
        sscanf(s , "%d/%d%c%d/%d" , &a1 , &b1 , &c , &a2 , &b2);
        int mu = b1 * b2 / gcd(b1 , b2);
        a1 *= mu / b1;
        a2 *= mu / b2;
        if (c == '+') a1 += a2;
        else a1 -= a2;
        int k = 0;
        if (a1 < 0) {k = 1; a1 = -a1;}
        int x = gcd(a1 , mu);
        if (x != 0) {a1 /= x; mu /= x;}
        if (k) printf("-");
        if (mu > 1)
            printf("%d/%d\n" , a1 , mu);
        else
            printf("%d\n" , a1);
    }
    return 0;
}
