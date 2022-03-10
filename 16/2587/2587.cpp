#include <stdio.h>
#include <math.h>
#define Pi 3.1415926535

int main()
{
int n , k , i , j;
double x[1000] , y[1000] , a[1000] , b[1000] , c[1000] , min , max , s , t , re , L[1000];

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%lf %lf" , &x[i] , &y[i]);
		s = 90 - x[i];
		if (y[i] < 0) t = y[i] + 360; else t = y[i];
		s = s * Pi / 180;
		t = t * Pi / 180;
		a[i] = sin(s) * cos(t);
		b[i] = sin(s) * sin(t);
		c[i] = cos(s);
		L[i] = sqrt(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
	}
	max = -1000;
	for (i = 0; i < n; i ++)
	{
		min = 1000;
		for (j = 0; j < n; j ++)
		{
			re = a[i]*a[j]+b[i]*b[j]+c[i]*c[j] / (L[i]*L[j]);
			if (re < min) min = re;
		}
		if (min > max) {max = min; k = i;}
	}
	printf("%.2lf %.2lf\n" , x[k] , y[k]);
	return 0;
}
