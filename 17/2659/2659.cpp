#include <stdio.h>
#include <string.h>

int main()
{
int a[101][101];
int n , m , t , i , j , h;
int x , y , d , s , max , tot;

	while (scanf("%d %d %d" , &n , &m , &t) == 3)
	{
		for (i = 1; i <= n; i ++) for (j = 1; j <= m; j ++) a[i][j] = 1;
		max = 1;
		for (h = 0; h < t; h ++)
		{
			scanf("%d %d %d %d" , &x , &y , &d , &s);
			if (s == 0)
			{
				for (i = x - (d / 2); i <= x + (d / 2); i ++)
					for (j = y - (d / 2); j <= y + (d / 2); j ++)
						if ((i >= 1) && (i <= n) && (j >= 1) && (j <= m)) a[i][j] = 0;
			}
			else
			{
				for (i = x - (d / 2); i <= x + (d / 2); i ++)
					for (j = y - (d / 2); j <= y + (d / 2); j ++)
						if ((i >= 1) && (i <= n) && (j >= 1) && (j <= m))
						{
							a[i][j] ++;
							if (a[i][j] > max) max = a[i][j];
						}
			}	
		}
		tot = 0;
		for (i = 1; i <= n; i ++) for (j = 1; j <= m; j ++) if (a[i][j] == max) tot ++;
		printf("%d\n" , tot);
	}
	return 0;
}