#include <stdio.h>

int main()
{
int n , i;
double x;

	printf("Cards  Overhang\n");
	while (scanf("%d" , &n) == 1)
	{
		printf("%5d  " , n);
		x = 0;
		for (i = 2; i <= n*2; i += 2)
			x += 1.0 / i;
		printf("%8.3lf\n" , x);
	}
	return 0;
}
