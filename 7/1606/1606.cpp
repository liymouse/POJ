#include <stdio.h>

int main()
{
int a , b , n , t;

	while (scanf("%d %d %d" , &a , &b , &n) == 3)
	{
		if (b == n) printf("fill B\n");
		else
		{
			t = 0;
			while (t != n)
			{
				t += a;
				printf("fill A\n");
				printf("pour A B\n");
				if (t >= b)
				{
					t -= b;
					printf("empty B\n");
					printf("pour A B\n");
				}
			}
		}
		printf("success\n");
	}
	return 0;
}
