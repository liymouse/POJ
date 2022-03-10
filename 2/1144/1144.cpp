#include <stdio.h>

int father[101];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
int n , x , y , i , j , k , p , q , tot , num;
int a[101][101] , b[101][101] , check[101];
char c;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 1; i <= n; i ++) for (j = 1; j <= n; j ++) a[i][j] = 0;
		while (scanf("%d" , &x) == 1)
		{
			if (x == 0) break;
			y = 0;
			while (scanf("%c" , &c) == 1)
			{
				if (c == ' ')
				{
					if (y == 0) continue;
					else 
					{
						a[x][y] = 1; a[y][x] = 1;
						y = 0;
					}
				}
				else if (('0' <= c) && (c <= '9')) y = y * 10 + c - '0';
				else {a[x][y] = 1; a[y][x] = 1; break;}
			}
		}
		tot = 0;
		for (k = 1; k <= n; k ++)
		{
			for (i = 1; i <= n; i ++) for (j = 1; j <= n; j ++) b[i][j] = a[i][j];
			for (i = 1; i <= n; i ++) {b[i][k] = 0; b[k][i] = 0;}
			for (i = 1; i <= n; i ++) father[i] = i;
			for (i = 1; i <= n; i ++)
				for (j = i + 1; j <= n; j ++)
					if (b[i][j])
					{
						p = getfather(i); q = getfather(j);
						father[p] = q;
					}
			for (i = 1; i <= n; i ++) check[i] = 0;
			for (i = 1; i <= n; i ++) check[getfather(i)] = 1;
			num = 0;
			for (i = 1; i <= n; i ++) if (check[i]) num ++;
			if (num > 2) tot ++;
		}
		printf("%d\n" , tot);
	}
	return 0;
}
