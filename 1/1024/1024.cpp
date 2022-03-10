#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

typedef struct
{
	int x , y , step;
}P;
int p[4][2] = {{-1, 0} , {0 , 1} , {1, 0} , {0 , -1}};

int start[105][105] = {0};
int end[105][105] = {0};
int visit[105][105] = {0};
int wallnum;
int x1[10000] , y1[10000] , x2[10000] , y2[10000];
int wall[105][105] = {0};
int w , h;
void bfs(int startx , int starty , int a[105][105])
{
	P s;
	s.x = startx;
	s.y = starty;
	s.step = 0;
	a[startx][starty] = 0;
	queue<P> q;
	q.push(s);
	while (!q.empty())
	{
		s = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++)
			if ((wall[s.x][s.y] & (1<<i)) == 0)
			{
				int xx = s.x + p[i][0];
				int yy = s.y + p[i][1];
				if (0 <= xx && xx < w && 0 <= yy && yy < h)
				{
					if ((xx != startx || yy != starty) && a[xx][yy] == 0)
					{
						P t;
						t.x = xx;
						t.y = yy;
						t.step = s.step + 1;
						a[xx][yy] = t.step;
						q.push(t);
					}
				}
			}
	}
}
int main()
{
	int ca;
	scanf("%d" , &ca);
	//freopen("output.txt" , "w" , stdout);
	while (ca --)
	{
		scanf("%d %d" , &w , &h);
		char dir[10000];
		scanf("%s" , dir);
		scanf("%d" , &wallnum);
		memset(wall , 0 , sizeof(wall));
		for (int i = 0; i < wallnum; i ++)
		{
			scanf("%d %d %d %d" , &x1[i] , &y1[i] , &x2[i] , &y2[i]);
			if (x1[i] == x2[i])
			{
				if (y1[i] < y2[i])
				{
					wall[x1[i]][y1[i]] |= 2;
					wall[x2[i]][y2[i]] |= 8;
				}
				else
				{
					wall[x1[i]][y1[i]] |= 8;
					wall[x2[i]][y2[i]] |= 2;
				}
			}
			else
			{
				if (x1[i] < x2[i])
				{
					wall[x1[i]][y1[i]] |= 4;
					wall[x2[i]][y2[i]] |= 1;
				}
				else
				{
					wall[x1[i]][y1[i]] |= 1;
					wall[x2[i]][y2[i]] |= 4;
				}
			}
		}

		int res = 1;
		/* trace */
		memset(visit , 0 , sizeof(visit));
		int x = 0 , y = 0;
		int Len = strlen(dir);
		visit[0][0] = 1;
		for (int i = 0; i < Len; i ++)
		{
			int f = 0;
			if (dir[i] == 'L') f = 0;
			else if (dir[i] == 'U') f = 1;
			else if (dir[i] == 'R') f = 2;
			else f = 3;
			if ((wall[x][y] & (1<<f)) != 0)
			{
				res = 0; break;
			}
			int xx = x + p[f][0];
			int yy = y + p[f][1];
			if (xx < 0 || xx >= w || yy < 0 || yy >= h)
			{
				res = 0; break;
			}
			x = xx;
			y = yy;
			visit[x][y] = 1;
		}

		/* bfs */
		memset(start , 0 , sizeof(start));
		memset(end , 0 , sizeof(end));
		bfs(0 , 0 , start);
		bfs(x , y , end);
		
		/* unique */
		if (res)
		{
			for (int i = 0; i < w; i ++)
			{
				for (int j = 0; j < h; j ++)
					if (visit[i][j] == 0 && start[i][j] + end[i][j] <= Len)
					{
						res = 0; break;
					}
				if (res == 0) break;
			}
		}
		/* unnecessary */
		if (res)
		{
			for (int i = 0; i < wallnum; i ++)
			{
				if (start[x1[i]][y1[i]] + end[x2[i]][y2[i]] + 1 > Len &&
					start[x2[i]][y2[i]] + end[x1[i]][y1[i]] + 1 > Len)
				{
					res = 0;
					break;
				}
			}
		}
		if (res == 1) printf("CORRECT\n");
		else printf("INCORRECT\n");
	}
	return 0;
}