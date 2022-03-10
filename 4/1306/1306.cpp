#include <stdio.h>

int main()
{
int m , n;
double res;
int i;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if ((n || m) == 0) break;
		res = 1;
		printf("%d things taken %d at a time is " , n , m);
		if (n - m < m) m = n - m;
		for (i = 1; i <= m; i ++)
			res *= (n - m + i) * 1.0 / (m - i + 1);
		printf("%.0lf exactly.\n" , res);
	}
	return 0;
}
