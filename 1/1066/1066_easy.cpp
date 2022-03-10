#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int linecross(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
{
    if (((x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) * ((x4 - x2)*(y1 - y2) - (y4 - y2)*(x1 - x2)) < 0 &&
        ((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) * ((x2 - x3)*(y4 - y3) - (y2 - y3)*(x4 - x3)) < 0)
        return 1;
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int x0[33], y0[33], x1[33], y1[33];
    for (int i = 0; i < n; i++) scanf("%d %d %d %d", &x0[i], &y0[i], &x1[i], &y1[i]);
    double x, y;
    scanf("%lf %lf", &x, &y);
    int res = 1<<30;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (i != j && linecross(x, y, x0[i], y0[i], x0[j], y0[j], x1[j], y1[j])) count++;
        if (count < res) res = count;
    }
    if (res == (1 << 30)) res = 0;
    printf("Number of doors = %d\n", res + 1);
    return 0;
}