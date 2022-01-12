#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int high, num;
    while (scanf("%d %d", &high, &num) == 2)
    {
        if (high == 0 && num == 0) break;
        if (high == 1 && num == 1) { printf("0 1\n"); continue; }
        int H = num, L = 1;
        double target = log((double)num) / log((double)high);
        int N = L;
        while (L <= H)
        {
            int m = (L + H) / 2;
            double x = log((double)m) / log((double)m + 1);
            if (fabs(x -target) < 1e-10) { N = m; break; }
            else if (x < target) L = m + 1;
            else H = m - 1;
        }
        int k = int(log((double)high) / log((double)N + 1) + 0.5);
        //printf("%d %d\n", N, k);
        if (N == 1) printf("%d ", k);
        else printf("%.0lf ", (pow((double)N, k) - 1) / (N - 1));
        printf("%.0lf\n", (1 - pow((double)N / (N + 1), k + 1))*(N + 1)*high);
    }
    return 0;
}