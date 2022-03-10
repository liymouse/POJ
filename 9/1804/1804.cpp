#include <stdio.h>

int main()
{
int a[1000];
int n , t , h , i , j , tot , x;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		tot = 0;
		for (i = 0; i < n; i ++)
			for (j = 1; j < n - i; j ++)
				if (a[j-1] > a[j]) {x = a[j-1]; a[j-1] = a[j]; a[j] = x; tot ++;}
		printf("Scenario #%d:\n" , h);
		printf("%d\n\n" , tot);
	}
	return 0;
}