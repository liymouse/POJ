#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int a, b;
    int m = 15;
    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0) break;
        int k[510] = { 0 };
        for (int n = a; n <= b; n++)
        {
            int p = 0;
            for (int i = 2; i <= n; i++)
                p = (p + m) % i;
            if (p != 0) k[p] = k[n - p] = 1;
        }
        int ok = 0;
        for (int i = 1; i <= a / 2; i++)
        {
            if (k[i] == 0) {
                printf("%d\n", i);
                ok = 1;
                break;
            }
        }
        if (!ok) printf("Better estimate needed\n");
    }
    return 0;
}