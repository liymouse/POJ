#include <stdio.h>
#include <math.h>

double max(double a , double b) {return a > b ? a : b;}

int main()
{
int n , ca;
double a[210][210];
int x[210] , y[210] , i , j , k;

	ca = 0;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++)
			scanf("%d %d" , &x[i] , &y[i]);
		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
				a[i][j] = sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		for (k = 0; k < n; k ++)
			for (i = 0; i < n; i ++)
				if (i != k)
					for (j = 0; j < n; j ++)
						if (j != i && j != k && a[i][j] > max(a[i][k] , a[k][j]))
							a[i][j] = max(a[i][k] , a[k][j]);
		ca ++;
		printf("Scenario #%d\n" , ca);
		printf("Frog Distance = %.3lf\n\n" , a[0][1]);
	}
	return 0;
}
