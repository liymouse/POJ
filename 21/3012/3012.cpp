#include <stdio.h>

int main()
{
__int64 c , n , k , m;
__int64 res , i , base;

	scanf("%I64d" , &c);
	while (c --)
	{
		scanf("%I64d %I64d %I64d" , &n , &k , &m);
		res = 1; base = 10;
		while (k)
		{
			if (k & 1) res = (res * base) % m;
			base = (base * base) % m;
			k /= 2;
		}
		res = (res + 1) % m;
		base = res; res = 1;
		while (n)
		{
			if (n & 1) res = (res * base) % m;
			base = (base * base) % m;
			n /= 2;
		}
		printf("%d\n" , res);
	}
}