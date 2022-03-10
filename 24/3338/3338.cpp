#include <stdio.h>
#include <string.h>

int a[50][50];
int w , h;
int p[4][2] = {{0 , -1} , {0 , 1} , {1 , 0} , {-1 , 0}};

int max(int x , int y) {return x > y ? x : y;}
int min(int x , int y) {return x < y ? x : y;}

void dfs(int x , int y)
{
int i , s , t;

	if (a[x][y] != 0) return;
	a[x][y] = 1;
	for (i = 0; i < 4; i ++)
	{
		s = x + p[i][0];
		t = y + p[i][1];
		if ((s >= 0) && (s <= 2 * w) && (t >= 0) && (t <= 2 * h))
		{
			dfs(s , t);
		}
	}
}

int main()
{
int n , i , j , x1 , y1 , x2 , y2 , t;

	while (scanf("%d %d" , &h , &w) == 2)
	{
		if ((w == 0) && (h == 0)) return 0;
		scanf("%d" , &n);
		memset(a , 0 , sizeof(a));
		for (i = 0; i <= 2 * h; i ++) {a[0][i] = 1; a[2 * w][i] = 1;}
		for (i = 0; i <= 2 * w; i ++) {a[i][0] = 1; a[i][2 * h] = 1;}
		for (t = 0; t < n; t ++)
		{
			scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);
			for (i = 2 * min(x1 , x2); i <= 2 * max(x1 , x2); i ++) {a[i][2*y1] = 1; a[i][2*y2] = 1;}
			for (j = 2 * min(y1 , y2); j <= 2 * max(y1 , y2); j ++) {a[2*x1][j] = 1; a[2*x2][j] = 1;}
		}
		t = 0;
		for (i = 0; i <= 2 * w; i ++)
			for (j = 0; j <= 2 * h; j ++)
				if (a[i][j] == 0)
				{
					t ++;
					dfs(i , j);
				}
		printf("%d\n" , t);
	}
	return 0;
}
