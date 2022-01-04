#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0) break;
        int has[1001] = { 0 };
        int L = 1;
        has[a] = 1;
        printf(".");
        int loop = 0;
        while (1)
        {
            int k = a * 10 / b;
            int t = a * 10 % b;
            if (L % 50 == 0) printf("\n");
            printf("%d", k);
            L++;
            if (t == 0) break;
            if (has[t] > 0) //loop
            {
                loop = L - has[t]; break;
            }
            has[t] = L;
            a = t;
        }
        printf("\n");
        if (loop == 0) printf("This expansion terminates.\n");
        else printf("The last %d digits repeat forever.\n", loop);
    }
    return 0;
}