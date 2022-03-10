#include <stdio.h>
#include <string.h>

int main()
{
int p[5][2] = {{0 , -1} , {0 , 0} , {0 , 1} , {-1 , 0} , {1 , 0}};
int a[5][6] , b[5][6] , c[5][6];
int t , h;
int i , j , s , k , x , y , ok;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		for (i = 0; i < 5; i ++) for (j = 0; j < 6; j ++) scanf("%d" , &a[i][j]);
		
		for (i = 0; i < 64; i ++)
		{
			x = i;
			memset(c , 0 , sizeof(c));
			for (j = 0; j < 6; j ++) {c[0][j] = x % 2; x /= 2;}
			for (j = 0; j < 5; j ++) for (k = 0; k < 6; k ++) b[j][k] = a[j][k];
			for (s = 0; s < 4; s ++)
			{
				for (j = 0; j < 6; j ++)
					if (c[s][j])
						for (k = 0; k < 5; k ++)
						{
							x = s + p[k][0]; y = j + p[k][1];
							if ((0 <= x) && (x < 5) && (0 <= y) && (y < 6)) b[x][y] = !b[x][y];
						}
				for (j = 0; j < 6; j ++) if (b[s][j]) c[s+1][j] = 1;
			}
			for (j = 0; j < 6; j ++)
				if (c[s][j])
					for (k = 0; k < 5; k ++)
					{
						x = s + p[k][0]; y = j + p[k][1];
						if ((0 <= x) && (x < 5) && (0 <= y) && (y < 6)) b[x][y] = !b[x][y];
					}
			ok = 1;
			for (j = 0; j < 6; j ++) if (b[4][j]) {ok = 0; break;}
			if (ok) break;
		}
		printf("PUZZLE #%d\n" , h);
		for (i = 0; i < 5; i ++)
		{
			for (j = 0; j < 5; j ++)
				printf("%d " , c[i][j]);
			printf("%d\n" , c[i][j]);
		}
	}
	return 0;
}