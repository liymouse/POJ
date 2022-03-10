#include <stdio.h>
#include <string.h>

int main()
{
int p[4][2] = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
int n , m , i , j , k , x , y , tot , tot1;
int a[11][11] , step[11][11];
char s[11];

	while (scanf("%d %d %d" , &n , &m , &k) == 3)
	{
		if ((n || m || k) == 0) break;
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			for (j = 0; j < m; j ++)
				if (s[j] == 'N') a[i][j] = 0;
				else if (s[j] == 'S') a[i][j] = 1;
					else if (s[j] == 'W') a[i][j] = 2;
						else a[i][j] = 3;
		}
		memset(step , 0 , sizeof(step));
		x = 0; y = k-1; tot = 1; tot1 = 0; step[x][y] = 1;
		while (1)
		{
			tot ++; i = x; j = y;
			x = x + p[a[i][j]][0]; y = y + p[a[i][j]][1];
			if ((x < 0) || (x >= n) || (y < 0) || (y >= m)) break;
			if (step[x][y] == 0) step[x][y] = tot;
			else
			{
				tot1 = tot - step[x][y];
				tot = step[x][y] - 1;
				break;
			}
		}
		if (tot1 == 0) printf("%d step(s) to exit\n" , tot - 1);
		else printf("%d step(s) before a loop of %d step(s)\n" , tot , tot1);
	}
	return 0;
}
