#include <stdio.h>
#include <string.h>

int map[510][510];
int sign[510];
int res , m;

void dfs(int x , int s)
{
int i;

	for (i = 0; i < m; i ++)
		if (map[i][x])
		{
			if (sign[i] == 0)
			{
				sign[i] = -s;
				dfs(i , -s);
				if (res == 0) return;
			}
			else if (sign[i] + sign[x] != 0) {res = 0; return;}
		}
}

inline int change(int x)
{
	if (x > 0) return 1; else return -1;
}

int main()
{
int n , i , j;
int x[510] , y[510];

	scanf("%d %d" , &n , &m);
	memset(map , 0 , sizeof(map));
	memset(sign , 0 , sizeof(sign));
	for (i = 0; i < m; i ++) scanf("%d %d" , &x[i] , &y[i]);
	res = 1;
	//构图
	for (i = 0; i < m; i ++)
		for (j = i + 1; j < m; j ++)
		{
			if (change(x[i] - x[j]) * change(x[i] - y[j]) * change(y[i] - y[j]) * change(y[i] - x[j]) < 0)
			{
				map[i][j] = 1; map[j][i] = 1;
			}
		}
	//判断是否为二分图
	for (i = 0; i < m; i ++)
	{
		if (sign[i] == 0)
		{
			sign[i] = 1;
			dfs(i , 1);
		}
		if (res == 0) break;
	}
	if (res) printf("panda is telling the truth...\n");
	else printf("the evil panda is lying again\n");
	return 0;
}