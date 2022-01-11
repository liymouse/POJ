#include <stdio.h>
#include <math.h>
#define PI (3.14159265358979)

double len(double x, double y)
{
    return sqrt(x*x + y*y);
}
int main()
{
    int n;
    double r;
    int ca = 1;
    while (scanf("%d %lf", &n, &r) == 2)
    {
        if (n == 0 && r == 0) break;
        int px[500], py[500];
        double res = 0.0;
        for (int i = 0; i < n; i++) scanf("%d %d", &px[i], &py[i]);
        int curx = 0, cury = 0;
        double dx = -1, dy = 0;
        while (r > 0)
        {
            double L = -1;
            double r2 = r * r;
            double dL = len(dx, dy);
            int nxti = -1;
            for (int i = 0; i < n; i++)
                if (py[i] <= 0 && (px[i] != curx || py[i] != cury))
                {
                    int a = px[i] - curx;
                    int b = py[i] - cury;
                    if (a*a + b*b < r2 && dx*b-a*dy >= 0)
                    {
                        if (nxti < 0 || a*(py[nxti] - cury) - b*(px[nxti] - curx) > 0 ||
                            (a*(py[nxti] - cury) - b*(px[nxti] - curx) == 0 && a*a + b*b > L))
                        {
                            nxti = i;
                            L = a*a + b*b;
                        }
                    }
                }
            if (nxti == -1)
            {
                if (r > -cury)
                {
                    double bx = sqrt(r2 - cury*cury);
                    double by = -cury;
                    double angle = acos((dx*bx + dy*by) / dL / r);
                    res += r * angle;
                    res *= 2;
                    break;
                }
                else //circle
                {
                    res = 2 * PI * r;
                    break;
                }
            }
            else
            {
                int ax = px[nxti] - curx;
                int ay = py[nxti] - cury;
                if (r > -cury)
                {
                    double bx = sqrt(r2 - cury*cury);
                    double by = -cury;
                    if (bx * ay - ax * by > 0 || (bx*ay-ax*by==0 && bx*ax+by*ay>0))
                    {
                        double angle = acos((dx*bx + dy*by) / dL / r);
                        res += r * angle;
                        res *= 2;
                        break;
                    }
                }
                double aL = len(ax, ay);
                double dian = dx * ax + dy * ay;
                double angle = acos(dian / (dL * aL));
                res += angle * r;
                dx = ax;
                dy = ay;
                curx = px[nxti];
                cury = py[nxti];
                r -= aL;
                if (r == 0) { res *= 2; break; }
            }
        }
        printf("Pendulum #%d\n", ca++);
        printf("Length of periodic orbit = %.2lf\n", res);
        printf("\n");
    }
    return 0;
}
