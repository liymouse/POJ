#include <stdio.h>

int main()
{
int a , b , x , y , t , i , h;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d %d %d %d" , &a , &b , &x , &y);
		printf("Problem set %d: %d / %d, base 7 digits %d through %d: " , h , a , b , x , y);
		i = 0; a = a % b;
		while (i <= y)
		{
			a *= 7;
			if (i >= x) printf("%d" , a / b);
			a %= b; i ++;
		}
		printf("\n");
	}
	return 0;
}