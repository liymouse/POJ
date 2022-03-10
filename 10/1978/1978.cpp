#include <stdio.h>

int main()
{
int a[53] , b[53] , r , x , c , n;
int *p , *q , *o;
int i , j;

	while (scanf("%d %d" , &n , &r) == 2)
	{
		if (n == 0) break;
		for (i = 1; i <= n; i ++) a[i] = n - i + 1;
		p = a; q = b;
		for (i = 0; i < r; i ++)
		{
			scanf("%d %d" , &x , &c);
			for (j = x; j <= x + c - 1; j ++) q[j - x + 1] = p[j];
			for (j = 1; j <= x - 1; j ++) q[j + c] = p[j];
			for (j = x + c; j <= n; j ++) q[j] = p[j];
			o = p; p = q; q = o;
		}
		printf("%d\n" , p[1]);
	}
	return 0;
}