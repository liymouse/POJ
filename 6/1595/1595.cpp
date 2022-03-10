#include <stdio.h>
#include <math.h>

int main()
{
int a[1001] = {0};
int i , k , n , c , num;

	for (i = 2; i <= (int)sqrt(1000); i ++)
	{
		k = i * i;
		while (k <= 1000)
		{
			a[k] = 1; k += i;
		}
	}
	while (scanf("%d %d" , &n , &c) == 2)
	{
		printf("%d %d:" , n , c);
		num = 0;
		for (i = 1; i <= n; i ++) if (a[i] == 0) num ++;
		if (num % 2 == 0) k = (num - 2 * c) / 2; else k = (num - 2 * c + 1) / 2;
		if (k < 0) 
		{
			for (i = 1; i <= n; i ++) 
				if ((a[i] == 0) && (num > 0)) {printf(" %d" , i); num --;}
				else if (num <= 0) break;
		}
		else
		{
			if (num % 2 == 0) c *= 2; else c = 2 * c - 1;
			num = 0;
			for (i = 1; i <= n; i ++) if (a[i] == 0) {num ++; if (num > k) break;}	
			while (c > 0)
			{
				if (a[i] == 0) {printf(" %d" , i); i ++; c --;}
				else while (a[i] == 1) i ++;
			}
		}
		printf("\n\n");
	}
}