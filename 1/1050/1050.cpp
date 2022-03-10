#include <stdio.h>

int main()
{
int a[100][100] , b[100][100] , i , j , max , n , s , t , k;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) scanf("%d" , &a[i][j]);
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
		{
			if ((i == 0) && (j == 0)) b[i][j] = a[i][j];
			else if (i == 0) b[i][j] = b[i][j-1] + a[i][j];
			else if (j == 0) b[i][j] = b[i-1][j] + a[i][j];
			else b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
		}
	max = -99999999;
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
			for (s = 0; s <= i; s ++)
				for (t = 0; t <= j; t ++)
				{
					if ((s == 0) && (t == 0)) k = b[i][j];
					else if (s == 0) k = b[i][j] - b[i][t-1];
					else if (t == 0) k = b[i][j] - b[s-1][j];
					else k = b[i][j] - b[i][t-1] - b[s-1][j] + b[s-1][t-1];
					if (k > max) max = k;
				}
	printf("%d\n" , max);
	return 0;
}