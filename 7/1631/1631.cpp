#include <stdio.h>

int main()
{
int f[40001];
int t , n , i , k , L , x , y , z;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		L = 0;
		for (i = 0; i < n; i ++) f[i] = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &k);
			if (k > f[L])
			{
				L ++; f[L] = k;
			}
			else
			{
				x = 1; y = L;
				while (x < y)
				{
					z = (x + y) / 2;
					if (k > f[z]) x = z + 1;
					else y = z - 1;
				}
				if ((f[(x + y) / 2 - 1] < k) && (f[(x + y) / 2] > k)) f[(x+y)/2] = k;
				else if ((f[(x + y) / 2] < k) && (f[(x + y) / 2 + 1] > k)) f[(x+y)/2+1] = k;
			}
		}
		printf("%d\n" , L);
	}
	return 0;
}