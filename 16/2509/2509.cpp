#include <stdio.h>

int main()
{
long n , k , tot , m;

    while (scanf("%ld %ld" , &n , &k) == 2)
    {
        m = 0; tot = 0;
        while (1)
        {
            m = n / k;
            n = n % k + m;
            tot += m * k;
            if (n < k) {tot += n; break;}
        }
        printf("%ld\n" , tot);
    }
    return 0;
}
