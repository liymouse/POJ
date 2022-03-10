#include <stdio.h>
#include <string.h>
int main()
{
int n;
int a[150][150] = {0};
int k , x , y , i , j;
int max , res;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 1; i <= n; i ++)
			for (j = 1; j <= n; j ++)
				a[i][j] = 99999;
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &k);
			for (j = 0; j < k; j ++)
			{
				scanf("%d %d" , &x , &y);
				a[i+1][x] = y;
			}
		}
		for (k = 1; k <= n; k ++)
			for (i = 1; i <= n; i ++)
				for (j = 1; j <= n; j ++)
					if (a[i][k] + a[k][j] < a[i][j])
						a[i][j] = a[i][k] + a[k][j];
		k = 0; res = 99999;
		for (i = 1; i <= n; i ++)
		{
			max = 0;
			for (j = 1; j <= n; j ++)
				if ((i != j) && (a[i][j] > max)) max = a[i][j];
			if (max < res) {k = i; res = max;}
		}
		if (res == 99999) printf("disjoint\n");
		else printf("%d %d\n" , k , res);
	}
	return 0;
}
