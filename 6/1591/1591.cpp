#include <stdio.h>

int main()
{
int a[50] , c[20];
int n , k , num , i , j , h , x;

	h = 0;
	while (scanf("%d %d" , &n , &k) == 2)
	{
		for (i = 0; i < 20; i ++) scanf("%d" , &c[i]);
		for (i = 0; i < n; i ++) a[i] = 0;
		i = 0; num = n;
		if (n != k)
			while (1)
			{
				x = 0;
				for (j = 0; j < n; j ++)
					if (a[j] == 0)
					{
						x ++;
						if (x == c[i]) {a[j] = 1; x = 0; num --; if (num == k) break;}
					}
				if (num == k) break;
				i ++; if (i == 20) i = 0;
			}
		h ++;
		printf("Selection #%d\n" , h);
		for (i = 0; i < n; i ++) if (a[i] == 0) printf("%d " , i + 1);
		printf("\n\n");
	}
	return 0;
}