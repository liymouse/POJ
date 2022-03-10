//最大2子段和
//b[i][j] = max(b[i][j-1] + a[j] , b[i-1][t] + a[j])  i <= t < j
//用滚动数组
//b[i] = max(b[i-1] , c[t]) + a[i];
#include <stdio.h>
#include <string.h>

int a[100000] , b[100000] , c[100000];
int main()
{
int n , max , i , res;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		memset(b , 0 , sizeof(b));
		memset(c , 0 , sizeof(c));
		b[0] = a[0];
		c[0] = b[0];
		max = c[0]; res = -100000;
		for (i = 1; i < n; i ++)
		{
			if (max > b[i-1]) b[i] = max; else b[i] = b[i-1];
			b[i] += a[i];
			if (b[i] > res) res = b[i];
			if (c[i-1] > 0) c[i] = c[i-1]; else c[i] = 0;
			c[i] += a[i];
			if (c[i] > max) max = c[i];
		}
		printf("%d\n" , res);
	}
	return 0;
}

