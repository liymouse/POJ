#include <stdio.h>

int main()
{
int n , i , j;
int x[1010],y[1010],r[1010];
int a , b , c , d , e;
double mx , my;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++)
			scanf("%d %d %d" , &x[i] , &y[i] , &r[i]);
		a = 1; b = 1; c = -2 * x[0]; d = -2 * y[0];
		e = x[0] * x[0] + y[0] * y[0] - r[0] * r[0];
		for (i = 1; i < n; i ++)
		{
			if (a*x[i]*x[i]+b*y[i]*y[i]+c*x[i]+d*y[i]+e >= 0) break;
			a ++; b ++;
			c += (-2 * x[i]);
			d += (-2 * y[i]);
			e += x[i]*x[i] + y[i]*y[i] - r[i]*r[i];
		}
		if (i < n) printf("Unfeasible %d\n" , i);
		else printf("Feasible\n");
	}
	return 0;
}