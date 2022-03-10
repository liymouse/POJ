#include <stdio.h>
#include <queue>
using namespace std;

int a[303][303];
typedef struct 
{
	int x , y , step;
}node;

int main()
{
int cas;
node k , k1;
int L , x1 , x2 , y1 , y2 , ok;
int p[8][2] = {{-2 , -1} , {-2 , 1} ,{-1 , -2} , {-1 , 2} , {1 , -2} , {1 , 2} , {2 , -1} , {2 , 1}};
queue<node> qu;
	
	scanf("%d" , &cas);
	while (cas --)
	{
		scanf("%d %d %d %d %d" , &L , &x1 , &y1 , &x2 , &y2);
		if (x1 == x2 && y1 == y2) { printf("0\n"); continue; }
		k.x = x1; k.y = y1; k.step = 0;
		while (!qu.empty()) qu.pop();
		qu.push(k);
		memset(a , 0 , sizeof(a));
		a[x1][y1] = 1; ok = 0;
		while (!qu.empty())
		{
			k = qu.front();
			qu.pop();
			for (int i = 0; i < 8; i ++)
			{
				int x = k.x + p[i][0];
				int y = k.y + p[i][1];
				if (x == x2 && y == y2) {ok = 1; break;}
				if (0 <= x && x < L && 0 <= y && y < L && a[x][y] == 0)
				{
					a[x][y] = 1;
					k1.x = x; k1.y = y; k1.step = k.step + 1;
					qu.push(k1);
				}
			}
			if (ok) break;
		}
		printf("%d\n" , k.step + 1);
	}
	return 0;
}