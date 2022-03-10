#include <stdio.h>

int main()
{
double x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 , xa , ya , xb , yb , xc , yc;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3 , &x4 , &y4) == 8)
	{
		if ((x1 == x3) && (y1 == y3))
		{
			xa = x2; ya = y2;
			xb = x1; yb = y1;
			xc = x4; yc = y4;
		}
		else if ((x1 == x4) && (y1 == y4))
		{
			xa = x2; ya = y2;
			xb = x1; yb = y1;
			xc = x3; yc = y3;
		}
		else if ((x2 == x3) && (y2 == y3))
		{
			xa = x1; ya = y1;
			xb = x2; yb = y2;
			xc = x4; yc = y4;
		}
		else
		{
			xa = x1; ya = y1;
			xb = x2; yb = y2;
			xc = x3; yc = y3;
		}
		printf("%.3lf %.3lf\n" , xa + xc - xb , ya + yc - yb);
	}
	return 0;
}