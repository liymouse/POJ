#include <stdio.h>

int main()
{
int p[8][2] = {{-1 , -1} , {-1 , 0} , {-1 , 1} , {0 , -1} , {0 , 1} , {1 , -1} , {1 , 0} , {1 , 1}};
int a[10][10] = {0};
char s[11][11] , t[11][11];
int i , j , n , k , x , y , tot , die;

	scanf("%d\n" , &n);
	die = 0;
	for (i = 0; i < n; i ++) scanf("%s" , s[i]);
	for (i = 0; i < n; i ++) scanf("%s" , t[i]);
	for (i = 0; i < n; i ++)
		for (j = 0; j < n; j ++)
		{
			if (s[i][j] == '*') a[i][j] = -1;
			if (t[i][j] == 'x')
			{
				if (s[i][j] == '*') die = 1;
				else
				{
					tot = 0;
					for (k = 0; k < 8; k ++)
					{
						x = i + p[k][0]; y = j + p[k][1];
						if ((0 <= x) && (x < n) && (0 <= y) && (y < n) && (s[x][y] == '*')) tot ++;
					}
					a[i][j] = tot;
				}
			}
		}
	for (i = 0; i < n; i ++)
	{
		for (j = 0; j < n; j ++)
			if ((die) && (a[i][j] == -1)) printf("*");
			else if (t[i][j] == '.') printf(".");
				else printf("%d" , a[i][j]);
		printf("\n");
	}
	return 0;
}