#include <stdio.h>

int main()
{
double x , y;

	scanf("%lf" , &x);
	while (scanf("%lf" , &y) == 1)
	{
		if (y == 999) break;
		printf("%.2lf\n" , y - x);
		x = y;
	}
	printf("End of Output\n");
}
