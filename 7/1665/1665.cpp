#include <stdio.h>
#define Pi 3.1415927

int main()
{
int h , n;
double t , d , tot;

	h = 0;
	while (scanf("%lf %d %lf" , &d , &n , &t) == 3)
	{
		if (n == 0) break;
		tot = d * Pi * n / (12 * 5280);
		h ++;
		printf("Trip #%d: %.2lf %.2lf\n" , h , tot , tot * 3600 / t);
	}
	return 0;
}