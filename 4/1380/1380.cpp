#include <stdio.h>
#include <math.h>

#define YES "Escape is possible.\n"
#define NO "Box cannot be dropped.\n"

int main()
{
int t;
double a , b , c , d , p;
double x , y , k , L , z;

	scanf("%d" , &t);
	while (t -- )
	{
		scanf("%lf %lf %lf %lf" , &a , &b , &c , &d);
		if (a < b) {p = a; a = b; b = p;}
		if (c < d) {p = c; c = d; d = p;}
		if ((a > c) && (b > d)) printf(YES);
		else if (d >= b) printf(NO);
		else
		{
			x = sqrt(a * a + b * b);
			y = sqrt(c * c + d * d);
			if (y < b) printf(YES);
			else if (y > x) printf(NO);
			else
			{
				L = (b - sqrt(y * y - a * a)) / 2; k = (a - sqrt(y * y - b * b)) / 2;
				z = sqrt(L * L + k * k);
				if (d >= z) printf(NO); else printf(YES);
			}
		}
	}
	return 0;
}