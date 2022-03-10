#include <stdio.h>
#include <math.h>

int main()
{
int n;
int x , y , z;
int a , b , c;
int min;

	while (scanf("%d" , &n) == 1)
	{
		min = 999999999;
		int k = (int)pow((double)n , 1/3.0);
		for (x = 1; x <= (int)pow(n,1/3.0)+1; x ++)
			if (n % x == 0)
			{
				for (y = x; y <= (int)sqrt((double)n / x); y ++)
					if ((n / x) % y == 0)
					{
						z = n / x / y;
						if (z < x) break;
						if (x * y + y * z + z * x < min)
						{
							min = x * y + y * z + z * x;
							a = x;
							b = y;
							c = z;
						}
					}
			}
		printf("%d %d %d\n" , a , b , c);
	}
	return 0;
}
