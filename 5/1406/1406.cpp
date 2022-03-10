#include <stdio.h>

int main()
{
int n , x , y , tot , max;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		x = 0; y = 0; max = 0;
		while (1)
		{
			tot = x * x * x + y * (y + 1) * (y + 2) / 6;
			if ((x == 0) && (tot > n)) break;
			x ++;
			if ((tot <= n) && (tot > max)) max = tot;
			else if (tot > n) {x = 0; y ++;}
		}
		printf("%d\n" , max);
	}
	return 0;
}