#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    double x1, y1;
    double x2, y2;
}Node;
Node a[22];
double res;
int n;

double cha(double xa, double ya, double xb, double yb)
{
    return xa * yb - xb * ya;
}
//a,b is a line, c is point
double cross(double cx, double cy, double ax, double ay, double bx, double by)
{
    return cha(bx - ax, by - ay, cx - ax, cy - ay);
}
void check(double x1, double y1, double x2, double y2)
{
    double k = (y2 - y1) / (x2 - x1);
    double b = (y1*x2 - y2 * x1) / (x2 - x1);
    double y0 = a[0].x1 * k + b;
    if (a[0].y2 <= y0 && y0 <= a[0].y1)
    {
        double line_x = x2 - x1;
        double line_y = y2 - y1;
        int has = 0;
        for (int i = 1; i < n; i++)
        {
            double ex = 1e100;
            has = 0;
            //cross up line
            if (cha(line_x, line_y, a[i].x1 - x1, a[i].y1 - y1) < 0 ||
                cha(line_x, line_y, a[i - 1].x1 - x1, a[i - 1].y1 - y1) < 0)
            {
                double k1 = (a[i].y1 - a[i - 1].y1) / (a[i].x1 - a[i - 1].x1);
                double b1 = (a[i - 1].y1 * a[i].x1 - a[i].y1 * a[i - 1].x1) / (a[i].x1 - a[i - 1].x1);
                double cross_x = (b1 - b) / (k - k1);
                if (cross_x < ex) ex = cross_x;
                has = 1;
            }
            if (cha(line_x, line_y, a[i].x2 - x1, a[i].y2 - y1) > 0 ||
                cha(line_x, line_y, a[i - 1].x2 - x1, a[i - 1].y2 - y1) > 0)
            {
                double k1 = (a[i].y2 - a[i - 1].y2) / (a[i].x2 - a[i - 1].x2);
                double b1 = (a[i - 1].y2 * a[i].x2 - a[i].y2 * a[i - 1].x2) / (a[i].x2 - a[i - 1].x2);
                double cross_x = (b1 - b) / (k - k1);
                if (cross_x < ex) ex = cross_x;
                has = 1;
            }
            if (has)
            {
                if (ex > res) res = ex;
                break;
            }
        }
        if (!has) // pass all
        {
            res = a[n - 1].x1 + 1;
        }
    }
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &a[i].x1, &a[i].y1);
            a[i].x2 = a[i].x1;
            a[i].y2 = a[i].y1 - 1;
        }
        res = a[0].x1;
        for (int i = 0; i < n; i ++)
            for (int j = i + 1; j < n; j++)
            {
                check(a[i].x1, a[i].y1, a[j].x1, a[j].y1);
                check(a[i].x1, a[i].y1, a[j].x2, a[j].y2);
                check(a[i].x2, a[i].y2, a[j].x1, a[j].y1);
                check(a[i].x2, a[i].y2, a[j].x2, a[j].y2);
            }
        if (res >= a[n - 1].x1) printf("Through all the pipe.\n");
        else printf("%lf\n", res);
    }
    return 0;
}