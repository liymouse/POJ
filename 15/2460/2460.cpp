#include <stdio.h>

int main()
{
long x[100000] , y[100000] , xx , yy;
long n , i;
long tot1 , tot2 , k;

    while (scanf("%ld" , &n) == 1)
    {
        if (n == 0) return 0;
        tot1 = 0; tot2 = 0;
        k = (n + 1)/2;
        for (i = 0; i < k; i ++) scanf("%ld %ld" , &x[i] , &y[i]);
        for (i = 0; i < k; i ++)
        {
            if (((x[i] > x[k-1]) && (y[i] > y[k-1])) || ((x[i] < x[k-1]) && (y[i] < y[k-1]))) tot1 ++;
            if (((x[i] < x[k-1]) && (y[i] > y[k-1])) || ((x[i] > x[k-1]) && (y[i] < y[k-1]))) tot2 ++;
        }
        for (i = k; i < n; i ++) 
        {
            scanf("%ld %ld" , &xx , &yy);
            if (((xx > x[k-1]) && (yy > y[k-1])) || ((xx < x[k-1]) && (yy < y[k-1]))) tot1 ++;
            if (((xx < x[k-1]) && (yy > y[k-1])) || ((xx > x[k-1]) && (yy < y[k-1]))) tot2 ++;
        }
        printf("%d %d\n" , tot1 , tot2);
    }
    return 0;
}
