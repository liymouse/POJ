#include <stdio.h>
#include <math.h>

int cmp(double x , double y)
{
	if (x - y < -1e-6) return -1;
	else if (x - y > 1e-6) return 1;
		else return 0;
}

int main()
{
double xa , ya , xb , yb , xc , yc , x1 , y1 , x2 , y2 , s1 , t1 , s2 , t2;
double L , k1 , k2 , a , b , s , t , r;

	while (scanf("%lf %lf %lf %lf %lf %lf" , &xa , &ya , &xb , &yb , &xc , &yc) == 6)
	{
		s1 = (xa + xb) / 2; t1 = (ya + yb) / 2;
		a = xa - s1; b = ya - t1;
		L = sqrt(a * a + b * b);
		x1 = s1 - b / L; y1 = t1 + a / L;
		s2 = (xb + xc) / 2; t2 = (yb + yc) / 2;
		a = xb - s2; b = yb - t2;
		L = sqrt(a * a + b * b);
		x2 = s2 - b / L; y2 = t2 + a / L;
		if (cmp(x1 , s1) == 0)
		{
			k2 = (y2 - t2) / (x2 - s2);
			s = x1;
			t = k2 * (x1 - x2) + y2;
		}
		else if (cmp(x2 , s2) == 0)
		{
			k1 = (y1 - t1) / (x1 - s1);
			s = x2;
			t = k1 * (x2 - x1) + y1;
		}
		else
		{
			k1 = (y1 - t1) / (x1 - s1);
			k2 = (y2 - t2) / (x2 - s2);
			s = (y1 - y2 + k2 * x2 - k1 * x1) / (k2 - k1);
			t = k2 * (s - x2) + y2;
		}
		r = sqrt((s-xa)*(s-xa) + (t-ya)*(t-ya));
		printf("(x");
		if (cmp(s , 0) > 0) printf(" - %.3lf)^2 + (y" , s);
		else if (cmp(s , 0) < 0) printf(" + %.3lf)^2 + (y" , -s);
			else printf(")^2 + (y");
		if (cmp(t , 0) > 0) printf(" - %.3lf)^2 = " , t);
		else if (cmp(t , 0) < 0) printf(" + %.3lf)^2 = " , -t);
		printf("%.3lf^2\n" , r);
		printf("x^2 + y^2");
		if (cmp(s , 0) > 0) printf(" - %.3lfx" , 2 * s);
		else if (cmp(s , 0) < 0) printf(" + %.3lfx" , -2 * s);
		if (cmp(t , 0) > 0) printf(" - %.3lfy" , 2 * t);
		else if (cmp(t , 0) < 0) printf(" + %.3lfy" , -2 * t);
		L = s * s + t * t - r * r;
		if (cmp(L , 0) > 0) printf(" + %.3lf" , L);
		else if (cmp(L , 0) < 0) printf(" - %.3lf" , -L);
		printf(" = 0\n");
		printf("\n");
	}
	return 0;
}