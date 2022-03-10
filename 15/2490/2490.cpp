#include <stdio.h>
#include <string.h>

int main()
{
int cas , ca;
int n;
int f[20000];
int a[15][15];

	
	scanf("%d" , &cas);
	for (ca = 1; ca <= cas; ca ++)
	{
		scanf("%d" , &n);
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++)
				scanf("%d" , &a[i][j]);
		for (int i = 1; i < (1 << n); i ++)
			f[i] = -1;
		f[0] = 0;
		for (int i = 0; i < (1 << n); i ++)
			if (f[i] >= 0)
			{
				for (int k = 0; k < n; k ++)
					if ((i & (1 << k)) == 0)
					{
						int t = i | (1 << k);
						int now = 0;
						for (int x = 0; x < n; x ++)
							if (i & (1 << x))
							{
								now += a[k][x];
							}
						if (f[t] == -1 || f[i] + now < f[t])
							f[t] = f[i] + now;
					}
			}
		for (int i = 0; i < n; i ++) f[(1<<n)-1] += a[i][i];
		printf("Scenario #%d:\n" , ca);
		printf("You have officially been pimped for only $%d\n" , f[(1<<n)-1]);
		printf("\n");
	}
	return 0;
}
