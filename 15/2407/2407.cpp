#include <stdio.h>

#define N 31627 //sqrt(10^9)
char check[N];
int p[3410] , n;
int main()
{
int i , k , res;

	for (i = 2; i*i < N; i ++)
		if (check[i] == 0)
		{
			k = i + i;
			while (k < N)
			{
				check[k] = 1; k += i;
			}
		}
	n = 0;
	for (i = 2; i < N; i ++) if (check[i] == 0) p[n++] = i;
	
	while (scanf("%d" , &k) == 1)
	{
		if (k == 0) break;
		if (k == 1) {printf("0\n"); continue;}
		res = k;
		for (i = 0; i < n; i ++)
			if (k % p[i] == 0)
			{
				res /= p[i];
				res *= p[i] - 1;
				while (k % p[i] == 0) k /= p[i];
			}
		if (k > 1) {res /= k; res *= k - 1;}
		printf("%d\n" , res);
	}
	return 0;
}
