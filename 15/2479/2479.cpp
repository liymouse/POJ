//最大2子段和
//b[i][j] = max(b[i][j-1] + a[j] , b[i-1][t] + a[j])  i <= t < j
//用滚动数组
//b[i] = max(b[i-1] , c[t]) + a[i];
#include <stdio.h>
#include <string.h>

int a , b , c;
int main()
{
int n , max , i , res , t;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		scanf("%d" , &a);
		b = a; c = b; max = b; res = -100000;
		for (i = 1; i < n; i ++)
		{
			scanf("%d" , &a);
			if (max > b) b = max;
			b += a;
			if (b > res) res = b;
			if (c < 0) c = 0;
			c += a;
			if (c > max) max = c;
		}
		printf("%d\n" , res);
	}
	return 0;
}