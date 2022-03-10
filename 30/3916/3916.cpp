#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        int a , last;
        scanf("%d" , &a);
        printf("%d " , a);
        last = a;
        for (int i = 1; i < n; i ++)
        {
            scanf("%d" , &a);
            if (a != last)
            {
                last = a;
                printf("%d " , a);
            }
        }
        printf("$\n");
    }
    return 0;
}
