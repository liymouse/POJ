//PKU 1019
#include <stdio.h>


int main()
{
int p[5] = {45 , 9000 , 1386450 , 188019000 , 2147483647};
int q[5] = {0 , 9 , 189 , 2889 , 38889};
int t , k , n , x;
	
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		k = 0;
		while (n > p[k]) n -= p[k++];
		x = q[k] + (k+1) * 1;
		while (n > x)
		{
			n -= x;
			x += k + 1;
		}
		if (n <= 9) printf("%d" , n);
		else if (n <= 189)
		{
			n -= 9;
			x = 10 + n / 2;
			if (n % 2 == 1) printf("%d" , x / 10);
			else printf("%d" , (x - 1) % 10);
		}
		else if (n <= 2889)
		{
			n -= 189;
			x = 100 + n / 3;
			if (n % 3 == 1) printf("%d" , x / 100);
			else if (n % 3 == 2) printf("%d" , (x / 10) % 10);
			else printf("%d" , (x - 1) % 10);
		}
		else if (n <= 38889)
		{
			n -= 2889;
			x = 1000 + n / 4;
			if (n % 4 == 1) printf("%d" , x / 1000);
			else if (n % 4 == 2) printf("%d" , (x / 100) % 10);
			else if (n % 4 == 3) printf("%d" , (x / 10) % 10);
			else printf("%d" , (x - 1) % 10);
		}
		else
		{
			n -= 38889;
			x = 10000 + n / 5;
			if (n % 5 == 1) printf("%d" , x / 10000);
			else if (n % 5 == 2) printf("%d" , (x / 1000) % 10);
			else if (n % 5 == 3) printf("%d" , (x / 100) % 10);
			else if (n % 5 == 4) printf("%d" , (x / 10) % 10);
			else printf("%d" , (x - 1) % 10);
		}
		printf("\n");
	}
	return 0;
}
