#include <stdio.h>

int main()
{
int n , i;
double x1 , y1 , x2 , y2 , area , v , s , t;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 3) break;
		scanf("%lf %lf" , &x1 , &y1);
		area = 0; s = x1 ; t = y1;
		for (i = 1; i < n; i ++)
		{
			scanf("%lf %lf" , &x2 , &y2);
			area += x2 * y1 - x1 * y2;
			x1 = x2; y1 = y2;
		}
		area += s * y1 - x1 * t;
		scanf("%lf" , &v);
		printf("BAR LENGTH: %.2lf\n" , v * 2/ area);
	}
	return 0;
}