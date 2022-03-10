#include <stdio.h>
#include <math.h>
#define sqr2 sqrt(2)
#define Pi 3.1415926535897932384626433832795

int main()
{
int n , i;
double xa , ya , xb , yb , La , Lb , L , x , costh , area , more , sinth;
double th1 , th2 , th;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		scanf("%lf %lf %lf %lf" , &xa , &ya , &xb , &yb);
		La = sqrt(xa * xa + ya * ya);
		Lb = sqrt(xb * xb + yb * yb);
		costh = (xa * xb + ya * yb) / (La * Lb);
		sinth = sqrt(1 - costh * costh);
		th = acos(costh);
		L = 0; more = 0;
		for (i = 0; i < n; i ++) {scanf("%lf" , &x); L += sqr2 * x; more += x * x / 2;}
		if ((xa == 0) || (xb == 0)) th1 = Pi / 4;
		else
		{
			if (ya / xa > yb / xb) th1 = 0.75 * Pi - atan(ya / xa);
			else th1 = 0.75 * Pi - atan(yb / xb);
		}
		th2 = Pi - th1 - th;
		x = L * sin(th1) / sinth;
		area = 0.5 * L * x * sin(th2);
		area -= more;
		printf("%.3lf\n" , area);
	}
	return 0;
}