#include <stdio.h>
#include <string.h>

int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int b[40][40] , a[41][41];
int min , m , n;

void find(int x , int y)
{
int i , s , t;

	b[x][y] = 2;
	for (i = 0; i < 8; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((s >= 0) && (s < n) && (t >= 0) && (t < m) && (b[s][t] == 0)) b[s][t] = 1;
	}
	for (i = 0; i < 8; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((s >= 0) && (s < n) && (t >= 0) && (t < m) && (b[s][t] == 1) && (a[s][t] == 0)) find(s , t);
	}
}

int Num()
{
int i , j , tot;

	tot = 0;
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			if ((b[i][j] == 0) && (a[i][j] != -1)) tot ++;
	return tot;
}

int main()
{
int i , j , k , min , tot , s , t , mine , x , y , num , bb;
char ss[41];

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if ((m == 0) && (n == 0)) break;
		mine = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , ss);
			for (j = 0; j < m; j ++)
				if (ss[j] == '.') a[i][j] = 0; else
				{
					a[i][j] = -1;
					mine ++;
				}
		}
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
				if (a[i][j] != -1)
				{
					tot = 0;
					for (k = 0; k < 8; k ++)
					{
						s = i + p[k][0]; t = j + p[k][1];
						if ((s >= 0) && (s < n) && (t >= 0) && (t < m) && (a[s][t] == -1)) tot ++;
					}
					a[i][j] = tot;
				}
		min = m * n - mine - 1;
		if (min < 0) min = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
				if (a[i][j] == 0)
				{
					memset(b , 0 , sizeof(b));
					b[i][j] = 1;
					find(i , j);
					while (1)
					{
						bb = 0;
						for (x = 0; x < n; x ++)
							for (y = 0; y < m; y ++)
								if ((b[x][y] == 1) && (a[x][y] > 0))
								{
									tot = 0; num = 0;
									for (k = 0; k < 8; k ++)
									{
										s = x + p[k][0]; t = y + p[k][1];
										if ((s >= 0) && (s < n) && (t >= 0) && (t < m))
										{
											if ((a[s][t] == -1) && (b[s][t] == 1)) tot ++;
											else if (b[s][t] == 0) num ++;
										}
									}
									if (tot == a[x][y])
									{
										for (k = 0; k < 8; k ++)
										{
											s = x + p[k][0]; t = y + p[k][1];
											if ((s >= 0) && (s < n) && (t >= 0) && (t < m) && (b[s][t] == 0)) b[s][t] = 1;	
										}
										b[x][y] = 2; bb = 1;
									}
									else if (a[x][y] - tot == num)
									{
										for (k = 0; k < 8; k ++)
										{
											s = x + p[k][0]; t = y + p[k][1];
											if ((s >= 0) && (s < n) && (t >= 0) && (t < m) && (b[s][t] == 0)) b[s][t] = 1;
										}
										b[x][y] = 2; bb = 1;
									}
								}
								else if ((b[x][y] == 1) && (a[x][y] == 0)) find(x , y);
						if (bb == 0) break;
					}
					if (Num() < min) min = Num();
					if (min == 0) break;
				}
		printf("%d\n" , min);
	}
	return 0;
}