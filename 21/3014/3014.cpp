//PKU 3014
//f[i][j] : j个放在i个里面
//f[i][j] = f[i-1][j] + (if j-i >= 0)f[i][j-i]
//f[i][0] = 1;  f[i][1] = 1; f[1][i] = 1;
#include <stdio.h>
#include <string.h>

int f[2][4501];

int main()
{
int n , m , a , b;
int i , j;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		memset(f , 0 , sizeof(f));
		a = 0; b = 1;
		for (i = 0; i <= m; i ++) f[a][i] = 1;
		for (i = 2; i <= n; i ++)
		{
			for (j = 0; j <= m; j ++)
			{
				f[b][j] = f[a][j];
				if (j - i >= 0) f[b][j] += f[b][j-i];
				if (f[b][j] >= 1000000007) f[b][j] -= 1000000007;
			}
			a = 1 - a;
			b = 1 - b;
		}
		printf("%d\n" , f[a][m]);
	}
	return 0;
}