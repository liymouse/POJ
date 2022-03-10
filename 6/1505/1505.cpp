#include <stdio.h>
#include <string.h>

int f[505][505];

int main()
{
int cas , k , m , i , j , t , max , min;
int sum[505] , a[505] , b[505];

	scanf("%d" , &cas);
	while (cas --)
	{
		memset(sum , 0 , sizeof(sum));
		scanf("%d %d" , &m , &k);
		for (i = 0; i < m; i ++) scanf("%d" , &a[i]);
		sum[0] = a[0];
		for (i = 1; i < m; i ++) sum[i] = sum[i-1] + a[i];
		memset(f , 0 , sizeof(f));
		for (i = 0; i < m; i ++) f[i][1] = sum[i];

		for (i = 0; i < m; i ++)
			for (j = 2; j <= i+1; j ++)
			{
				min = -1;
				for (t = 1; t <= i - j + 2; t ++)
				{
					max = f[i-t][j-1] > (sum[i] - sum[i-t]) ? f[i-t][j-1] : (sum[i] - sum[i-t]);
					if (min == -1 || max <= min)
						min = max;
				}
				f[i][j] = min;
			}
		i = m - 1; j = k;
		memset(b , 0 , sizeof(b));
		j = m-1; t = m-1;
		for (i = k-2; i >= 0; i --)
		{
			while (j >= i && sum[t] - sum[j] <= f[m-1][k]) j --;
			j ++;
			if (j >= 0) {b[j] = 1; t = j;}
			else break;
		}
		for (i = 0; i < m; i ++)
		{
			printf("%d " , a[i]);
			if (b[i] == 1) printf("/ ");
		}
		printf("\n");
	}
	return 0;
}
