#include <stdio.h>

int main()
{
long a , b , c , d , t , i;

    for (i = 1;;i++)
    {
        scanf("%ld %ld %ld %ld" , &a , &b , &c , &d);
        if (a == -1) break;
        t = d + 1;
        while (((t - c) % 33 != 0) || ((t - a) % 23 != 0) || ((t - b) % 28 != 0))
            t ++;
        printf("Case %d: the next triple peak occurs in %ld days.\n" , i , t - d);
    }
    return 0;
}
