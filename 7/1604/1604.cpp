#include <stdio.h>

int main()
{
int n , i , k;
__int64 x;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 10) printf("    ");
		else if (n < 100) printf("   ");
			else if (n < 1000) printf("  ");
				else if (n < 10000) printf(" ");
		printf("%d -> " , n);
		x = 1;
		for (i = 1; i <= n; i ++)
		{
			k = i; while (k % 10 == 0) k /= 10;			
			x *= k;
			while (x % 10 == 0) x /= 10;
			x = x % 10000000;
		}
		printf("%d\n" , x % 10);
	}
}