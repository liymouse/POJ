#include <stdio.h>

int main()
{
long n , m , p , c , k;

    while (scanf("%ld %ld %ld %ld" , &n , &m , &p , &c) == 4)
    {
        if ((n == 0) && (m == 0) && (p == 0) && (c == 0)) return 0;
        k = m - p - n;
        printf("%ld\n" , -k);
    }
    return 0;
}
