#include <stdio.h>
#include <string.h>
#define N 400
__int64 f[N][N];

int main()
{
int n , i , j , k;
__int64 res;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		res = 0;
		memset(f , 0 , sizeof(f));
		f[0][0] = 1;
		for (i = 1; i <= n / 2; i ++)
			for (j = 1; j <= i; j ++)
			{
				for (k = 1; k <= j; k ++)
					if (i - k >= 0)
						f[i][j] += f[i-k][k < (i-k) ? k : (i-k)];
			}
		for (i = 1; i <= n; i ++)
		{
			if (((n - i) & 1) == 0)
				res += f[(n-i)/2][i<(n-i)/2 ? i : (n-i)/2];
			if ((n & 1) == 0 && n >= i + i)
				res += f[n/2-i][(i<n/2-i) ? i : (n/2-i)];
		}
		printf("%d %I64d\n" , n , res);
	}
	return 0;
}
