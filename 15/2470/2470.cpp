#include <stdio.h>

int main()
{
long a[100001] , b[100001] , i , n , k;

    while (scanf("%ld" , &n) == 1)
    {
        if (n == 0) return 0;
        for (i = 1; i <= n; i ++)
        {
            scanf("%ld" , &a[i]);
            b[a[i]] = i;
        }
        k = 0;
        for (i = 1; i <= n; i ++)
            if (a[i] != b[i]) {k = 1; break;}
        if (k == 0) printf("ambiguous\n");
        else printf("not ambiguous\n");
    }
    return 0;
}

