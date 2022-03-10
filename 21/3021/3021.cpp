#include <stdio.h>
#include <string.h>

int main()
{
int c;
int m , s;
int a[40] , b[40];
int f[305][305];
int i , j , k , r2 , i2;
int min;

	scanf("%d" , &c);
	while (c --)
	{
		scanf("%d %d" , &m , &s);
		for (i = 0; i < m; i ++)
			scanf("%d %d" , &a[i] , &b[i]);
		memset(f , 0 , sizeof(f));
		min = 1000;
		f[0][0] = 1;
		r2 = s * s;
		for (i = 0; i <= s; i ++)
		{
			j = 0;  i2 = i * i;
			while (i2 + j * j <= r2)
			{
				for (k = 0; k < m; k ++)
					if ((i - a[k] >= 0) && (j - b[k] >= 0))
					{
						if (f[i-a[k]][j-b[k]] > 0)
						{
							if ((f[i][j] == 0) || (f[i-a[k]][j-b[k]] < f[i][j]))
								f[i][j] = f[i-a[k]][j-b[k]] + 1;
						}
					}
				if ((i2 + j * j == r2) && (f[i][j] < min) && (f[i][j] > 0)) min = f[i][j];
				j ++;
			}
		}
		if (min == 1000) printf("not possible\n");
		else printf("%d\n" , min - 1);
	}
	return 0;
}