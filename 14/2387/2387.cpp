#include <stdio.h>
#include <string.h>

int a[1001][1001] , mark[1001] , dist[1001];

int main()
{
int t , n;
int i , j , x , y , w , min , k;

	scanf("%d %d" , &t , &n);
	memset(a , 0 , sizeof(a));
	for (i = 0; i < t; i ++)
	{
		scanf("%d %d %d" , &x , &y , &w);
		if (a[x][y] == 0) {a[x][y] = w; a[y][x] = w;}
		else if (w < a[x][y]) {a[x][y] = w; a[y][x] = w;}
	}
	for (i = 1; i <= n; i ++) 
	{
		mark[i] = 0; 
		if (a[1][i] > 0) dist[i] = a[1][i];
		else dist[i] = 100000;
	}
	dist[1] = 0; mark[1] = 1;
	for (i = 0; i < n; i ++)
	{
		min = 100000; k = 0;
		for (j = 1; j <= n; j ++) 
			if ((mark[j] == 0) && (dist[j] < min)) 
				{min = dist[j]; k = j;}
		if (k == 0) break;
		mark[k] = 1;
		for (j = 1; j <= n; j ++)
			if ((mark[j] == 0) && (dist[k] + a[k][j] < dist[j]) && (a[k][j] > 0))
				dist[j] = dist[k] + a[k][j];
	}
	printf("%d\n" , dist[n]);
	return 0;
}