#include <stdio.h>

int main()
{
	int n , m;
	int u , d;
	
	while (scanf("%d %d" , &n , &m) == 2)
	{
		int res = 2000000000;
		for (int i = 0; i < m; i ++)
		{
			scanf("%d %d" , &u , &d);
			int x = n * d / (u + d) - 1;
			while (x <= n && x * (u + d) - n * d <= 0) x ++;
			if (x * (u + d) - n * d < res) res = x * (u + d) - n * d;
		}
		printf("%d\n" , res);
	}
	return 0;

}
