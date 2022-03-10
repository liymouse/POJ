#include <stdio.h>

int f[1000][1000] = {0};

int main()
{
int n , i , j;

	f[0][1] = 0; f[0][0] = 1;
	for (i = 1; i < 1000; i ++)
	{
		f[i][0] = f[i-1][0];
		for (j = 1; j <= f[i-1][0]; j ++) f[i][j] = f[i-1][j] * 2;
		if (i % 2 == 0) f[i][1] --;
		else f[i][1] ++;
		j = 1;
		while (f[i][j] < 0) {f[i][j] += 10; f[i][j+1] --; j ++;}
		for (j = 1; j <= f[i][0]; j ++)
			if (f[i][j] > 9)
			{
				f[i][j+1] += f[i][j] / 10; f[i][j] %= 10;
			}
		if (f[i][f[i][0] + 1] > 0)
		{
			j = f[i][0] + 1;
			while (f[i][j] > 9) {f[i][j+1] += f[i][j] / 10; f[i][j] %= 10; j ++;}
			f[i][0] = j;
		}
	}
	while (scanf("%d" , &n) == 1)
	{
		for (i = f[n-1][0]; i >= 1; i --) printf("%d" , f[n-1][i]);
		printf("\n");
	}
	return 0;
}