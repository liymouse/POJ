#include <stdio.h>

int main()
{
int a , b , c , d;
int x1[1000] , x2[1000] , x3[1000] , x4[1000] , t , i;

	freopen("1543.txt" , "w" , stdout);
	t = 0;
	for (a = 2; a <= 100; a ++)
		for (b = 2; b < a; b ++)
			for (c = b; c < a; c ++)
				for (d = c; d < a; d ++)
					if (a*a*a == b*b*b + c*c*c + d*d*d)
					{
						x1[t] = a; x2[t] = b; x3[t] = c; x4[t] = d;
						t ++;
					}
	for (i = 0; i < t; i ++)
	{
		printf("%d," , x1[i]);
		if (i % 30 == 0) printf("\n");
	}
	printf("\n");
	for (i = 0; i < t; i ++)
	{
		printf("%d," , x2[i]);
		if (i % 30 == 0) printf("\n");
	}
	printf("\n");
	for (i = 0; i < t; i ++)
	{
		printf("%d," , x3[i]);
		if (i % 30 == 0) printf("\n");
	}
	printf("\n");
	for (i = 0; i < t; i ++)
	{
		printf("%d," , x4[i]);
		if (i % 30 == 0) printf("\n");
	}
	printf("\n");
	printf("%d\n" , t);
	return 0;
}