#include <stdio.h>
#include <string.h>
int w[200];
bool can[23000][50];
int main()
{
	int n, i, j, k, tot, maxw, maxn, min;
	while (scanf("%d", &n) == 1)
	{
		tot = 0;
		memset(can, 0, sizeof(can));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &w[i]);
			tot += w[i];
			can[w[i]][1] = true;
		}
		maxw = tot / 2;
		maxn = n / 2 + 1;
		for (i = 2; i <= n; i++)
			for (j = 1; j <= maxw; j++)
				for (k = 1; k <= maxn; k++)
					if (can[j][k] && j + w[i] <= maxw)
						can[j+w[i]][k+1] = true;
		for (i = maxw; i >= 1; i--)
			if (can[i][n/2])
				break;
		min = i;
		if (n % 2 == 1)
			for (i = maxw; i >= 1; i--)
			if (can[i][n/2+1])
				break;
		if (i > min) min = i;
		printf("%d %d\n", min, tot - min);
	}
	return 0;
}


