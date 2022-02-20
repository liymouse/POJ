#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) printf("1\n");
        else if (n == 0 || m == 0) printf("0\n");
        else
        {
            int a = n - m;
            int b = (m + 1) / 2;
            if (((a + b - 1) & (b - 1)) == (b - 1)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
