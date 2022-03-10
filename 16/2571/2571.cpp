#include <stdio.h>
#include <math.h>
#define R 6378
#define Pi 3.141592653589

double a , b , c;

double Lo(double x , double y)
{
double a1 , b1 , c1 , k;

	x = x * Pi / 180;
	y = y * Pi / 180;
	a1 = R * sin(x) * cos(y);
	b1 = R * sin(x) * sin(y);
	c1 = R * cos(x);
	k = (a * a1 + b * b1 + c * c1) / (sqrt(a*a+b*b+c*c) * sqrt(a1*a1+b1*b1+c1*c1));
	return R * acos(k);
}

int cmp(double x , double y)
{
	if (x - y < -1e-6) return -1;
	else if (x - y > 1e-6) return 1;
	else return 0;
}

int main()
{
int n , i , num;
double x , y , h , L , r , s , t , d;
char name[100];

	num = 0;
	while (scanf("%d %lf %lf %lf" , &n , &x , &y , &h) == 4)
	{
		if (n == 0) return 0;
		num ++;
		printf("Test case %d:\n" , num);
		x = 90 - x;
		if (y < 0) y = 360 + y;
		x = x * Pi / 180;
		y = y * Pi / 180;
		a = R * sin(x) * cos(y);
		b = R * sin(x) * sin(y);
		c = R * cos(x);
		r = R * sqrt((R + h) * (R + h) - R * R) / (R + h);
		L = asin(r / R) * R;
		for (i = 0; i < n; i ++)
		{
			scanf("%s %lf %lf" , name , &s , &t);
			s = 90 - s;
			if (t < 0) t += 360;
			d = Lo(s , t);
			if (cmp(d , L) <= 0) printf("%s\n" , name);
		}
		printf("\n");
	}
	return 0;
}
