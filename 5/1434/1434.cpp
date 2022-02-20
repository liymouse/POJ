#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define EPS 0.0001

int b[50000], h[50000], w[50000], d[50000];
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        double high = 0;
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &b[i], &h[i], &w[i], &d[i]);
            if (b[i] + h[i] > high) high = b[i] + h[i];
            sum += (double)h[i] * w[i] * d[i];
        }
        double v;
        scanf("%lf", &v);
        if (v >= sum + EPS) { printf("OVERFLOW\n"); continue; }
        double low = 0.0;
        double res = 0.0;
        while (low < high)
        {
            double mid = (low + high) / 2;
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (mid > b[i])
                {
                    sum += min(mid - b[i], h[i]) * (double)w[i] * d[i];
                    if (sum > v + EPS) break;
                }
            }
            res = mid;
            if (v - EPS <= sum && sum <= v + EPS) break;
            else if (sum < v - EPS) low = mid + 0.0001;
            else high = mid - 0.0001;
        }
        double maxv = 0.0;
        int ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] + h[i] < res) maxv = max(maxv, b[i] + h[i]);
            if (b[i] < res && res <= b[i] + h[i]) { ok = 1; break; }
        }
        if (ok) printf("%.2lf\n", res);
        else printf("%.2lf\n", maxv);
    }
    return 0;
}
