#include <stdio.h>
#include <math.h>

int main()
{
int n , x , y , tot = 0;

	scanf("%d" , &n);
	y = (int)sqrt(2 * n);
	for (x = 1; x <= y; x ++)
		if (((2 * n) % x == 0) && ((2 * n / x - x + 1) % 2 == 0)) tot ++;
	printf("%d\n" , tot);
	return 0;
}