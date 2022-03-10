#include <stdio.h>
#include <string.h>

int main()
{
int a , b , c;
int n , i , j;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		if (n % 2 == 1) printf("0\n");
		else if (n == 0) printf("1\n");
		else if (n == 2) printf("3\n");
		else
		{
			a = 1; b = 3;
			for (i = 4; i <= n; i += 2)
			{
				c = 4 * b - a;
				a = b;
				b = c;
			}
			printf("%d\n" , c);
		}
	}
	return 0;
}