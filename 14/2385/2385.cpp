#include <stdio.h>

int main()
{
int t , w , i , j , k , x , y;
int num , f[1000][31][3] = {0};

	scanf("%d %d" , &t , &w);
	scanf("%d" , &num);
	if (num == 1) f[0][0][1] = 1; else f[0][1][2] = 1;
	for (i = 1; i < t; i ++)
	{
		scanf("%d" , &num);
		for (j = 0; j <= w; j ++)
		{
			x = f[i-1][j][1];
			if (j > 0) y = f[i-1][j-1][2];
			else y = x;
			if (num == 1) {x ++; y ++;}
			if (x > y) f[i][j][1] = x; else f[i][j][1] = y;
			x = f[i-1][j][2];
			if (j > 0) y = f[i-1][j-1][1];
			else y = x;
			if (num == 2) {x ++; y ++;}
			if (x > y) f[i][j][2] = x; else f[i][j][2] = y;
		}
	}
	x = 0;
	for (i = 0; i <= w; i ++) 
		for (j = 1; j <= 2; j ++)
			if (f[t-1][i][j] > x) x = f[t-1][i][j];
	printf("%d\n" , x);
	getchar(); getchar();
	return 0;
}