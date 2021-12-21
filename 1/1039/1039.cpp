#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct
{
    double x, y;
}Node;
Node a[50];
double res;
int n;

#define less(a,b) (a<=b+1e-6)

void check(int ii, int jj)
{
    double k = (a[jj].y-a[ii].y) / (a[jj].x-a[ii].x);
    double b = a[ii].y - k * a[ii].x;
    for (int i = 0; i < 2 * n; i++)
    {
        double y0 = a[i].x * k + b;
        if ((i % 2 == 0 && less(y0, a[i].y)) ||
            (i % 2 == 1 && less(a[i].y, y0))) continue;
        else if (i <= max(ii, jj)) return;
        else
        {
            double k1 = (a[i].y - a[i - 2].y) / (a[i].x - a[i - 2].x);
            double b1 = a[i - 2].y - k1 * a[i - 2].x;
            double x = (b1 - b) / (k - k1);
            res = max(res, x);
            return;
        }
    }
    res = a[2 * n - 1].x + 100;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        res = -1e10;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &a[2*i].x, &a[2*i].y);
            a[2*i+1].x = a[2*i].x;
            a[2*i+1].y = a[2*i].y - 1;
        }
        for (int i = 0; i < 2*n; i ++)
            for (int j = 0; j < 2*n; j++)
                if (i != j)
                {
                    check(i, j);
                }
        if (res >= a[2*n-1].x) printf("Through all the pipe.\n");
        else printf("%.2lf\n", res);
    }
    return 0;
}