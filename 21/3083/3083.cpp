#include <stdio.h>

char map[40][41];
int p[4][2] = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0}};
int f[4] = {0 , 2 , 3 , 1};
int leftstep , rightstep , minstep , dir;
int w , h , ok;

void find(int step , int x , int y , int fang , int turn)
{
int s , t , sk , tk , z;

	if (map[x][y] == 'E')
	{
		if (turn == 1) rightstep = step;
		else leftstep = step;
		ok = 1;
		return;
	}
	s = x + p[f[fang]][0]; t = y + p[f[fang]][1];
	z = fang + turn;
	if (z == 4) z = 0;
	else if (z == -1) z = 3;
	if (map[s][t] != '#')		//走
	{
		sk = s + p[f[z]][0]; tk = t + p[f[z]][1];
		if (map[sk][tk] != '#')	//顺转
		{
			fang += turn;
			if (fang == 4) fang = 0;
			else if (fang == -1) fang = 3;
		}
		find(step + 1 , s , t , fang , turn);
		if (ok) return;
	}
	else if (map[s][t] == '#')	//反转
	{
		fang -= turn;
		if (fang == 4) fang = 0;
		else if (fang == -1) fang = 3;
		find(step , x , y , fang , turn);
		if (ok) return;
	}
}

void shortfind(int sx , int sy)
{
int x[1600] , y[1600] , step[1600] , top , now;
int i , ok;

	x[0] = sx; y[0] = sy; step[0] = 0;
	top = 1; now = 0; ok = 0;
	while (1)
	{
		for (i = 0; i < 4; i ++)
		{
			x[top] = x[now] + p[i][0]; y[top] = y[now] + p[i][1]; step[top] = step[now] + 1;
			if (map[x[top]][y[top]] == 'E') {ok = 1; minstep = step[top]; break;}
			else if (map[x[top]][y[top]] == '.')
			{
				map[x[top]][y[top]] = 'x'; top ++;
			}
		}
		if (ok) break;
		now ++;
	}
}

int main()
{
int n , sx , sy , i , j;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%d %d\n" , &w , &h);
		for (i = 0; i < h; i ++)
		{
			gets(map[i]);
			for (j = 0; j < w; j ++)
			{
				if (map[i][j] == 'S')
				{
					sx = i; sy = j;
					if (i == 0) dir = 2;
					else if (i == h-1) dir = 0;
					else if (j == 0) dir = 1;
					else if (j == w-1) dir = 3;
				}
			}
		}
		ok = 0;
		find(0 , sx , sy , dir , 1);	//right
		ok = 0;
		find(0 , sx , sy , dir , -1);	//left
		shortfind(sx , sy);
		printf("%d %d %d\n" , leftstep+1 , rightstep+1 , minstep+1);
	}
	return 0;
}