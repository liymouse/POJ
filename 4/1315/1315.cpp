#include <stdio.h>

int n , max , p;
int map[4][4];

void find(int x , int y , int tot)
{
int i , j;
	if (tot > max) max = tot;
	if (x == n) return;
	if (map[x][y] == 0)
	{
		map[x][y] = p;
		i = x-1; j = y;
		while ((i >= 0) && (map[i][j] != 1))
		{
			if (map[i][j] == 0) map[i][j] = p;
			i --;
		}
		i = x + 1; j = y;
		while ((i < n) && (map[i][j] != 1))
		{
			if (map[i][j] == 0) map[i][j] = p;
			i ++;
		}
		i = x; j = y - 1;
		while ((j >= 0) && (map[i][j] != 1))
		{
			if (map[i][j] == 0) map[i][j] = p;
			j --;
		}
		i = x; j = y + 1;
		while ((j < n) && (map[i][j] != 1))
		{
			if (map[i][j] == 0) map[i][j] = p;
			j ++;
		}
		p ++;
		y ++;
		if (y == n) {y = 0; x ++;}
		find(x , y , tot + 1);
		y --;
		if (y < 0) {y = n-1; x --;}
		p --;
		for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) if (map[i][j] == p) map[i][j] = 0;
	}
	y ++; 
	if (y == n) {y = 0; x ++;}
	find(x , y , tot);
}

int main()
{
int i , j , x , y;
char a[4][5];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%s" , a[i]);
		max = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
			{
				for (x = 0; x < n; x ++)
					for (y = 0; y < n; y ++)
						if (a[x][y] == '.') map[x][y] = 0;
						else map[x][y] = 1;
				p = 2;
				find(i , j , 0);
			}
		printf("%d\n" , max);
	}
	return 0;
}