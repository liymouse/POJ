#include <stdio.h>
#include <math.h>
#define Pi 3.14159265358

int main()
{
int t , n , h;
double R , r , angle; 

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%lf %d" , &R , &n);
		angle = 2 * Pi / double(n);
		angle = sqrt(2 - 2 * cos(angle));
		r = angle * R / (2 + angle);
		printf("Scenario #%d:\n" , h);
		printf("%.3lf\n\n" , r);
	}
	return 0;
}