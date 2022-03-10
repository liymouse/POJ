#include <stdio.h>
#include <string.h>

int a[1000][1000];

int main()
{
int x[1000] , y[1000];
int n , d , p , q , min , i , j , k;

	scanf("%d" , &k);
	while (k --)
	{
		scanf("%d %d" , &d , &n);
		memset(x , 0 , sizeof(x));
		memset(y , 0 , sizeof(y));
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &p , &q);
			p %= d; q %= d;
			if (p < 0) p += d;
			if (q < 0) q += d;
			x[p] ++; y[q] ++;
			a[p][q] ++;
		}
		min = 100001;
		for (i = 0; i < d; i ++)
			for (j = 0; j < d; j ++)
				if (x[i] + y[j] - a[i][j] < min) min = x[i] + y[j] - a[i][j];
		printf("%d\n" , min);
	}
	return 0;
}