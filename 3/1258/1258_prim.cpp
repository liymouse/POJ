#include <stdio.h>
#include <string.h>

int main()
{
int m , n;
int a[201][201] , mark[201] , pre[201] , dist[201];
int s , t , w;
int i , j , k , min , tot;

	while (scanf("%d" , &n) == 1)
	{
		for (i = 1; i <= n; i ++)
			for (j = 1; j <= n; j ++)
				scanf("%d" , &a[i][j]);
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