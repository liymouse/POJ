#include <stdio.h>

int main()
{
int i , n , k , t , tot;
int a[101];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		tot = 0;
		for (i = 1; i <= n; i ++) a[i] = 1;
		for (i = 2; i <= n; i ++)
		{
			k = i;
			while (k <= n)
			{
				if (a[k] == 0) a[k] = 1;
				else a[k] = 0;
				k += i;
			}
		}
		for (i = 1; i <= n; i ++) if (a[i] == 1) tot ++;
		printf("%d\n" , tot);
	}
}