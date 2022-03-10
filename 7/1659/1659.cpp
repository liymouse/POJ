#include <stdio.h>
#include <string.h>

int main()
{
int a[20][20] , n , f[20];
int i , j , t , max , k , b;

	freopen("1659in.txt" , "r" , stdin);
	freopen("1659out.txt" , "w" , stdout);
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &f[i]);
		memset(a , 0 , sizeof(a));
		while (1)
		{
			max = 0;
			for (i = 0; i < n; i ++) if (f[i] > max) {max = f[i]; k = i;}
			if (max == 0) break;
			b = 0;
			for (i = 0; i < n; i ++)
				if ((i != k) && (f[i] > 0) && (a[i][k] == 0))
				{
					a[i][k] = 1; a[k][i] = 1; f[i] --; f[k] --;
					b = 1;
					break;
				}
			if (b == 0) break;
		}
		if (b == 0) printf("NO\n\n");
		else
		{
			printf("YES\n");
			for (i = 0; i < n; i ++)
			{
				for (j = 0; j < n-1; j ++)
					printf("%d " , a[i][j]);
				printf("%d\n" , a[i][n-1]);
			}
			printf("\n");
		}
	}
	return 0;
}
