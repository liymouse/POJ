#include <stdio.h>

int main()
{
int p[31];
int n , t , i , k;

	p[0] = 1;
	for (i = 1; i < 31; i ++) p[i] = p[i-1] * 2;
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 30; i >= 0; i --) if (n % p[i] == 0) break;
		k = n;
		while (i > 0) {k -= p[i-1]; i --;}
		printf("%d %d\n" , k , 2 * n - k);
	}
}