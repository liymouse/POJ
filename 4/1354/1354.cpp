#include <stdio.h>
#include <string.h>

int main()
{
int n , i , j;
int a[300] , k;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 0) break;
		memset(a , 0 , sizeof(a));
		a[0] = 1; k = 0;
		for (i = 1; i < n; i ++)
		{
			for (j = 0; j <= k; j ++)
				a[j] = a[j] * i;
			for (j = 0; j <= k; j ++)
				if (a[j] >= 10000)
				{
					a[j+1] += a[j] / 10000;
					a[j] %= 10000;
				}
			if (a[k+1] > 0) k ++;
		}
		for (i = 0; i <= k; i ++)
			a[i] *= 2;
		for (i = 0; i <= k; i ++)
			if (a[i] > 9999) {a[i+1] += a[i] / 10000; a[i] %= 10000;}
		if (a[k+1] > 0) k ++;
		printf("N=%d:\n" , n);
		printf("%d" , a[k]);
		for (i = k-1; i >= 0; i --)
			if (a[i] >= 1000) printf("%d" , a[i]);
			else if (a[i] >= 100) printf("0%d" , a[i]);
				else if (a[i] >= 10) printf("00%d" , a[i]);
					else printf("000%d" , a[i]);
		printf("\n");
	}
	return 0;
}