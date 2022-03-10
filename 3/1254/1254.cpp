#include <stdio.h>
#include <math.h>
#define Pi 2 * acos(0)

int main()
{
int n , i;
int x1 , y1 , d1 , x2 , y2 , d2;
double k1 , k2 , x , y;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d %d %d" , &x1 , &y1 , &d1);
		scanf("%d %d %d" , &x2 , &y2 , &d2);
		if (d1 <= 90) d1 = 90 - d1;
		else d1 = 450 - d1;
		if (d2 <= 90) d2 = 90 - d2;
		else d2 = 450 - d2;
		if ((d1 == 90) || (d1 == 270))
		{
			k2 = tan(d2 * Pi / 180);
			x = x1;
			y = k2 * (x1 - x2) + y2;
		}
		else if ((d2 == 90) || (d2 == 270))
		{
			k1 = tan(d1 * Pi / 180);
			x = x2;
			y = k1 * (x2 - x1) + y1;
		}
		else
		{
			k1 = tan(d1 * Pi / 180);
			k2 = tan(d2 * Pi / 180);
			x = (k1 * x1 - k2 * x2 + y2 - y1) / (k1 - k2);
			y = k1 * (x - x1) + y1;
		}
		printf("%.4lf %.4lf\n" , x , y);
	}
}