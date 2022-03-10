#include <stdio.h>

int main()
{
int t , i , a , b , j;
char x[6] , y[6] , c[6] , d[6];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s %s" , x , y);
		a = 0; b = 0;
		for (i = 0; i < 4; i ++) { c[i] = 0; d[i] = 0; }
		for (i = 0; i < 4; i ++)
			if (x[i] == y[i]) { a ++; c[i] = 1; d[i] = 1; }
		for (i = 0; i < 4; i ++)
			if (c[i] == 0)
				for (j = 0; j < 4; j ++)
					if (d[j] == 0 && x[i] == y[j]) { d[j] = 1; b ++; }
		printf("%dA%dB\n" , a , b);
	}
	return 0;
}
