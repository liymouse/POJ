//PKU 3006
//input a , d , n
//find the n-th prime number in the sequence like a , a + d , a + 2d , a + 3d ...
#include <stdio.h>
#include <string.h>

char prime[1000000];

void findprime()
{
int i , j , k;

	memset(prime , 0 , sizeof(prime));
	prime[1] = 1;
	for (i = 2; i <= 1000; i ++)
		if (prime[i] == 0)
		{
			k = i + i;
			while (k < 1000000)
			{
				prime[k] = 1;
				k += i;
			}
		}
}

int main()
{
int a , d , n;

	findprime();
	while (scanf("%d %d %d" , &a , &d , &n) == 3)
	{
		if (n == 0) break;
		while (n)
		{
			if (prime[a] == 0) n --;
			a += d;
		}
		printf("%d\n" , a - d);
	}
	return 0;
}
