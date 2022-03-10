#include <stdio.h>

int main()
{
int t , L , n , min , max , k;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &L , &n);
		min = 999999999; max = 0;
		for (int i = 0; i < n; i ++)
		{
			scanf("%d" , &k);
			if (2 * k > L) k = L - k;
			if (k > max) max = k;
			if (k < min) min = k;
		}
		printf("%d %d\n" , max , L - min);
	}
	return 0;
}
