#include <stdio.h>

typedef long long i64d;

int main()
{
    int n;
    i64d C[10010] = {0};
    for (i64d i = 4; i <= 10000; i ++) C[i] = i*(i-1)*(i-2)*(i-3)/24;
    while (scanf("%d" , &n) == 1)
    {
        int yinshu[10010] = {0}; //yinshu[i] i的质因数个数
        int count[10010] = {0}; //count[i] 有因数i的数的个数

        for (int i = 0; i < n; i ++)
        {
            int x , p[15] , tot = 0;
            scanf("%d" , &x);
            for (int j = 2; j * j <= x; j ++)
                if (x % j == 0)
                {
                    p[tot++] = j;
                    while (x % j == 0) x /= j;
                }
            if (x != 1) p[tot ++] = x;
            for (int j = 1; j < 1 << tot; j ++)
            {
                int t = 1 , num = 0;
                for (int k = 0; k < tot; k ++)
                    if ((1 << k) & j)
                    {
                        t *= p[k];
                        num ++;
                    }
                count[t] ++;
                yinshu[t] = num;
            }
        }
        i64d res = 0;
        for (int i = 1; i <= 10000; i ++)
            if (count[i])
            {
                if (yinshu[i] % 2 == 0) res -= C[count[i]];
                else res += C[count[i]];
            }
        printf("%lld\n" , C[n] - res);
    }
    return 0;
}
