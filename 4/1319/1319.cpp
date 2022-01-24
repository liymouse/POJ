#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    double x, y;
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        //grid
        int grid = (int)x * (int)y;
        //skew  x bottom
        int y_num = (int)((y - 1) / (sqrt(double(3.0))*0.5)) + 1;
        if (y < 1) y_num = 0;
        int x_num = (int)x;
        int skew = (x - x_num >= 0.5) ? x_num * y_num : (y_num / 2)*(2 * x_num - 1) + (y_num % 2)*x_num;
        //skew  y bottom
        y_num = (int)((x - 1) / (sqrt(double(3.0))*0.5)) + 1;
        if (x < 1) y_num = 0;
        x_num = (int)y;
        int skew2 = (y - x_num >= 0.5) ? x_num * y_num : (y_num / 2)*(2 * x_num - 1) + (y_num % 2)*x_num;
        skew = max(skew, skew2);
        if (grid >= skew) printf("%d grid\n", grid);
        else printf("%d skew\n", skew);
    }
    return 0;
}