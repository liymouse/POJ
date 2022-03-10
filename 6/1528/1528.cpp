#include <stdio.h>

int main()
{
int i , n , s , b;

	printf("PERFECTION OUTPUT\n");
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		printf("%5d  " , n);
		s = 0; b = 0;
		for (i = 1; i <= n / 2; i ++)
			if (n % i == 0)
			{
				s += i;
				if (s > n) break;
			}
		if (s == n) printf("PERFECT\n");
		else if (s < n) printf("DEFICIENT\n");
			else printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
}