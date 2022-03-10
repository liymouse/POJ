#include <stdio.h>

int main()
{
int n , x , y , z , k , i;

	while (scanf("%d" , &n) == 1)
	{
		n = n % 200;
		if (n == 0) printf("1\n");
		else if (n == 1) printf("2\n");
		else if (n == 2) printf("4\n");
		else
		{
			x = 2; y = 4; k = -1;
			for (i = 3; i <= n; i ++)
			{
				if (i % 2 == 1) z = (x + y) % 2005;
				else {z = (x + y + k) % 2005; k = -k;}
				x = y; y = z;
			}
			printf("%d\n" , z);
		}
	}
	return 0;
}
