#include <stdio.h>

char b[409115] = {0};
int a[1024];

int main()
{
int i , n , t , k;

	a[0] = 1; n = 1; b[1] = 1; k = 1;
	for (t = 1; t <= 9; t ++)
	{
		k = k * t;
		a[n] = k; b[k] = 1;
		for (i = n+1; i <= 2 * n; i ++)
		{
			a[i] = a[i-n-1] + k; if (a[i] <= 409114) b[a[i]] = 1;
		}
		n = 2 * n + 1;
	}
	while (scanf("%d" , &n) == 1)
	{
		if (n < 0) break;
		if (n > 409114) printf("NO\n");
		else
		{
			if (b[n]) printf("YES\n"); else printf("NO\n");
		}
	}
	return 0;
}