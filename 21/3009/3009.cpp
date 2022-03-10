//PKU 3009
//ษ๎หั
#include <stdio.h>

int w , h;
int map[20][20];
int f[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
int ok , mins;
int gx , gy;

void find(int x , int y , int step)
{
int i , s , t , b , tot;
int type;

	if (step > 10) return;
	if ((x == gx) && (y == gy))
	{
		ok = 1; if (step < mins) mins = step;
		return;
	}
	for (i = 0; i < 4; i ++)
	{
		s = x; t = y;
		b = 1; tot = 0;
		while (map[s][t] == 0)
		{
			s += f[i][0];
			if ((s < 0) || (s == h)) {b = 0; break;}
			t += f[i][1];
			if ((t < 0) || (t == w)) {b = 0; break;}
			tot ++;
		}
		if (b == 0) continue;	//out of border
		type = map[s][t];
		if ((type == 1) && (tot == 1)) continue;
		if (type == 3) find(s , t , step + 1);
		else if (type == 1)
		{
			map[s][t] = 0;
			s -= f[i][0]; t -= f[i][1];
			find(s , t , step + 1);
			s += f[i][0]; t += f[i][1];
			map[s][t] = 1;
		}
	}
}

int main()
{
int i , j , x , y;

	while (scanf("%d %d" , &w , &h) == 2)
	{
		if (w == 0) break;
		for (i = 0; i < h; i ++)
			for (j = 0; j < w; j ++)
			{
				scanf("%d" , &map[i][j]);
				if (map[i][j] == 2) {x = i; y = j; map[i][j] = 0;}
				else if (map[i][j] == 3) {gx = i; gy = j;}
			}
		ok = 0; mins = 11;
		find(x , y , 0);
		if (ok) printf("%d\n" , mins);
		else printf("-1\n");
	}
	return 0;
}
