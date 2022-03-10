#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {int x , y;}node;

int main()
{
int a[50][50];
char s[50];
int m , n , i , j;
node x , y;
queue<node> qu;
int res;
int p[4][2] = {{0 , 1} , {0 , -1} , {-1 , 0} , {1 ,0}};

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		res = 1;
		for (i = 0; i < m; i ++)
		{
			scanf("%s" , s);
			for (j = 0; j < n; j ++)
			{
				if (s[j] == '.') a[i][j] = 0;
				else if (s[j] == '#') a[i][j] = 2;
				else {a[i][j] = 1; x.x = i; x.y = j;}
			}
		}
		qu.push(x);
		while (!qu.empty())
		{
			x = qu.front();
			qu.pop();
			for (i = 0; i < 4; i ++)
			{
				y.x = x.x + p[i][0]; y.y = x.y + p[i][1];
				if (y.x >= 0 && y.x < m && y.y >= 0 && y.y < n && a[y.x][y.y] == 0)
				{
					res ++; a[y.x][y.y] = 1;
					qu.push(y);
				}
			}
		}
		printf("%d\n" , res);
	}
	return 0;
}
