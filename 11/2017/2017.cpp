#include <stdio.h>

int main()
{
int n , tot , t , last , speed , i;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) return 0;
		last = 0; tot = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &speed , &t);
			tot += (t - last) * speed;
			last = t;
		}
		printf("%d miles\n" , tot);
	}
	return 0;
}