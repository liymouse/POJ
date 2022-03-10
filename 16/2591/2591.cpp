#include <stdio.h>

int a[10000000];

int main()
{
int t , n , x , y;

	x = 0; y = 0; a[0] = 1; t = 1;
	while (t < 10000000)
	{
		if (a[x] * 2 + 1 < a[y] * 3 + 1) a[t ++] = a[x ++] * 2 + 1;
		else if (a[x] * 2 + 1 > a[y] * 3 + 1) a[t ++] = a[y ++] * 3 + 1;
		else {a[t ++] = a[x ++] * 2 + 1; y ++;}
	}
	while (scanf("%d" , &n) == 1) printf("%d\n" , a[n-1]);
	return 0;
}
