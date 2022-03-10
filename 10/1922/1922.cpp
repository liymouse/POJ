#include <stdio.h>
#include <math.h>

int main()
{
int a , t , r;
int n , i , min;

	while(scanf("%d" , &n) == 1)
	{
	    if (n == 0) break;
		min = 99999;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &a , &t);
			if (t >= 0)
			{
				r = ceil((4.5 / a) * 3600) + t;
				if (r < min) min = r;
			}
		}
		printf("%d\n" , min);
	}
	return 0;
}

