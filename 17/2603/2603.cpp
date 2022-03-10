#include <stdio.h>

int main()
{
char b[101] = {0};
int i , k , n , j;
int a[10] = {0} , num[101] = {0};

	for (i = 2; i <= 10; i ++)
	{
		k = i * i;
		while (k <= 100)
		{
			b[k] = 1;
			k += i;
		}
	}
	for (i = 0; i < 10; i ++)
	{
		scanf("%d" , &n);
		for (j = 2; j <= 100; j ++)
		{
			if (n == 1) break;
			if (b[j] == 0) 
				while (n % j == 0) {num[j] ++; n /= j;}
		}
		if (n > 1) a[i] = n;
	}
	k = 1;
	for (i = 2; i <= 100; i ++)
		if (num[i] > 0) k = (k * (num[i] + 1)) % 10;
	while (1)
	{
		for (i = 0; i < 10; i ++) if (a[i] > 0) break;
		if (i == 10) break;
		n = 0; j = a[i];
		for (i = 0; i < 10; i ++) if (a[i] == j) {n ++; a[i] = 0;}
		k = (k * (n + 1)) % 10;
	}
	printf("%d\n" , k);
	return 0;
}
