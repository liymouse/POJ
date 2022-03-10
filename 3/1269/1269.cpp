#include <stdio.h>

int main()
{
int x[5] , y[5];
int a1 , b1 , a2 , b2 , a , b;
int n , i , j;
double k1 , k2 , xx , yy;

	scanf("%d" , &n);
	printf("INTERSECTING LINES OUTPUT\n");
	for (i = 0; i < n; i ++)
	{
		for (j = 1; j <= 4; j ++) scanf("%d %d" , &x[j] , &y[j]);
		a1 = x[2] - x[1]; b1 = y[2] - y[1];
		a2 = x[4] - x[3]; b2 = y[4] - y[3];
		if (a1 * b2 == b1 * a2)
		{
			a = x[3] - x[2]; b = y[3] - y[2];
			if (a1 * b == a * b1) printf("LINE\n");
			else printf("NONE\n");
		}
		else
		{
			if (x[1] == x[2])
			{
				k2 = (y[3] - y[4]) * 1.0 / (x[3] - x[4]);
				xx = x[1]; yy = k2 * (x[1] - x[3]) + y[3];
			}
			else if (x[3] == x[4])
			{
				k1 = (y[1] - y[2]) * 1.0 / (x[1] - x[2]);
				xx = x[3]; yy = k1 * (x[3] - x[1]) + y[1];
			}
			else
			{
				k1 = (y[1] - y[2]) * 1.0 / (x[1] - x[2]);
				k2 = (y[3] - y[4]) * 1.0 / (x[3] - x[4]);
				xx = (k1 * x[1] - k2 * x[3] + y[3] - y[1]) * 1.0 / (k1 - k2);
				yy = k1 * (xx - x[1]) + y[1];
			}
			printf("POINT %.2lf %.2lf\n" , xx , yy);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}