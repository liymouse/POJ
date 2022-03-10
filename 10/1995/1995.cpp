#include <stdio.h>

int main()
{
int ca , m , n , x , y , i;
__int64 res , s , t;

	scanf("%d" , &ca);
	while (ca --)
	{
		scanf("%d %d" , &m , &n);
		res = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			s = 1; t = x;
			while (y)
			{
				if (y & 1) s = (s * t) % (__int64)m;
				y = y >> 1;
				t = (t * t) % (__int64)m;
			}
			res = (res + s) % (__int64)m;
		}
		printf("%I64d\n" , res);
	}
	return 0;
}
