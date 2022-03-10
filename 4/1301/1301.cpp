#include <stdio.h>
#include <string.h>

char a[4][12][12];
int n , m;  //n rows  m columns
int ok;

void find(int x , int y)
{
int k = x % 4;
int i;

	if (a[k][x][y] == 'G')
	{
		ok = 1;
		return;
	}
	if (a[k][x][y] != 'O') return;
	for (i = -1; i <= 1; i ++)
	{
		int s = x + 1;
		int t = y + i;
		if (0 <= s && s < n && 0 <= t && t < m)
		{
			if (a[k][s][t] == 'O' || a[k][s][t] == 'G') find(s , t);
			if (ok) return;
		}
	}
}

int main()
{
int i , x , y , j , t , h , k;
char s[12][12];
int p[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};

	while (scanf("%s %d %d" , s[0] , &m , &n) == 3)
	{
		for (i = 0; i <= n; i ++)
			scanf("%s" , s[i]);
		x = 0;
		for (i = 0; i < m; i ++)
			if (s[0][i] == 'L')
			{
				y = i;
				s[0][i] = 'O';
				break;
			}
		for (t = 0; t < 4; t ++)
		{
			for (i = 0; i < n; i ++) strcpy(a[t][i] , s[i]);
			for (i = 0 ; i < n; i ++)
				for (j = 0; j < m; j ++)
					if (a[t][i][j] == 'S')
					{
						h = i + p[t][0];
						k = j + p[t][1];
						while (0 <= h && h < n && 0 <= k && k < m)
						{
							if (a[t][h][k] != 'S') a[t][h][k] = 'X';
							h += p[t][0];
							k += p[t][1];
						}
					}
		}

		ok = 0;
		find(x , y);
		if (ok) printf("FERRET\n");
		else printf("GARRET\n");
	}
	return 0;
}
