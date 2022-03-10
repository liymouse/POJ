#include <stdio.h>
#include <string.h>

int main()
{
int c , m , n;
double f[401][102];
int i , j;

	while (scanf("%d %d %d" , &c , &n , &m) == 3)
	{
		if (m > c) printf("0\n");
		else if (m > n) printf("0\n");
		else if ((n - m) % 2 == 1) printf("0\n");
		else
		{
			if ((n > 400) && (n % 2 == 0)) n = 400;
			else if ((n > 400) && (n % 2 == 1)) n = 399;
			memset(f , 0 , sizeof(f));
			f[0][0] = 1; f[1][1] = 1;
			for (i = 1; i <= n; i ++)
			{
				if (i % 2 == 0)
					for (j = 0; j <= c; j += 2)
					{
						if (j > i) break;
						if ((j > 0) && (j < c))
							f[i][j] = (j+1)*1.0/c * f[i-1][j+1] + (1-(j-1)*1.0/c) * f[i-1][j-1];
						else if (j == 0)
							f[i][j] = (j+1)*1.0/c * f[i-1][j+1];
						else if (j == c)
							f[i][j] = (1-(j-1)*1.0/c) * f[i-1][j-1];
					}
				else 
					for (j = 1; j <= c; j += 2)
					{
						if (j > i) break;
						if ((j > 0) && (j < c))
							f[i][j] = (j+1)*1.0/c * f[i-1][j+1] + (1-(j-1)*1.0/c) * f[i-1][j-1];
						else if (j == 0)
							f[i][j] = (j+1)*1.0/c * f[i-1][j+1];
						else if (j == c)
							f[i][j] = (1-(j-1)*1.0/c) * f[i-1][j-1];
					}
			}
			printf("%.3lf\n" , f[n][m]);
		}
	}
	return 0;
}