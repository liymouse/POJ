#include <stdio.h>
#include <math.h>

int cmp(double a , double b , double c , double d)
{
double x , y , k , L , z , p;

	if (a < b) {p = a; a = b; b = p;}
	if (c < d) {p = c; c = d; d = p;}
	if ((a >= c) && (b >= d)) return 1;
	else if (d > b) return 0;
		else
		{
			x = sqrt(a * a + b * b);
			y = sqrt(c * c + d * d);
			if (y <= b) return 1;
			else if (y > x) return 0;
			else
			{
				L = (b - sqrt(y * y - a * a)) / 2; k = (a - sqrt(y * y - b * b)) / 2;
				z = sqrt(L * L + k * k);
				if (d > z) return 0; else return 1;
			}
		}
}

int main()
{
double a , b , c , d , e;

	scanf("%lf %lf %lf %lf %lf" , &a , &b , &c , &d , &e);
	a *= 10; b *= 10; c *= 10; d *= 10; e *= 10;
	if ((cmp(d , e , a , b) || cmp(d , e , a , c) || cmp(d , e , b , c)) == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}