#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define abs(x) ((x)<0?(-(x)):(x))
#define EPS 1.0
#define INF2 1.0e15
#define INF 1.0e8

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        double a[2], b[2], c[2], d[2], h, f;
        scanf("%lf %lf %lf %lf %lf %lf", &a[0], &b[0], &c[0], &d[0], &h, &f);
        b[0] = -b[0];
        int p = 0;
        for (int i = 0; i < 100; i++)
        {
            a[1 - p] = a[p] * a[p] + b[p] * d[p];
            b[1 - p] = a[p] * b[p] + b[p] * c[p];
            d[1 - p] = d[p] * a[p] + c[p] * d[p];
            c[1 - p] = d[p] * b[p] + c[p] * c[p];
            p = 1 - p;
            if (abs(a[p]) > INF2 || abs(b[p]) > INF2 || abs(c[p]) > INF2 || abs(d[p]) > INF2) break;
        }
        double H = a[p] * h + b[p] * f;
        double F = d[p] * h + c[p] * f;
        if (abs(H) < EPS && abs(F) < EPS) printf("Ecological balance will develop.\n");
        else if (H < -INF && F > INF) printf("Hares will die out while foxes will overgrow.\n");
        else if (H > INF && F < -INF) printf("Hares will overgrow while foxes will die out.\n");
        else if (H < -INF && F < -INF) printf("Both hares and foxes will die out.\n");
        else if (H > INF && F > INF) printf("Both hares and foxes will overgrow.\n");
        else printf("Chaos will develop.\n");
    }
    return 0;
}