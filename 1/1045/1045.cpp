#include <stdio.h>
#include <math.h>

int main()
{
double vs , r , c , w;
int n;

	scanf("%lf %lf %lf %d" , &vs , &r , &c , &n);
	while (n --)
	{
		scanf("%lf" , &w);
		printf("%.3lf\n" , vs/sqrt(r*r+1/(w*w*c*c))*r);
	}
	return 0;
}