#include <stdio.h>
#include <string.h>

int main()
{
int f[5]; //quarter , dime , nickel , pennie , cent;
int p[4] = {25 , 10 , 5 , 1};
int a[100] , i , k , cent , j , t;
int b[100][4];

	while (scanf("%d %d %d %d %d" , &f[0] , &f[1] , &f[2] , &f[3] , &cent) == 5)
	{
		if (f[0] + f[1] + f[2] + f[3] + cent == 0) break;
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		a[0] = 1;
		for (k = 0; k < 4; k ++)
			for (i = 0; i < f[k]; i ++)
			{
				for (j = cent; j >= 0; j --)
					if (a[j] && (j + p[k] <= cent))
						if ((a[j + p[k]] == 0) || (a[j + p[k]] > a[j] + 1))
						{
							a[j+p[k]] = a[j] + 1;
							for (t = 0; t < 4; t ++) b[j+p[k]][t] = b[j][t];
							b[j+p[k]][k] = b[j][k] + 1;
						}
			}
		if (!a[cent]) printf("Cannot dispense the desired amount.\n");
		else printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n" , b[cent][0] , b[cent][1] , b[cent][2] , b[cent][3]);
	}
	return 0;
}