#include <stdio.h>

#define N 1000 //sqrt(10^9)
char check[N];
int p[170] , n;
__int64 tb[1000001];
int phi[1000001];

int main()
{
int i , j , x , k;

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
	
	tb[1] = 0; phi[1] = 1;
	for (j = 2; j <= 1000000; j ++)
	{
		for (i = 0; i < n; i ++)
			if (j % p[i] == 0)
			{
				if (((j / p[i]) % p[i]) == 0) phi[j] = phi[j/p[i]] * p[i];
				else phi[j] = phi[j/p[i]] * (p[i] - 1);
				break;
			}
		if (i == n) phi[j] = j - 1;
		tb[j] = tb[j-1] + (__int64)phi[j];
	}

	while (scanf("%d" , &x) == 1)
	{
		if (x == 0) break;
		printf("%I64d\n" , tb[x]);
	}
	return 0;
}

