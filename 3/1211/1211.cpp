#include <stdio.h>

int main()
{
	int a[120];
	int n;
	int i , min , t , ok , k;

	while (scanf("%d" , &a[0]) == 1)
	{
		if (a[0] == 0) break;
		n = 1;
		while (scanf("%d" , &a[n ++]) == 1)
		{
			if (a[n-1] == 0) break;
		}
		n --;
		min = 9999;
		for (i = 0; i < n; i ++)
			if (a[i] < min) min = a[i];
		ok = 0;
		for (t = 2 * min; t <= 18000; t ++)
		{
			ok = 1;
			for (i = 0; i < n; i ++)
			{
				if (((t/ a[i]) & 1) == 1)
				{
					ok = 0; break;
				}
				else
				{
					k = t % a[i];
					if (a[i] - k <= 5) //yellow
					{
						ok = 0; break;
					}
				}
			}
			if (ok)
			{
				ok = t; break;
			}
		}
		if (!ok) printf("Signals fail to synchronise in 5 hours\n");
		else
		{
			int h , m , s;
			h = ok / 3600;
			m = (ok / 60) % 60;
			s = ok % 60;
			printf("0%d:" , h);
			if (m < 10) printf("0");
			printf("%d:" , m);
			if (s < 10) printf("0");
			printf("%d\n" , s);
		}
	}
	return 0;
}
