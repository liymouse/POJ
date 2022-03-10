#include <stdio.h>
#include <math.h>

int cmp(double x , int y)
{
    if (x - y < -1e-6) return -1;
    else if (x - y > 1e-6) return 1;
    else return 0;
}

int main()
{
double x , y , c , t , L , s , k;

    while (scanf("%lf %lf %lf" , &x , &y , &c) == 3)
    {
        if (x > y) {t = x; x = y; y = t;} 
        s = 0.001; t = sqrt(x * x - c * c) - 0.001;
        while (1)
        {
            L = (s + t) / 2;
            k = c / sqrt(x*x-L*L) + c / sqrt(y*y -L*L);
            if (cmp(k , 1) < 0) s = L + 0.001;
            else if (cmp(k , 1) > 0) t = L - 0.001;
            else {printf("%.3lf\n" , L); break;}
        }
    }
    return 0;
}
