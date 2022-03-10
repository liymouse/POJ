#include <stdio.h>

int a[1000][1000] , max , m , n , bestx , besty;
int f[4][2] = {{-1 , 0} , {0 , -1} , {1 , 0} , {0 , 1}};

int find(int x , int y)
{
int i , s , t , L , best , p , q;

	if (a[x][y] == 0)
	{
		best = 0; p = x; q = y;
		a[x][y] = 1;
		for (i = 0; i < 4; i ++)
		{
			s = x + f[i][0]; t = y + f[i][1];
			if ((0 <= s) && (s < n) && (0 <= t) && (t < m))
			{
				L = find(s , t);
				if (L > best)
				{
					p = bestx; q = besty; best = L;
				}
			}
		}
		bestx = p; besty = q;
		return best + 1;
	}
	return 0;
}

int main()
{
int t , i , j , bo;
char s[1001];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &m , &n);
		for (i = 0; i < n; i ++) 
		{
			scanf("%s" , s);
			for (j = 0; j < m; j ++)
				if (s[j] == '#') a[i][j] = -1; else a[i][j] = 0;
		}
		bo = 0;
		for (i = 0; i < n; i ++)
		{
			for (j = 0; j < m; j ++) if (a[i][j] == 0) {bo = 1; break;}
			if (bo) break;
		}
		find (i , j);
		for (i = 0; i < n; i ++) for (j = 0; j < m; j ++) if (a[i][j] == 1) a[i][j] = 0;
		printf("Maximum rope length is %d.\n" , find(bestx , besty) - 1);
	}
	return 0;
}