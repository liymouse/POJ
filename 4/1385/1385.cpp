#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double res = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
    return res / 2.0;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);
        double sum_area = 0;
        double sum_x = 0, sum_y = 0;
        for (int i = 2; i < n; i++)
        {
            scanf("%d %d", &x3, &y3);
            double area = getArea(x1, y1, x2, y2, x3, y3);
            sum_x += (x1 + x2 + x3) * area;
            sum_y += (y1 + y2 + y3) * area;
            sum_area += area;
            x2 = x3; y2 = y3;
        }
        printf("%.2lf %.2lf\n", sum_x / sum_area / 3.0, sum_y / sum_area / 3.0);
    }
    return 0;
}