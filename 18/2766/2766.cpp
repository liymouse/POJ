#include <stdio.h>
#include <string.h>

int main()
{
int p[4][2] = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
int a[52][52];
int n , r , x , y , s , t , f;
int i , team;

	scanf("%d" , &team);
	while (team --)
	{
		memset(a , 0 , sizeof(a));
		scanf("%d %d" , &n , &r);
		for (i = 0; i < r; i ++)
		{
			scanf("%d %d" , &x , &y);
			a[x][y] = 1;
		}
		scanf("%d %d" , &s , &t);
		if (s == 0) f = 1;
		else if (s == n + 1) f = 3;
			else if (t == 0) f = 0;
				else f = 2;
		x = s + p[f][0]; y = t + p[f][1];
		while ((0 < x) && (x <= n) && (0 < y) && (y <= n))
		{
			if (a[x][y])
			{
				f ++; if (f == 4) f = 0;
			}
			x += p[f][0]; y += p[f][1];
		}
		printf("%d %d\n" , x , y);
	}
	return 0;
}