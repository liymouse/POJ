#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct
{
    double x , y;
}Point;

int main()
{
    Point a[10010];
    Point b[10010];
    int n;
    while (scanf("%d" , &n) == 1)
    {
        double low = 0 , high = 1e13;
        for (int i = 0; i < n; i ++)
        {
            double x , y , z;
            scanf("%lf %lf %lf" , &x , &y , &z);
            a[i].x = sqrt(x*x + y*y);
            a[i].y = z;
            if (z > low) low = z;
        }
        double rmin , rmax;
        for (int i = 0; i < 150; i ++)
        {
            double midmin = (low * 2 + high) / 3;
            double midmax = (low + high * 2) / 3;
            rmin = 0 , rmax = 0;
            for (int j = 0; j < n; j ++)
            {
                rmin = max(rmin , a[j].x * midmin / (midmin - a[j].y));
                rmax = max(rmax , a[j].x * midmax / (midmax - a[j].y));
            }
            if (rmin * rmin * midmin < rmax * rmax * midmax) high = midmax;
            else low = midmin;
        }
        double h = low;
        double r = 0;
        for (int i = 0; i < n; i ++) r = max(r , a[i].x * h / (h - a[i].y));
        printf("%.3lf %.3lf\n" , h , r);
    }
    return 0;
}
