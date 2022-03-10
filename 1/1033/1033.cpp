#include <stdio.h>

int main()
{
	int k , n , m;
	int a[10100] = {0};
	int b[10100] = {0};
	while (scanf("%d %d" , &n , &k) == 2)
	{
		int t = 0;
		for (int i = 0; i < k; i ++)
		{
			scanf("%d" , &m);
			for (int j = 0; j < m; j ++)
			{
				int x;
				scanf("%d" , &x);
				t ++;
				a[t] = x;
				b[x] = t;
			}
		}
		int ans = 1;
		while (1)
		{
			while (1)
			{
				int ok = 1;
				for (int i = 1; i <= t; i ++)
					if (b[i] == 0)
					{
						printf("%d %d\n" , a[i] , i);
						b[a[i]] = 0;
						b[i] = i;
						a[i] = i;
						ok = 0;
						ans = 0;
					}
				if (ok) break;
			}
			
			int ok = 1;
			for (int i = 1; i <= t; i ++)
				if (b[i] != i)
				{
					ok = 0;
					b[n] = b[i];
					a[b[i]] = n;
					b[i] = 0;
					ans = 0;
					printf("%d %d\n" , i , n);
					break;
				}
			if (ok) break;
		}
		if (ans) printf("No optimization needed\n");
	}
	return 0;
}
