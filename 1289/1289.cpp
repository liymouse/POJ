#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int high, num;
    while (scanf("%d %d", &high, &num) == 2)
    {
        if (high == 0) break;
        if (high == 1 && num == 1) { printf("0 1\n"); continue; }
        int H = num, L = 1;
        double target = log(num) / log(high);
        int N = L;
        while (L <= H)
        {
            int m = (L + H) / 2;
            double x = log(m) / log(m + 1);
            if (x == target) { N = m; break; }
            else if (x < target) L = m + 1;
            else H = m - 1;
        }
        int k = int(log(high) / log(N + 1) + 0.5) + 1;
        //printf("%d %d\n", N, k);
        if (N == 1) printf("%d %.0lf\n", k - 1, pow(2, k) - 1);
        else printf("%.0lf %.0lf\n", (pow(N, k - 1) - 1) / (N - 1), pow(N + 1, k) - pow(N, k));
    }
    return 0;
}