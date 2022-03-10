#include <stdio.h>

int n , m , a , b;
char s[21];
int map[20][20] , check[20][20];
int p[8][2] = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0} , {-1 , -1} , {1 , 1} , {-1 , 1} , {1 , -1}};

void find(int x , int y)
{
int s , t , i , tot;

	tot = 4; check[x][y] = 1;
	for (i = 0; i < 4; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((0 <= s) && (s < n) && (0 <= t) && (t < m) && (map[s][t] >= 0)) tot --;
	}
	map[x][y] = tot;
	for (i = 0; i < 8; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((0 <= s) && (s < n) && (0 <= t) && (t < m) && (map[s][t] >= 0) && (check[s][t] == 0)) 
			find(s , t);
	}
}

int main()
{
int i , j , tot;

	while (scanf("%d %d %d %d" , &n , &m , &a , &b) == 4)
	{
		if ((n || m || a || b) == 0) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			for (j = 0; j < m; j ++) 
			{
				if (s[j] == '.') map[i][j] = -1;
				else map[i][j] = 0;
				check[i][j] = 0;
			}
		}
		find(a - 1 , b - 1);
		tot = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
				if (map[i][j] > 0) tot += map[i][j];
		printf("%d\n" , tot);
	}
	return 0;
}
