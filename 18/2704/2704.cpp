#include <stdio.h>
#include <string.h>

int main()
{
int n , a[34][34];
__int64 f[34][34];
char s[40];
int i , j , k;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			for (j = 0; j < n; j ++) a[i][j] = s[j] - '0';
		}
		memset(f , 0 , sizeof(f));
		f[0][0] = 1;
		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
			{
				for (k = 0; k < i; k ++)
					if (a[k][j] == i - k) f[i][j] += f[k][j];
				for (k = 0; k < j; k ++)
					if (a[i][k] == j - k) f[i][j] += f[i][k];
			}
		printf("%I64d\n" , f[n-1][n-1]);
	}
	return 0;
}