#include<stdio.h>

int main()
{
int n , k , i , t , j;
int a[25];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		k = 0;
		while (n)
		{
			a[k ++] = n & 1;
			n = n >> 1;
		}
		i = 0; t = 0;
		while ((i < k) && (a[i] == 0)) i ++;
		t = i + 1;
		while ((i < k) && (a[i] == 1)) i ++;
		a[i] = 1;
		if (i == k) k ++;
		for (j = i - 1; j >= i - t; j --) a[j] = 0;
		for (j = i - t - 1; j >= 0; j --) a[j] = 1;
		n = 0;
		for (i = 0; i < k; i ++)
			n += a[i] << i;
		printf("%d\n" , n);
	}
	return 0;
}
