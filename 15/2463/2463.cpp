#include <stdio.h>
#include <math.h>
#define g 9.81

int main()
{
double k , L , s , w;
double dL , v;

    while (scanf("%lf %lf %lf %lf" , &k , &L , &s , &w) != EOF)
    {
        if ((k < 1e-6) && (k > -1e-6) && (L < 1e-6) && (L > -1e-6)) return 0;
        dL = sqrt(2 *w  * g * s / k);
        if (dL - s + L < 1e-6) printf("Stuck in the air.\n");
        else
        {
            dL = s - L;
            v = sqrt((2 * w * g * s - k *dL *dL)/w);
            if (v - 10 < 1e-6) printf("James Bond survives.\n");
            else printf("Killed by the impact.\n");
        }
    }
    return 0;
}
