#include <stdio.h>

int main()
{
int a[1000] , b[1000] , c[1000] , i , j , k , n , *p , *q , *s;
int t1 , t2 , t3 , x , *t;

    while (scanf("%d" , &n) == 1)
    {
        for (i = 0; i < 1000; i ++) {a[i] = 0; b[i] = 0; c[i] = 0;}
        t1 = 1; t2 = 1; a[0] = 1; b[0] = 1; t3 = 0;
        p = a; q = b; s = c;
        for (i = 2; i <= n; i ++)
        {
            if (t2 > t3) k = t2; else k = t3;
            for (j = 0; j < k; j ++)
            {
                s[j] += q[j];
                if (s[j] > 9)
                {
                    s[j+1] += s[j] / 10;
                    s[j] = s[j] % 10;
                }
            }
            if (s[k] > 0) k ++; t3 = k;
            if (t1 > t3) k = t1; else k = t3;
            for (j = 0; j < k; j ++)
            {
                s[j] += 2 * p[j];
                if (s[j] > 9)
                {
                    s[j + 1] += s[j] / 10;
                    s[j] = s[j] % 10;
                }
            }
            if (s[k] > 0) k ++; t3 = k;
            t = p; p = q; t1 = t2; q = s; t2 = t3; s = t;
            for (j = 0; j < 1000; j ++) s[j] = 0;
        }
        for (j = t2 - 1; j >= 0; j --) printf("%d" , q[j]);
        printf("\n");
    }
    return 0;
}
