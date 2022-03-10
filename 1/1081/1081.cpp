#include <stdio.h>

int a[40][40];
int b[40] = {0};
int n , x , y;
int res;

void dfs(int x)
{
	if (x == n+1)
	{
		int max1 = -1, max2 = -1;
		for (int i = 1; i <= n; i ++)
		{
			int t = 0;
			for (int j = i + 1; j <= n; j ++)
				if (i != j && b[i] == b[j] && a[i][j] == 0)	t ++;
			if (b[i] == 0 && t > max1) max1 = t;
			else if (b[i] == 1 && t > max2) max2 = t;
		}
		if (max1 == -1 || max2 == -1) return;
		if (max2 > max1) max1 = max2;
		if (max1 < res) res = max1;
		return;
	}
	for (int i = 0; i < 2; i ++)
	{
		b[x] = i;
		dfs(x + 1);
		b[x] = 0;
	}
}

int main()
{
	n = 0;
	while (scanf("%d" , &x) == 1)
	{
		int m;
		scanf("%d" , &m);
		for (int i = 0; i < m; i ++)
		{
			scanf("%d" , &y);
			a[x][y] = 1;
			a[y][x] = 1;
		}
		n ++;
		
	}
	res = 100;
	dfs(1);
	printf("%d\n" , res);
	return 0;
}
