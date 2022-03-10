#include <stdio.h>

int main()
{
int m , n , k , tot , max , x , t;
int a[50] , i , j , b[1001];

	t = 0;
	while (scanf("%d %d" , &m , &n) == 2)
	{
		if ((m || n) == 0) break;
		t ++;
		for (i = 0; i < n; i ++) scanf("%d"  ,&a[i]);
		for (i = 0; i < n; i ++)
			for (j = 1; j < n - i; j ++)
				if (a[j-1] < a[j]) {k = a[j-1]; a[j-1] = a[j]; a[j] = k;}
		tot = 0; max = n * m; x = 0;
		for (i = 1; i <= m * n; i ++) b[i] = 0;
		while (x < n)
		{
			while (b[max] == 1) max --;
			if (a[x] == max) {tot ++; max --; x ++;}
			else {max --; b[a[x]] = 1; x ++;}
		}
		printf("Case %d: %d\n" , t , tot);
	}
	return 0;
}