#include <stdio.h>

int min[50005][17] = {0};
int max[50005][17] = {0};

int main()
{
int k[50005];
int n , q , i , a , b , j , x , y;

	scanf("%d %d" , &n , &q);
	for (i = 0; i < n; i ++) scanf("%d" , &k[i]);
	for (i = 0; i < n; i ++) {max[i][0] = i; min[i][0] = i;}
	for (j = 1; (1 << j) <= n; j ++)
		for (i = 0; i + (1 << j) - 1 < n; i ++)
		{
			if (k[max[i][j-1]] < k[max[i + (1 << (j-1))][j-1]])
				max[i][j] = max[i + (1 << (j-1))][j-1];
			else
				max[i][j] = max[i][j-1];
			if (k[min[i][j-1]] < k[min[i + (1 << (j-1))][j-1]])
				min[i][j] = min[i][j-1];
			else
				min[i][j] = min[i + (1 << (j-1))][j-1];
		}
	for (i = 0; i < q; i ++)
	{
		scanf("%d %d" , &a , &b);
		a --; b --;
		j = 0;
		while ((1 << (j+1)) < b - a + 1) j ++;
		x = k[min[a][j]] < k[min[b-(1<<j)+1][j]] ? k[min[a][j]] : k[min[b-(1<<j)+1][j]];
		y = k[max[a][j]] > k[max[b-(1<<j)+1][j]] ? k[max[a][j]] : k[max[b-(1<<j)+1][j]];
		printf("%d\n" , y - x);
	}
	return 0;
}
