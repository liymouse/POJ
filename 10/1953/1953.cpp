#include <stdio.h>
#include <string.h>

int main()
{
int t , n , h;
__int64 a[46];

	scanf("%d" , &t);
	a[1] = 2; a[2] = 3;
	for (h = 3; h <= 45; h ++)
		a[h] = a[h-1] + a[h-2];
	for (h = 1; h <= t; h ++)
	{
		scanf("%d" , &n);
		printf("Scenario #%d:\n" , h);
		printf("%I64d\n\n" , a[n]);
	}
	return 0;
}