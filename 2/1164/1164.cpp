#include <stdio.h>

int n , m , a[50][50] , b[50][50] = {0} , tot , max , num;

void find(int x , int y)
{
int p[4] , i;

	for (i = 0; i < 4; i ++)
	{p[i] = a[x][y] % 2; a[x][y] /= 2;}
	b[x][y] = tot; num ++;
	if ((p[3] == 0) && (b[x+1][y] == 0)) find(x + 1 , y); //S
	if ((p[2] == 0) && (b[x][y+1] == 0)) find(x , y + 1); //E
	if ((p[1] == 0) && (b[x-1][y] == 0)) find(x - 1 , y); //N
	if ((p[0] == 0) && (b[x][y-1] == 0)) find(x , y - 1); //W
}

int main()
{
int i , j;

	scanf("%d %d" , &n , &m);
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			scanf("%d" , &a[i][j]);
	tot = 0;
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			if (b[i][j] == 0)
			{
				tot ++; num = 0;
				find(i , j);
				if (num > max) max = num;
			}
	printf("%d\n%d\n" , tot , max);
	return 0;
}