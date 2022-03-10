#include <stdio.h>
#include <math.h>

int main()
{
	int t , cas , n , a[10010] , res;
	scanf("%d" , &t);
	while (t -- )
	{
		int s = 0 , ok;
		scanf("%d %d" , &cas , &n);
		for (int i = 0; i < n; i ++)
		{
			scanf("%d" , &a[i]);
			s += a[i];
		}
		res = s;
		for (int i = 1; i < int(sqrt((double)s)); i ++)
			if (s % i == 0)
			{
				int x = s / i;
				for (int h = 0; h < 2; h ++)
				{
					x = s / x;
					int k = 0;
					ok = x;
					for (int j = 0; j < n; j ++)
					{
						k += a[j];
						if (k > x) {ok = 0; break;}
						else if (k == x) k = 0;
					}
					if (k != 0) ok = 0;
					if (ok > 0 && ok < res)
					{
						res = ok;
						if (h == 0) {ok = -1; break;}
					}
				}
				if (ok == -1) break;
			}
		printf("%d %d\n" , cas , res);
	}
	return 0;
}
