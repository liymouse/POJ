#include <stdio.h>

int main()
{
int i , n , a , b;
int maxday , maxv;
	while(scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		maxv = -1;
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d", &a, &b);
			if (a + b > maxv)
			{
				maxv = a + b;
				maxday = i;
			}
		}
		if (maxv <= 8) printf("0\n");
		else printf("%d\n", maxday);
	}
	return 0;
}