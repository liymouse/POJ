#include <stdio.h>

int main()
{
int m , i;
long n , s;

    while (scanf("%d" , &m) == 1)
    {
        scanf("%ld" , &n);
        s = n;
        for (i = 1; i < m; i ++)
        {
            scanf("%ld" , &n);
            s = s ^ n;
        }
        if (s == 0) printf("No\n"); else printf("Yes\n");
    }
    return 0;
}
