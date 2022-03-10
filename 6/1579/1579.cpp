#include <stdio.h>

int main()
{
int f[21][21][21];
int a , b , c;

	for (a = 0; a <= 20; a ++)
		for (b = 0; b <= 20; b ++)
			for (c = 0; c <= 20; c ++)
			{
				if ((a && b && c) == 0) f[a][b][c] = 1;
				else if ((a < b) && (b < c)) f[a][b][c] = f[a][b][c-1] + f[a][b-1][c-1] - f[a][b-1][c];
				else f[a][b][c] = f[a-1][b][c] + f[a-1][b-1][c] + f[a-1][b][c-1] - f[a-1][b-1][c-1];
			}
	while (scanf("%d %d %d" , &a , &b , &c) == 3)
	{
		if ((a == -1) && (b == -1) && (c == -1)) break;
		printf("w(%d, %d, %d) = " , a , b , c);
		if ((a < 0) || (b < 0) || (c < 0)) printf("1\n");
		else if ((a > 20) || (b > 20) || (c > 20)) printf("%d\n" , f[20][20][20]);
		else printf("%d\n" , f[a][b][c]);
	}
	return 0;
}