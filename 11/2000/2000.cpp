#include <stdio.h>
#include <math.h>

int main()
{
int n , k;
__int64 tot;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) return 0;
		printf("%d " , n);
		k = (int)sqrt(2 * n);
		tot = k * (k + 1) * (2 * k + 1) / 6;
		if (n >= (1 + k) * k / 2)
			tot += (n - (1 + k) * k / 2) * (k + 1);
		else tot += (n - (1 + k) * k / 2) * k;
		printf("%I64d\n" , tot);
	}
}