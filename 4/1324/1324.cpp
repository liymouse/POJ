#include <stdio.h>
#include <string.h>

int n , m , L;
int p[4][2] = {{0 , -1} , {0 , 1} , {-1 , 0} , {1 , 0}};
int q[7] = {1 , 4 , 16 , 64 , 256 , 1024 , 4096};
int map[21][21];
struct kk{int sp , x , y , steps;} a[1000000];
int hash[16384][21][21];
int done , top , min;

void find()
{
int i , s , t , sh , y , x;
int body[8][2];

	x = 0;
	while (1)
	{
		sh = a[x].sp; body[0][0] = a[x].x; body[0][1] = a[x].y;
		for (i = 1; i < L; i ++)
		{
			y = sh / q[L-1-i]; sh %= q[L-1-i];
			body[i][0] = body[i-1][0] + p[y][0];
			body[i][1] = body[i-1][1] + p[y][1];
			map[body[i][0]][body[i][1]] = 2;
		}
		for (i = 0; i < 4; i ++)
		{
			s = a[x].x + p[i][0]; t = a[x].y + p[i][1];
			if ((1 <= s) && (s <= n) && (1 <= t) && (t <= m) && (map[s][t] == 0))
			{
				if ((s == 1) && (t == 1)) {done = 1; min = a[x].steps + 1; break;}
				if (i == 0) sh = 1;
				else if (i == 1) sh = 0;
				else if (i == 2) sh = 3;
				else sh = 2;
				sh = sh << ((L - 2) * 2);
				sh = sh | (a[x].sp >> 2);
				if (hash[sh][s][t] == 0)
				{
					top ++;
					a[top].sp = sh; a[top].x = s; a[top].y = t; a[top].steps = a[x].steps + 1;
					hash[sh][s][t] = 1;
				}
			}
		}
		if (done) break;
		for (i = 0; i < L; i ++)
			map[body[i][0]][body[i][1]] = 0;
		x ++;
		if (x > top) break;
	}
}

int main()
{
int i , j , k , x , y , lx , ly;
int h;

	h = 0;
	while (scanf("%d %d %d" , &n , &m , &L) == 3)
	{
		if (n == 0) break;
		h ++;
		scanf("%d %d" , &a[0].x , &a[0].y);
		a[0].sp = 0; lx = a[0].x; ly = a[0].y; a[0].steps = 0;
		for (i = 1; i < L; i ++)
		{
			scanf("%d %d" , &x , &y);
			for (j = 0; j < 4; j ++)
				if ((x == lx + p[j][0]) && (y == ly + p[j][1]))
				{
					a[0].sp = a[0].sp << 2; a[0].sp |= j;
				}
			lx = x; ly = y;
		}
		scanf("%d" , &k);
		memset(map , 0 , sizeof(map));
		memset(hash , 0 , sizeof(hash));
		hash[a[0].sp][a[0].x][a[0].y] = 1;
		for (i = 0; i < k; i ++)
		{
			scanf("%d %d" , &x , &y);
			map[x][y] = 1;
		}
		printf("Case %d: " , h);
		if ((a[0].x == 1) && (a[0].y == 1)) printf("0\n");
		else
		{
			done = 0; top = 0;
			find();
			if (done == 0) printf("-1\n");
			else printf("%d\n" , min);
		}
	}
}