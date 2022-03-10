#include <stdio.h>

int main()
{
int n , t , p , i , j;
int a[14] , b[14];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) b[i] = 0;
		p = 0;
		for (i = 1; i <= n; i ++)
		{
			for (j = 0; j < i; j ++)
			{
				while (b[p]) {p ++; if (p == n) p = 0;}
				p ++; if (p == n) p = 0;
			}
			while (b[p]) {p ++; if (p == n) p = 0;}
			a[p] = i; b[p] = 1;
		}
		for (i = 0; i < n; i ++) printf("%d " , a[i]);
		printf("\n");
	}
	return 0;
}