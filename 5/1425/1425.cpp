#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        double f1, f2, f3;
        //f1 = n(n-1)^n / ((n-1)^n -1) - 1 /(n-2)
        double a = 1.0;
        for (int i = 0; i < n; i++) a *= (double)n - 1;
        f1 = n * a / (a - 1) - 1.0 / (n - 2);

        //f2 = (1*n(n-1) + 2*n(n-1)*(n-2) + ... + (n-1)*n!) / (n(n-1)+n*(n-1)(n-2)+...+n!)
        //f3 = (3*n(n-1)*(n-2) + ... + n*n!) / (n*(n-1)(n-2)+...+n!)
        a = (double)n;
        f2 = 0.0;
        f3 = 0.0;
        double fenmu2 = 0.0;
        double fenmu3 = 0.0;
        for (int i = 1; i <= n - 1; i++)
        {
            a *= (double)(n - i);
            f2 += (double)i * a;
            fenmu2 += a;
            if (i > 1)
            {
                f3 += (double)(i + 1) * a;
                fenmu3 += a;
            }
        }
        f2 /= fenmu2;
        f3 /= fenmu3;

        printf("%.4lf %.4lf %.4lf\n", f1, f2, f3);
    }
    return 0;
}
