//PKU 2959
#include <stdio.h>
#include <math.h>

int main()
{
int n;
double D , d , s;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%lf %lf %lf" , &D , &d , &s);
		printf("%.d\n" , int(3.141 / asin((s + d) / (D - d))));
	}
	return 0;
}
