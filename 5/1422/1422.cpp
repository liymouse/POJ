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
	int t , k , x , y;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		m = n;
		scanf("%d" , &k);
		memset(a , 0 , sizeof(a));
		memset(used , 0 , sizeof(used));
		memset(link , 0 , sizeof(link));
		for (int i = 0; i < k; i ++)
		{
			scanf("%d %d" , &x , &y);
			a[x-1][y-1] = 1;
		}
		x = maxMatch();
		printf("%d\n" , n - maxMatch());
	}
	return 0;
}
