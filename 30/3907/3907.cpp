#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;

        double x1 , y1 , x2 , y2;
        double area = 0;
        scanf("%lf %lf" , &x1 , &y1);
        double fx = x1 , fy = y1;
        for (int i = 1; i < n; i ++)
        {
            scanf("%lf %lf" , &x2 , &y2);
            area += x1 * y2 - x2 * y1;
            x1 = x2; y1 = y2;
        }
        x2 = fx; y2 = fy;
        area += x1 * y2 - x2 * y1;
        area = fabs(area) / 2;
        printf("%d\n" , (int)(area+0.5));
    }
    return 0;
}
