#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define abs(x) ((x)<0?-(x):(x))

void cross(double *dx, double *dy, double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
{
    *dx = (x1 + (y3 - y1)*(x2 - x1)) / (1 - (y4 - y3)*(x2 - x1));
    *dy = (y4 - y3)*(*dx) + y3;
}
double calArea(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double a1 = x2 - x1, b1 = y2 - y1;
    double a2 = x3 - x1, b2 = y3 - y1;
    double a3 = x4 - x1, b3 = y4 - y1;
    double area = abs((a1 * b2 - a2 * b1) + (a2 * b3 - a3 * b2)) / 2.0;
    return area;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        double x[32][32], y[32][32];
        x[0][0] = 0.0; y[0][0] = 0.0;
        x[0][n + 1] = 1.0; y[0][n + 1] = 0.0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &x[0][i]); y[0][i] = 0.0;
        }
        x[n + 1][0] = 0.0; y[n + 1][0] = 1.0;
        x[n + 1][n + 1] = 1.0; y[n + 1][n + 1] = 1.0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &x[n + 1][i]); y[n + 1][i] = 1.0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &y[i][0]); x[i][0] = 0.0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &y[i][n + 1]); x[i][n + 1] = 1.0;
        }
        double res = 0.0, area;
        for (int i = 1; i <= n+1; i++)
            for (int j = 1; j <= n+1; j++)
            {
                if (i <= n && j <= n)
                {
                    cross(&x[i][j], &y[i][j], x[0][j], y[0][j], x[n + 1][j], y[n + 1][j],
                        x[i][0], y[i][0], x[i][n + 1], y[i][n + 1]);
                }
                area = calArea(x[i - 1][j - 1], y[i - 1][j - 1], x[i - 1][j], y[i - 1][j], x[i][j], y[i][j], x[i][j - 1], y[i][j - 1]);
                if (area > res) res = area;
            }
        printf("%.6lf\n", res);
    }
    return 0;
}
