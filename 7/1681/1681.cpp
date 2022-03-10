#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
int p[5][2] = {{0 , -1} , {0 , 0} , {0 , 1} , {-1 , 0} , {1 , 0}};
int a[16][16] , b[16][16] , c[16][16];
int t , h , n;
int i , j , s , k , x , y , ok , min , tot;
char str[20];

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , str);
			for (j = 0; j < n; j ++) if (str[j] == 'y') a[i][j] = 0; else a[i][j] = 1;
		}
		min = 1000;
		for (i = 0; i < pow(2 , n); i ++)
		{
			x = i;
			memset(c , 0 , sizeof(c));
			for (j = 0; j < n; j ++) {c[0][j] = x % 2; x /= 2;}
			for (j = 0; j < n; j ++) for (k = 0; k < n; k ++) b[j][k] = a[j][k];
			for (s = 0; s < n-1; s ++)
			{
				for (j = 0; j < n; j ++)
					if (c[s][j])
						for (k = 0; k < 5; k ++)
						{
							x = s + p[k][0]; y = j + p[k][1];
							if ((0 <= x) && (x < n) && (0 <= y) && (y < n)) b[x][y] = !b[x][y];
						}
				for (j = 0; j < n; j ++) if (b[s][j]) c[s+1][j] = 1;
			}
			for (j = 0; j < n; j ++)
				if (c[s][j])
					for (k = 0; k < 5; k ++)
					{
						x = s + p[k][0]; y = j + p[k][1];
						if ((0 <= x) && (x < n) && (0 <= y) && (y < n)) b[x][y] = !b[x][y];
					}
			ok = 1;
			for (j = 0; j < n; j ++) if (b[n-1][j]) {ok = 0; break;}
			if (ok)
			{
				tot = 0;
				for (j = 0; j < n; j ++) for (k = 0; k < n; k ++) tot += c[j][k];
				if (tot < min) min = tot;
			}
		}
		if (min < 1000) printf("%d\n" , min);
		else printf("inf\n");
	}
	return 0;
}
