#include <stdio.h>

int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
char a[101][101];
int n , m;

void find(int x , int y)
{
int i , s , t;

	for (i = 0; i < 8; i ++)
	{
		s = x + p[i][0]; t = y + p[i][1];
		if ((0 <= s) && (s < n) && (0 <= t) && (t < m) && (a[s][t] == 'W'))
		{
			a[s][t] = '.';
			find(s , t);
		}
	}
}

int main()
{
char c;
int i , j , tot;

	tot = 0;
	scanf("%d %d\n" , &n , &m);
	for (i = 0; i < n; i ++)
	{
		for (j = 0; j < m; j ++)
			scanf("%c" , &a[i][j]);
		a[i][m] = 0;
		scanf("%c" , &c);
	}
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			if (a[i][j] == 'W') {tot ++; find(i , j);}
	printf("%d\n" , tot);
	return 0;
}