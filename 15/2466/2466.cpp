#include <stdio.h>

int main()
{
long k[50] , a[10] , c[50];
long n , nk , x;
long i , j , sum , t , b , p , q;
long done;

    while (scanf("%ld" , &n) == 1)
    {
        nk = n * (n - 1) / 2;
        for (i = 0; i < nk; i ++) scanf("%ld" , &k[i]);
        for (i = 1; i < nk; i ++)
            for (j = nk-1; j >= i; j --)
                if (k[j] < k[j-1]) {x = k[j]; k[j] = k[j-1]; k[j-1] = x;}
        i = 2; sum = k[0] + k[1];
        b = 0;
	while (i < nk)
        {
            t = sum + k[i];
            if (t % 2 == 1) i ++;
            else
            {
                b = 1;
                t = t/2;
                for (j = 0; j < nk; j ++) c[j] = 0;
                a[0] = t - k[i];
                a[1] = t - k[1];
                a[2] = t - k[0];
                c[i] = 1; c[1] = 1; c[0] = 1;
                for (j = 3; j < n; j ++)
                {
                    for (p = 0; p < nk; p ++) if (c[p] == 0) break;
                    a[j] = k[p] - a[0]; c[p] = 1;
                    for (p = 1; p < j; p ++)
                    {
                        done = 0;
                        for (q = 0; q < nk; q ++)
                            if ((c[q] == 0) && (k[q] == a[j] + a[p])) {done = 1; c[q] = 1; break;}
                        if (done == 0) break;
                    }
                    if (done == 0) break;
                }
                if (done == 0) {i ++; b = 0; continue;}
                else break;
            }
        }
        if (b == 0) printf("Impossible\n");
        else
        {
            for (i = 0; i < n-1; i ++) printf("%ld " , a[i]); printf("%ld\n" , a[n-1]);
        }
    }
    
    return 0;
}
