#include <stdio.h>

int main()
{
int p[9];
int i , n , tot , k;

	p[0] = 1;
	for (i = 1; i < 9; i ++) p[i] = p[i-1] * 9;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		k = n;
		i = 0; tot = 0;
		while (k > 0)
		{
			if (k % 10 > 3) tot += ((k % 10) - 1) * p[i];
			else tot += (k % 10) * p[i];
			k /= 10; i ++;
		}
		printf("%d: %d\n" , n , tot);
	}
	return 0;
}