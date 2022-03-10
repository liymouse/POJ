#include <stdio.h>
#include <string.h>

int n , m;
int used[205] , link[205] , a[205][205];

bool can(int t)
{
int i;
	
	for (i = 0; i < m; i ++)
		if (used[i] == 0 && a[t][i] == 1)
		{
			used[i] = 1;
			if (link[i] == -1 || can(link[i]))
			{
				link[i] = t; return true;
			}
		}
	return false;
}

int maxMatch()
{
int i , num = 0;

	for (i = 0; i < m; i ++) link[i] = -1;
	for (i = 0; i < n; i ++)
	{
		memset(used , 0 , sizeof(used));
		if (can(i)) num ++;
	}
	return num;
}
int main()
{
int i , j , t , x;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &t);
			for (j = 0; j < t; j ++)
			{
				scanf("%d" , &x);
				a[i][x-1] = 1;
			}
		}
		printf("%d\n" , maxMatch());
	}
	return 0;
}
