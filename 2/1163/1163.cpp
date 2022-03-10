#include <stdio.h>

int main()
{
int n , i , j , max;
int a[100] , b[100] = {0} , c[100] = {0};
int *p , *q , *s;

	scanf("%d" , &n );
	p = b; q = c;
	for (i = 0; i < n; i ++)
	{
		for (j = 0; j <= i; j ++) scanf("%d" , &a[j]);

		for (j = 0; j <= i; j ++)
			if (j == 0) p[j] = q[j] + a[j];
			else if (j == i) p[j] = q[j-1] + a[j];
			else
			{
				p[j] = q[j] + a[j];
				if (q[j-1]+a[j] > p[j]) p[j] = q[j-1]+a[j];
			}
		s = p; p = q; q = s;
	}
	max = 0;
	for (i = 0; i < n; i ++) if (q[i] > max) max = q[i];
	printf("%d\n" , max);
	return 0;
}