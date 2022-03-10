#include <stdio.h>
#include <string.h>

char a[4][4] , s[5] , c[4][4] , d[4][4];
int p[5][2] = {{0 , 1} , {1 , 0} , {0 , 0} , {0 , -1} , {-1 , 0}};
int tot , min;

int check(int x , char col)
{
int i , j , num , k , r , t;

	for (i = 0; i < 4; i ++) for (j = 0; j < 4; j ++) d[i][j] = c[i][j];
	num = x;
	for (i = 0; i < 3; i ++)
	{
		for (j = 0; j < 4; j ++)
			if (d[i][j] == col)
			{
				for (k = 0; k < 5; k ++)
				{
					r = i + 1 + p[k][0]; t = j + p[k][1];
					if ((r >= 0) && (r < 4) && (t >= 0) && (t < 4))
					{
						if (d[r][t] == 'w') d[r][t] = 'b'; else d[r][t] = 'w';
					}
				}
				num ++;
			}
	}
	k = 0;
	for (i = 0; i < 4; i ++) if (d[3][i] == col) {k = 1; break;}
	if (k) return -1;
	else return num;
}

int main()
{
int b[4] , i , j , k , x , r , t , n;

	for (i = 0; i < 4; i ++)
	{
		scanf("%s" , s);
		for (j = 0; j < 4; j ++) a[i][j] = s[j];
	}
	min = 20;
	for (k = 0; k < 16; k ++)
	{
		for (i = 0; i < 4; i ++) for (j = 0; j < 4; j ++) c[i][j] = a[i][j];
		x = k; i = 0;
		memset(b , 0 , sizeof(b));
		while (x > 0) {b[i ++] = x % 2; x /= 2;}
		x = 0;
		for (i = 0; i < 4; i ++)
			if (b[i])
			{
				for (j = 0; j < 5; j ++)
				{
					r = p[j][0]; t = i + p[j][1];
					if ((r >= 0) && (r < 4) && (t >= 0) && (t < 4))
					{
						if (c[r][t] == 'w') c[r][t] = 'b'; else c[r][t] = 'w';
					}
				}
				x ++;
			}
		tot = check(x , 'w');
		if ((tot >= 0) && (tot < min)) min = tot;
		tot = check(x , 'b');
		if ((tot >= 0) && (tot < min)) min = tot;
	}
	if (min == 20) printf("Impossible\n");
	else printf("%d\n" , min);
	return 0;
}