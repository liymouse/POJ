#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int getCrossPoint(double *x , double *y , 
                  double x0 , double y0 , double xd , double yd , 
                  double xc , double yc , double r)
{
    double b = 2 * (xd*(x0-xc) + yd*(y0-yc));
    double c = (x0-xc)*(x0-xc) + (y0-yc)*(y0-yc) - r * r;
    if (b * b - 4 * c <= 1e-8) return -1;
    else
    {
        double t0 = (-b + sqrt(b*b-4*c)) / 2.0;
        double t1 = (-b - sqrt(b*b-4*c)) / 2.0;
        double t;
        if (t0 <= 1e-8 && t1 <= 1e-8) t = -1;
        else if (t0 <= 1e-8) t = t1;
        else if (t1 <= 1e-8) t = t0;
        else t = min(t0 , t1);
        if (t <= 1e-8) return -1;
        *x = x0 + xd * t;
        *y = y0 + yd * t;
    }
	return 0;
}

void normalize(double *x , double *y)
{
    double L = sqrt( (*x) * (*x) + (*y) * (*y));
    *x = (*x) / L;
    *y = (*y) / L;
}

void getReflect(double *xr , double *yr ,
                double xin , double yin ,
                double xn , double yn)
{
    double len = fabs(xin * xn + yin * yn);
    xn *= 2 * len;
    yn *= 2 * len;
    *xr = xn - xin;
    *yr = yn - yin;
}

double dist(double x1 , double y1 , double x2 , double y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    int n , ca = 1;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        double x[25] , y[25] , r[25];
        double x0 , y0 , xd , yd;
        for (int i = 0; i < n; i ++) scanf("%lf %lf %lf" , &x[i] , &y[i] , &r[i]);
        scanf("%lf %lf %lf %lf" , &x0 , &y0 , &xd , &yd);
        printf("Scene %d\n" , ca ++);
        int last = -1;
        int time = 0;
        while (time <= 10)
        {
            normalize(&xd , &yd);
            double xp , yp;
            int t = -1;
            double mindist = -1;
            for (int i = 0; i < n; i ++)
            if (i != last)
            {
                double xc , yc; //cross point
                if (getCrossPoint(&xc , &yc , x0 , y0 , xd , yd , x[i] , y[i] , r[i]) != -1)
                {
                    double d = dist(xc , yc , x0 , y0);
                    if (mindist < 0 || d < mindist)
                    {
                        mindist = d;
                        xp = xc; yp = yc;
                        t = i;
                    }
                }
            }
            if (t == -1) {printf("inf\n\n"); break;}
			if (time == 10) {printf("...\n\n"); break;}
            printf("%d " , t + 1);
            double xr , yr;
            getReflect(&xr , &yr , -xd , -yd , (xp - x[t]) / r[t], (yp -y[t]) / r[t]);
            xd = xr; yd = yr;
            x0 = xp; y0 = yp;
            last = t;
            time ++;
        }
    }
    return 0;
}
