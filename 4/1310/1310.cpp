#include <stdio.h>

int main()
{
    int n, ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == -1) break;
        double L[7], g[7], y[7], r[7];
        for (int i = 0; i < n; i++) scanf("%lf %lf %lf %lf", &L[i], &g[i], &y[i], &r[i]);
        int a[66] = { 0 };
        for (int s = 30; s <= 60; s++)
        {
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                double t = L[i] * 3600 / s;
                double sum = g[i] + y[i] + r[i];
                t = t - sum * int(t / sum);
                if (t > g[i]+y[i]) //red
                {
                    ok = 0; break;
                }
            }
            if (ok) a[s] = 1;
        }
        printf("Case %d: ", ca++);
        int pre = -1;
        int first = 1;
        for (int i = 30; i <= 61; i ++)
            if (a[i])
            {
                if (pre == -1) pre = i;
            }
            else if (pre != -1)
            {
                if (first == 0) printf(", ");
                else first = 0;
                if (pre == i - 1) printf("%d", i-1);
                else printf("%d-%d", pre, i - 1);
                pre = -1;
            }
        if (first) printf("No acceptable speeds.");
        printf("\n");
    }
    return 0;
}