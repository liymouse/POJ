#include <stdio.h>

int main()
{
int n , x[50000] , y[50000] , i , j , b , tot;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) return 0;
		for (i = 0; i < n; i ++) scanf("%d %d" , &x[i] , &y[i]);
		tot = 0;
		for (i = 0; i < n; i ++)
		{
			b = 0;
			for (j = 0; j < n; j ++)
				if ((i != j) && (x[j] >= x[i]) && (y[j] >= y[i])) {b = 1; break;}
			if (b == 0) tot ++;
		}
		printf("%d\n" , tot);
	}
	return 0;
}
