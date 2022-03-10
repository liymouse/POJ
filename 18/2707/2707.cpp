#include <stdio.h>
#include <math.h>

int main()
{
int a , b , x , y;
double max , p;

	while (scanf("%d %d %d %d" , &a , &b , &x , &y) == 4)
	{
		if (a == 0) break;
		if (((x >= a) && (y >= b)) || ((y >= a) && (x >= b))) printf("100%%\n");
		else
		{
			max = 1;
			if (a > x) max = x * 1.0 / a;
			if ((b > y) && (y * 1.0 / b < max)) max = y * 1.0 / b;
			p = 1;
			if (a > y) p = y * 1.0 / a;
			if ((b > x) && (x * 1.0 / b < p)) p = x * 1.0 / b;
			if (p > max) max = p;
			printf("%.0lf%%\n" , floor(max * 100));
		}
	}
	return 0;
}