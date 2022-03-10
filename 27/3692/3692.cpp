#include <stdio.h>
#include <string.h>
bool can(int t , int a[][205] , int m , int *used , int *link)
{
int i;
	
	for (i = 0; i < m; i ++)
		if (used[i] == 0 && a[t][i] == 1)
		{
			used[i] = 1;
			if (link[i] == -1 || can(link[i] , a , m , used , link))
			{
				link[i] = t; return true;
			}
		}
	return false;
}

int maxMatch(int a[][205] , int n , int m)
{
int i , num = 0;
int used[205] , link[205];

	for (i = 0; i < m; i ++) link[i] = -1;
	for (i = 0; i < n; i ++)
	{
		memset(used , 0 , sizeof(used));
		if (can(i , a , m , used , link)) num ++;
	}
	return num;
}

int main()
{
int i , j , x , y , max;
int g , b , m;
int a[205][205];
int cas = 0;

	while (scanf("%d %d %d" , &g , &b , &m) == 3)
	{
		if (g + b + m == 0) break;
		cas ++;
		for (i = 0; i < g; i ++) for (j = 0; j < b; j ++) a[i][j] = 1;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d" , &x , &y);
			a[x-1][y-1] = 0;
		}
		max = maxMatch(a , g , b);
		max = g + b - max;
		printf("Case %d: %d\n" , cas , max);
	}
	return 0;
}
