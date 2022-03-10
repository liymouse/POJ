#include <stdio.h>
#include <math.h>

int cmp1(double x , double y)
{
	if (x - y < -1e-6) return -1;
	else if (x - y > 1e-6) return 1;
		else return 0;
}

int cmp(double x , double y)
{
	if (x - y < -1e-1) return -1;
	else if (x - y > 1e-1) return 1;
		else return 0;
}

double dist(double x1 , double y1 , double x2 , double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int triangle(double x1 , double y1 , double x2 , double y2 , double x3 , double y3)
{
double a1 , b1 , a2 , b2;

	a1 = x1 - x2; b1 = y1 - y2;
	a2 = x1 - x3; b2 = y1 - y3;
	if (cmp1(a1 * b2 , b1 * a2) == 0) return 0;
	else return 1;
}

int main()
{
double x1 , y1 , x2 , y2 , x3 , y3;
double a , b , c;
int bian , xing;

	//freopen("1586in.txt" , "r" , stdin);
	//freopen("1586.txt" , "w" , stdout);
	while (scanf("%lf %lf %lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3) == 6)
	{
		if (triangle(x1 , y1 , x2 , y2 , x3 , y3) == 0) printf("Not a Triangle\n");
		else
		{
			a = dist(x1 , y1 , x2 , y2);
			b = dist(x2 , y2 , x3 , y3);
			c = dist(x3 , y3 , x1 , y1);
			if ((cmp(a*a + b*b , c*c) == 0) || (cmp(a*a + c*c , b*b) == 0) || (cmp(b*b + c*c , a*a) == 0))
				xing = 2;
			else if ((cmp(a*a + b*b , c*c) > 0) && (cmp(a*a + c*c , b*b) > 0) && (cmp(b*b + c*c , a*a) > 0))
					xing = 1;
				else xing = 3;
			if ((cmp(a , b) == 0) && (cmp(b , c) == 0)) bian = 3;
			else if ((cmp(a , b) == 0) || (cmp(b , c) == 0) || (cmp(a , c) == 0)) bian = 2;
				else bian = 1;
			if (bian == 1) printf("Scalene ");
			else if (bian == 2) printf("Isosceles ");
				else printf("Equilateral ");
			if (xing == 1) printf("Acute\n");
			else if (xing == 2) printf("Right\n");
				else printf("Obtuse\n");
		}
	}
	printf("End of Output\n");
	return 0;
}