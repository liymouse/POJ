#include <stdio.h>
#include <math.h>
#include <string.h>

int a[1000001];

int gcd(int x , int y)
{
int r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	int k , tot , p , m , n , x , y , z , i;

	while (scanf("%d" , &k) == 1)
	{
		memset(a , 0 , sizeof(a));
		tot = 0;
		for (m = 1; m <= (int)sqrt((double)k); m ++)
			for (n = 1; n < m; n ++)
				if (m * m + n * n <= k && (m + n) % 2 == 1 && gcd(m , n) == 1)
				{
					x = m * m - n * n;
					y = 2 * m * n;
					z = m * m + n * n;
					//if (gcd(gcd(x , y) , gcd(y , z)) == 1)
					tot ++; i = 1; 
					while (z * i <= k)
					{
						a[x*i] = 1; a[y*i] = 1; a[z*i] = 1;
						i ++;
					}
				}
		p = 0;
		for (i = 1; i <= k; i ++) if (a[i] == 0) p ++;
		printf("%d %d\n" , tot , p);
	}
	return 0;
}
