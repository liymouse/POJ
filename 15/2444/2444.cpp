#include <stdio.h>
#include <math.h>

__int64 a[500][500];
__int64 b[500][500];

int main()
{
int n , m;
int i , j;
__int64 x , y , z , min , t;
	
	while (scanf("%d %d" , &n , &m) == 2)
	{
		if ((n || m) == 0) break;
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
			{
				scanf("%I64d" , &a[i][j]);
				if ((i > 0) && (j > 0)) b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
				else if (i > 0) b[i][j] = b[i-1][j] + a[i][j];
				else if (j > 0) b[i][j] = b[i][j-1] + a[i][j];
				else b[i][j] = a[i][j];
			}
		min = (__int64)65535 * 250000;
		for (i = 1; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				x = b[i-1][m-1];
				y = b[j-1][m-1] - x;
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
			}
		for (i = 1; i < m; i ++)
			for (j = i + 1; j < m; j ++)
			{
				x = b[n-1][i-1];
				y = b[n-1][j-1] - x;
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
			}
		for (i = 1; i < n; i ++)
			for (j = 1; j < m; j ++)
			{
				x = b[i-1][j-1];
				y = b[i-1][m-1] - x;
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
				x = b[n-1][j-1];
				y = b[i-1][m-1] - b[i-1][j-1];
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
				x = b[i-1][m-1];
				y = b[n-1][j-1] - b[i-1][j-1];
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
				x = b[i-1][j-1];
				y = b[n-1][j-1] - x;
				z = b[n-1][m-1] - x - y;
				t = (__int64)(fabs(x - y) + fabs(y - z) + fabs(z - x));
				if (t < min) min = t;
			}
		printf("%I64d\n" , min);
	}
	return 0;
}