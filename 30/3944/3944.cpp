#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int getCrossPoint(double *x , double *y , double*z , 
                  double x0 , double y0 , double z0 , double xd , double yd , double zd , 
                  double xc , double yc , double zc , double r)
{
    double b = 2 * (xd*(x0-xc) + yd*(y0-yc) + zd*(z0-zc));
    double c = (x0-xc)*(x0-xc) + (y0-yc)*(y0-yc) + (z0-zc)*(z0-zc) - r * r;
    if (b * b < 4 * c) return -1;
    else
    {
        double t0 = (-b + sqrt(b*b-4*c)) / 2.0;
        double t1 = (-b - sqrt(b*b-4*c)) / 2.0;
        double t;
        if (t0 <= 0 && t1 <= 0) t = -1;
        else if (t0 <= 0) t = t1;
        else if (t1 <= 0) t = t0;
        else t = min(t0 , t1);
        if (t <= 0) return -1;
        *x = x0 + xd * t;
        *y = y0 + yd * t;
        *z = z0 + zd * t;
    }
}

void normalize(double *x , double *y , double *z)
{
    double L = sqrt( (*x) * (*x) + (*y) * (*y) + (*z) * (*z));
    *x = (*x) / L;
    *y = (*y) / L;
    *z = (*z) / L;
}

void getReflect(double *xr , double *yr , double *zr ,
                double xin , double yin , double zin ,
                double xn , double yn , double zn)
{
    double len = fabs(xin * xn + yin * yn + zin * zn);
    xn *= 2 * len;
    yn *= 2 * len;
    zn *= 2 * len;
    *xr = xn - xin;
    *yr = yn - yin;
    *zr = zn - zin;
}

double dist(double x1 , double y1 , double z1 ,
            double x2 , double y2 , double z2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        double x[110] , y[110] , z[110] , r[110];
        double x0 = 0 , y0 = 0 , z0 = 0 , xd , yd , zd;
        scanf("%lf %lf %lf" , &xd , &yd , &zd);
        for (int i = 0; i < n; i ++) scanf("%lf %lf %lf %lf" , &x[i] , &y[i] , &z[i] , &r[i]);
        //int check[110];
        //for (int time = 0; time < 5; time ++)
        int last = -1;
        while (1)
        {
            normalize(&xd , &yd , &zd);
            double xp , yp , zp;
            int t = -1;
            double mindist = -1;
            for (int i = 0; i < n; i ++)
            if (i != last)
            {
                double xc , yc , zc; //cross point
                if (getCrossPoint(&xc , &yc , &zc , x0 , y0 , z0 , xd , yd , zd , x[i] , y[i] , z[i] , r[i]) != -1)
                {
                    double d = dist(xc , yc , zc , x0 , y0 , z0);
                    if (mindist < 0 || d < mindist)
                    {
                        mindist = d;
                        xp = xc; yp = yc; zp = zc;
                        t = i;
                    }
                }
            }
            if (t == -1)
            {
                printf("%lf %lf %lf\n" , x0 , y0 , z0);
                break;
            }
            double xr , yr , zr;
            getReflect(&xr , &yr , &zr , -xd , -yd , -zd , (xp - x[t]) / r[t], (yp -y[t]) / r[t], (zp -z[t])/r[t] );
            xd = xr; yd = yr; zd = zr;
            x0 = xp; y0 = yp; z0 = zp;
            last = t;
        }
    }
    return 0;
}
