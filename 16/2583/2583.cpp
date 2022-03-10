#include <stdio.h>

int main()
{
double a , b , c;
int x , y , z;

	while (scanf("%d %d %d" , &x , &y , &z) == 3)
	{
		a = (z + x) * 1.0 / 2 - y;
		b = 2 * y - (z + 3 * x) * 1.0 / 2;
		c = x;
		printf("%.0lf %.0lf %.0lf\n" , 9*a+3*b+c , 16*a+4*b+c , 25*a+5*b+c);
	}
	return 0;
}
