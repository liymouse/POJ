#include <stdio.h>
#include <math.h>

int main()
{
double x1 , y1 , x2 , y2 , x3 , y3;
double a , b , c , R , p , s;

	while (scanf("%lf %lf %lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3) == 6)
	{
		a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		p = 0.5 * (a + b + c);
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		R = a * b * c / 4 / s;
		printf("%.2lf\n" , 2 * R * acos(-1));
	}
	return 0;
}

