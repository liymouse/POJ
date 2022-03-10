#include <stdio.h>
#include <string.h>

char s[11][17] , a[11][17];
int n = 10, m = 15;

int find(int type , int x , int y , char c)
{
int p[4][2] = {{-1 , 0}, {1 , 0} , {0 , -1} , {0 , 1}};
int i , num;

	num = 1;
	if (type) s[x][y] = ' ';
	a[x][y] = 1;
	for (i = 0; i < 4; i ++)
	{
		int ss = x + p[i][0];
		int tt = y + p[i][1];
		if (0 <= ss && ss < n && 0 <= tt && tt <= m && s[ss][tt] == c && a[ss][tt] == 0)
			num += find(type , ss , tt , c);
	}
	return num;
}

void go()
{
int i , j , x , y , p;
int sum , tot , st;

	tot = 0; st = 0;
	while (1)
	{
		//for (i = 0; i < n; i ++) printf("%s\n" , s[i]);
		sum = 0; st ++;
		memset(a , 0 , sizeof(a));
		for (j = 0; j < m; j ++)
			for (i = n-1; i >= 0; i --)
				if (s[i][j] != ' ' && a[i][j] == 0)
				{
					p = find(0 , i , j , s[i][j]);
					if (p > sum) {sum = p; x = i; y = j;}
				}
		if (sum < 2) break;
		printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n" , st , n-x , y+1 , sum , s[x][y] , (sum-2)*(sum-2));
		tot += (sum-2)*(sum-2);
		memset(a , 0 , sizeof(a));
		find(1 , x , y , s[x][y]);
		for (i = 0; i < n; i ++) for (j = 0; j < m; j ++) a[i][j] = ' ';
		for (j = 0; j < m; j ++)
		{
			p = n-1;
			for (i = n-1; i >= 0; i --)
				if (s[i][j] != ' ') a[p --][j] = s[i][j];
		}
		p = 0;
		for (i = 0; i < n; i ++) for (j = 0; j < m; j ++) s[i][j] = ' ';
		for (j = 0; j < m; j ++)
			if (a[n-1][j] != ' ')
			{
				for (i = 0; i < n; i ++) s[i][p] = a[i][j];
				p ++;
			}
	}
	sum = 0;
	for (i = 0; i < n; i ++) for (j = 0; j < m; j ++)
		if (s[i][j] != ' ') sum ++;
	if (sum == 0) tot += 1000;
	printf("Final score: %d, with %d balls remaining.\n\n" , tot , sum);
}

int main()
{
int cas , ca , i;

	//freopen("1027.out" , "w" , stdout);
	scanf("%d" , &cas);
	for (ca = 1; ca <= cas; ca ++)
	{
		for (i = 0; i < n; i ++) scanf("%s" , s[i]);
		printf("Game %d:\n\n" , ca);
		go();
	}
	return 0;
}
