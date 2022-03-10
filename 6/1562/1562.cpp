#include <stdio.h>

int p[8][2] = {{-1 , 0} , {-1 , -1} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int n , m;
char a[101][101];

void find(int x , int y)
{
int i , s , t;

	a[x][y] = '*';
	for (i = 0; i < 8; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((0 <= s) && (s < n) && (0 <= t) && (t < m) && (a[s][t] == '@')) find(s , t);
	}
}

int main()
{
int i , j , tot;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if ((n == 0) && (m == 0)) break;
		for (i = 0; i < n; i ++) scanf("%s" , a[i]);
		tot = 0;
		for (i = 0; i < n; i ++)
			for (j = 0; j < m; j ++)
				if (a[i][j] == '@') {tot ++; find(i , j);}
		printf("%d\n" , tot);
	}
	return 0;
}