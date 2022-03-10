#include <stdio.h>
#include <math.h>
typedef __int64 i64;

int main()
{
i64 m , n , i , res;
double s;

	while (scanf("%I64d %I64d" , &m , &n) == 2)
	{
		if (m == 0 && n == 0) break;
		if (m < n) {res = m; m = n; n = res;}
		s = 1;
		for (i = 1; i <= n; i ++)
			s *= (double)(m + i) / (double)i;
		if (s - (i64)s > ceil(s) - s) res = ceil(s);
		else res = (i64)s;
		printf("%I64d\n" , res);
	}
	return 0;
}
