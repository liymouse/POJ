#include <stdio.h>
#include <math.h>

int main()
{
int n , k , p;
double x;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		p = 1; n = n / 10 - 194;
		while (n --) p *= 2;
		n = p;
		k = 3; x = log10(2);
		while (1)
		{
			x += log10(k ++);
			if (x / log10(2) >= n) break;
		}
		printf("%d\n" , k-2);
	}
	return 0;
}