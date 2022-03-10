#include <stdio.h>

int main()
{
int i , j , a , n , last , done;

	while (scanf("%d" , &n) == 1)
	{
		if (n < 0) break;
		printf("%d coconuts, " , n);
		if (n == 0) printf("0 people and 1 monkey\n");
		else
		{
			for (i = 20; i >= 2; i --)
			{
				last = n; done = 1;
				for (j = 1; j <= i; j ++)
				{
					if ((last - 1) % i == 0)
					{
						a = (last - 1) / i;
						last = last - a - 1;
					}
					else {done = 0; break;}
				}
				if (last % i != 0) done = 0;
				if (done) {printf("%d people and 1 monkey\n" , i); break;}
			}
			if (done == 0) printf("no solution\n");
		}
	}
}