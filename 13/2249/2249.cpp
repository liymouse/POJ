#include <stdio.h>

int main()
{
int n , k , i;
double res;

	while (scanf("%d %d" , &n , &k) == 2)
	{
		if (n == 0) break;
		res = 1;
		if (k > n/2) k = n - k;
		for (i = 1; i <= k; i ++)
			res *= 1.0 * (n - k + i) / i;
		printf("%.0lf\n" , res);
	}
	return 0;
}