#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

//state = top bottom north south east west
#define TOP 0
#define BOTTOM 1
#define NORTH 2
#define SOUTH 3
#define EAST 4
#define WEST 5
//rcgmby = 123456

typedef struct
{
	int x , y , state , init;
}node;

//first 4 is move , last one is rotate to left
int turn[5][6] = {{SOUTH , NORTH , TOP , BOTTOM , EAST , WEST},
{NORTH , SOUTH , BOTTOM , TOP , EAST , WEST},
{WEST , EAST , NORTH , SOUTH , TOP , BOTTOM},
{EAST , WEST , NORTH , SOUTH , BOTTOM , TOP},
{TOP , BOTTOM , WEST , EAST , NORTH , SOUTH}
};

int states[24] = {123456 , 214356 , 342156 , 431256 , 563421 , 653412};
int change[24][4] = {0};
int p[][2] = {{-1 , 0} , {1 , 0} , {0 , 1} , {0 , -1}};
int f[33][33][24] = {0};
int move[6][24][24] = {0};

int turnCube(int index , int d)
{
	char s[10] , res[10] = {0};
	sprintf(s , "%d" , states[index]);
	for (int i = 0; i < 6; i ++) res[i] = s[turn[d][i]];
	int newstate;
	sscanf(res , "%d" , &newstate);
	for (int i = 0; i < 24; i ++)
		if (states[i] == newstate) return i;
		else if (states[i] == 0)
		{
			states[i] = newstate;
			return i;
		}
	return -1;
}

int getIndex(char c)
{
	char s[] = "rcgmby";
	for (int i = 0; i < 6; i ++) if (s[i] == c) return i+1;
	return -1;
}

void getAllState()
{
	for (int i = 0; i < 6; i ++)
	{
		int s = i;
		for (int j = 0; j < 4; j ++)
		{
			s = turnCube(s , 4);
		}
	}
	for (int i = 0; i < 24; i ++)
		for (int j = 0; j < 4; j ++)
			change[i][j] = turnCube(i , j);
}


int main()
{
	int w , d;
	getAllState();
	while (scanf("%d %d" , &w , &d) == 2)
	{
		if (w == 0 && d == 0) break;
		char a[33][33] , order[10];
		for (int i = 0; i < d; i ++) scanf("%s" , a[i]);
		scanf("%s" , order);

		int initState[24] = {0} , x[6] , y[6];
		initState[0] = 1;
		memset(move , 0 ,sizeof(move));
		char st[10] = {'#'};
		for (int i = 0; i < 5; i ++) st[i+1] = order[i];
		for (int i = 0; i < d; i ++)
			for (int j = 0; j < w; j ++)
				for (int k = 0; k < 6; k ++)
					if (a[i][j] == st[k])
					{
						x[k] = i; y[k] = j;
						if (a[i][j] == '#') a[i][j] = 'w';
					}
		for (int k = 0; k < 6; k ++)
		{
			int newState[24] = {0};
			memset(f , 0 , sizeof(f));
			queue<node> q;
			for (int i = 0; i < 24; i ++)
				if (initState[i])
				{
					f[x[k]][y[k]][i] = 1;
					node tmp;
					tmp.state = tmp.init = i;
					tmp.x = x[k]; tmp.y = y[k];
					q.push(tmp);
				}
			while (!q.empty())
			{
				node top = q.front();
				q.pop();
				for (int j = 0; j < 4; j ++)
				{
					int x = top.x + p[j][0];
					int y = top.y + p[j][1];
					if (x >= 0 && x < d && 0 <= y && y < w)
					{
						int nextState = change[top.state][j];
						if (a[x][y] == 'w')
						{
							if (f[x][y][nextState] == 0 || f[top.x][top.y][top.state] + 1 < f[x][y][nextState])
							{
								f[x][y][nextState] = f[top.x][top.y][top.state] + 1;
								node tmp;
								tmp.x = x;
								tmp.y = y;
								tmp.state = nextState;
								tmp.init = top.init;
								q.push(tmp);
							}
						}
						else if (a[x][y] == order[k] && states[nextState]/100000 == getIndex(order[k]))
						{
							if (move[k][top.init][nextState] == 0 || f[top.x][top.y][top.state] + 1 < move[k][top.init][nextState])
								move[k][top.init][nextState] = f[top.x][top.y][top.state] + 1;
							newState[nextState] = 1;
						}
					}
				}
			}
			for (int i = 0; i < 24; i ++) initState[i] = newState[i];
		}
		int dp[6][24] = {0};
		for (int i = 0; i < 24; i ++) dp[0][i] = move[0][0][i];
		for (int i = 1; i < 6; i ++)
			for (int j = 0; j < 24; j ++)
			{
				for (int k = 0; k < 24; k ++)
					if (move[i][k][j] > 0 && (dp[i][j] == 0 || dp[i-1][k] + move[i][k][j] < dp[i][j]))
						dp[i][j] = dp[i-1][k] + move[i][k][j];
			}
		int res = 1 << 30;
		for (int i = 0; i < 24; i ++) if (dp[5][i]) res = min(res , dp[5][i]);
		if (res == 1 << 30) printf("unreachable\n");
		else printf("%d\n" , res - 6);
	}
	return 0;
}