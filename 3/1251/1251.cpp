#include <stdio.h>
#include <string.h>

int main()
{
int a[27][27] , mark[27] , pre[27] , dist[27];
int n , i , j , k , d , x , y , tot , min;
char s[3];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n-1; i ++)
		{
			scanf("%s %d" , s , &k);
			x = s[0] - 'A' + 1;
			for (j = 0; j < k; j ++)
			{
				scanf("%s %d" , s , &d);
				y = s[0] - 'A' + 1;
				a[x][y] = d; a[y][x] = d;
			}
		}
		memset(mark , 0 , sizeof(mark));
		memset(pre , 0 , sizeof(pre));
		memset(dist , 9999 , sizeof(dist));
		dist[1] = 0;
		for (i = 1; i <= n; i ++)
		{
			min = 9999; k = 0;
			for (j = 1; j <= n; j ++) 
				if ((mark[j] == 0) && (dist[j] < min)) {min = dist[j]; k = j;}
			if (k == 0) break;
			mark[k] = 1;
			for (j = 1; j <= n; j ++)
				if ((mark[j] == 0) && (a[k][j] < dist[j]) && (a[k][j] > 0))
				{
					dist[j] = a[k][j];
					pre[j] = k;
				}
		}
		tot = 0;
		for (i = 1; i <= n; i ++) tot += dist[i];
		printf("%d\n" , tot);
	}
	return 0;
}