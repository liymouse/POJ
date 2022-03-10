#include <stdio.h>
#include <string.h>

char b[65537] = {0};

int gcd(int x , int y)
{
int t;

	if (x < y) {t = x; x = y; y = t;}
	while (1)
	{
		if (x % y == 0) break;
		t = y; y = x % y; x = t;
	}
	return y;
}

int main()
{
int i , k , x;
__int64 n;
int a[100];

	for (i = 2; i <= 256; i ++)
	{
		k = i * i;
		while (k <= 65536)
		{
			b[k] = 1; k += i;
		}
	}
	while (scanf("%I64d" , &n) == 1)
	{
		if (n == 0) break;
		k = 0;
		memset(a , 0 , sizeof(a));
		for (i = 2; i <= 65537; i ++)
			if (b[i] == 0)
			{
				x = 0;
				while (n % i == 0)
				{
					a[k] ++;
					n /= i;
					x = 1;
				}
				if (x) k ++;
				if ((n == 1) || (n == -1)) break;
			}
		if (k == 0) printf("1\n");
		else if (k == 1)
		{
			if (n > 0)
				printf("%d\n" , a[0]);
			else
			{
				while (a[0] % 2 == 0) a[0] /= 2;
				printf("%d\n" , a[0]);
			}
		}
		else
		{
			for (i = 1; i < k; i ++) a[i] = gcd(a[i-1] , a[i]);
			if (n > 0)
				printf("%d\n" , a[k-1]);
			else
			{
				while (a[k-1] % 2 == 0) a[k-1] /= 2;
				printf("%d\n" , a[k-1]);
			}
		}
		
	}
	return 0;
}