#include <stdio.h>

int main()
{
int m , n;
int p[4][2] = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
char c;
int x , y , t , k;
char a[100][100] = {0};

	scanf("%d %d" , &m , &n);
	x = 0; y = 0; c = 'A'; t = 0; k = 0;
	while (t < m * n - 1)
	{
		a[x][y] = c;
		int xx = x + p[k][0];
		int yy = y + p[k][1];
		if (!(xx < 0 || xx >= m || yy < 0 || yy >= n))
		{
			if (a[xx][yy] != 0) {t --; k ++;}
			else {x = xx; y = yy; c ++; if (c > 'Z') c = 'A';}
		}
		else {t --; k ++;}
		if (k == 4) k = 0;
		t ++;
	}
	a[x][y] = c;
	for (int i = 0; i < m; i ++)
	{
		for (int j = 0; j < n; j ++)
			printf("   %c" , a[i][j]);
		printf("\n");
	}
	return 0;
}
