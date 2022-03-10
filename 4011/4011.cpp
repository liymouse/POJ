#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        int res = 0;
        if (n <= 198)
        {
            for (int a = 0; a < 100; a ++)
                if (n - a >= 0 && n - a < 100) res ++;
        }
        printf("%d\n" , res);
    }
    return 0;
}