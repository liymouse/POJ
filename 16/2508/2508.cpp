#include <stdio.h>
#include <math.h>
#define Pi 3.1415926

int cmp(double x , int y)
{
    if (x - y < -1e-6) return -1;
    else if (x - y > 1e-6) return 1;
    else return 0;
}

int main()
{
double r , h , d1 , a1 , d2 , a2 , L , th , x1 , y1 , x2 , y2 , d , t;

    while (scanf("%lf %lf %lf %lf %lf %lf" , &r , &h , &d1 , &a1 , &d2 , &a2) == 6)
    {
        if (a1 > a2) {t = a1; a1 = a2; a2 = t; t = d1; d1 = d2; d2 = t;}
        L = r * a1 * 2 * Pi / 360.0;
        th = L / sqrt(h*h + r*r);
        x1 = d1 * cos(th);
        y1 = d1 * sin(th);
        if (cmp(a2 - a1 , 180) > 0) a2 = 360 - a2;
        L = r * a2 * 2 * Pi / 360.0;
        th = L / sqrt(h*h + r*r);
        x2 = d2 * cos(th);
        y2 = d2 * sin(th);
        d = sqrt((x1 - x2) * (x1-x2) + (y1-y2) * (y1-y2));
        printf("%.2lf\n" , d);
    }
    return 0;
}
