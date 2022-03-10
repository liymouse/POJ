#include <stdio.h>

int main()
{
    int n , ca = 1;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        printf("%d. " , ca ++);
        if (n & 1) printf("odd "); else printf("even ");
        printf("%d\n" , (3 * n + 1) / 2 * 3 / 9);
    }
    return 0;
}