#include <stdio.h>

int main()
{
int a[1000] , f[1000];
int n , i , j , max;

    scanf("%d" , &n);
    for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
    for (i = 0; i < n; i ++)
    {
        max = 0;
        for (j = 0; j < i; j ++)
            if ((a[j] < a[i]) && (f[j] > max)) max = f[j];
        f[i] = max + 1;
    }
    max = 0;
    for (i = 0; i < n; i ++) if (f[i] > max) max = f[i];
    printf("%d\n" , max);
    return 0;
}
