#include <stdio.h>
#include <string.h>

int a[101][10] = {0};
int y[101];

int main()
{
int i , x , n , k , res;

	for (i = 2; i <= 100; i ++)
	{
		x = 10;
		memset(y , 0 , sizeof(y));
		while (1)
		{
			if (y[x % i] == 1)
			{
				if (x == 10) break;
				a[i][x / i] ++;
				break;
			}
			a[i][x / i] ++;
			x %= i;
			y[x] = 1;
			x *= 10;
			if (x == 0) break;
		}
	}
	while (scanf("%d %d" , &n , &k) == 2)
	{
		res = 0;
		for (i = 2; i <= n; i ++) res += a[i][k];
		printf("%d\n" , res);
	}
	return 0;
}

