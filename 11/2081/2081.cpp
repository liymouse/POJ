#include <stdio.h>

int a[500001];
int b[3000000] = {0};

int main()
{
int n;

	a[0] = 0; b[0] = 1;
	for (n = 1; n <= 500000; n ++)
	{
		a[n] = a[n-1] - n;
		if ((a[n] < 0) || (b[a[n]] == 1)) a[n] = a[n-1] + n;
		b[a[n]] = 1;
	}
	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) return 0;
		else printf("%d\n" , a[n]);
	}
	return 0;
}