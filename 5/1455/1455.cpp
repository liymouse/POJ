#include <stdio.h>

int main()
{
int n , t , x , y;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		x = y = n / 2;
		if (n % 2 == 1) x ++;
		printf("%d\n" , x * (x-1) / 2 + y * (y-1) / 2);
	}
	return 0;
}