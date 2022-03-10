#include <stdio.h>

int main()
{
int n , x , tot , a , b , max , p;

	while (scanf("%d %d" , &a , &b) == 2)
	{
		max = 0; p = 0;
		if (a > b) {x = a; a = b; b = x; p = 1;}
		for (n = a; n <= b; n ++)
		{
			x = n; tot = 1;
			while (x != 1)
			{
				if (x % 2 == 1) x = 3 * x + 1;
				else x = x / 2;
				tot ++;
			}
			if (tot > max) max = tot;
		}
		if (p == 0)	printf("%d %d %d\n" , a , b , max);
		else printf("%d %d %d\n" , b , a , max);
	}
	return 0;
}