#include <stdio.h>
#include <string.h>
#define NUM 4

int map[NUM][NUM];
int choose[NUM] , used[NUM];
int n;

int check(int x)
{
int y;

	if (used[x]) return 0;
	used[x] = 1;
	for (y = 1; y <= n; y ++)
		if (map[x][y])
			if (choose[y] == 0)
			{
				choose[y] = x;
				return 1;
			}
			else if (check(choose[y]))
			{
				choose[y] = x;
				return 1;
			}
	return 0;
}

int main()
{
int ans , i , k , x , y;

	while (scanf("%d %d" , &n , &k) == 2)
	{
		memset(map , 0 , sizeof(map));
		for (i = 0; i < k; i ++)
		{
			scanf("%d %d" , &x , &y);
			map[x][y] = 1;
		}
		ans = 0;
		for (i = 1; i <= n; i ++)
		{
			memset(used , 0 , sizeof(used));
			if (check(i)) ans ++;
		}
		printf("%d\n" , ans);
	}
	return 0;
}

