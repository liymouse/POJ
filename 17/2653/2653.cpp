#include <stdio.h>
#include <string.h>

struct xian{double x1 , y1 , x2 , y2; int top;}a[100000];

int main()
{
int n , i , j;
double a1 , b1 , a2 , b2 , a3 , b3;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%lf %lf %lf %lf" , &a[i].x1 , &a[i].y1 , &a[i].x2 , &a[i].y2);
		}
		for (i = 0; i < n-1; i ++)
		{
			a[i].top = 0;
			for (j = i+1; j < n; j ++)
			{
				a1 = a[i].x2 - a[i].x1; b1 = a[i].y2 - a[i].y1;
				a2 = a[j].x1 - a[i].x1; b2 = a[j].y1 - a[i].y1;
				a3 = a[j].x2 - a[i].x1; b3 = a[j].y2 - a[i].y1;
				if ((a1 * b2 - a2 * b1) * (a1 * b3 - a3 * b1) < 0)
				{
					a1 = a[j].x2 - a[j].x1; b1 = a[j].y2 - a[j].y1;
					a2 = a[i].x1 - a[j].x1; b2 = a[i].y1 - a[j].y1;
					a3 = a[i].x2 - a[j].x1; b3 = a[i].y2 - a[j].y1;
					if ((a1 * b2 - a2 * b1) * (a1 * b3 - a3 * b1) < 0) a[i].top = 1;
				}
				if (a[i].top == 1) break;
			}
		}
		a[n-1].top = 0;
		printf("Top sticks:");
		for (i = 0; i < n; i ++)
			if (a[i].top == 0)
			{
				if (i < n-1) printf(" %d," , i + 1);
				else printf(" %d.\n" , i + 1);
			}
	}
	return 0;
}