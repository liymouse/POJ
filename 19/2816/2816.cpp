#include <stdio.h>
#include <string.h>

int main()
{
int f[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
int a[100][100] , w , h , L , gx , gy , x , y , n , face;
int i , j , step , right , left , min , max , have , suc;
struct {int x , y;} entrance[50];
char s[102];

	//freopen("2816test1.in" , "r" , stdin);
	//freopen("2816out.txt" , "w" , stdout);
	while (scanf("%d %d\n" , &w , &h) == 2)
	{
		if (w < 3 || h < 3) break;
		memset(a , 0 , sizeof(a));
		n = 0; suc = 0;
		for (i = 0; i < h; i ++)
		{
			gets(s);
			L = strlen(s);
			if (L > w) L = w;
			for (j = 0; j < L; j ++)
				if (s[j] == 'X') a[i][j] = 0;
				else if (s[j] == 'G') {a[i][j] = 2; gx = i; gy = j;}
				else if (s[j] == ' ') a[i][j] = 1;
				else
				{
					a[i][j] = 1;
					entrance[n].x = i; entrance[n].y = j;
					n ++;
				}
		}
		for (i = 0; i < n; i ++)
		{
			x = entrance[i].x; y = entrance[i].y;
			face = -1;
			for (j = 0; j < 4; j ++)
				if ((x + f[j][0] >= 0) && (x + f[j][0] < h) && (y + f[j][1] >= 0) && (y + f[j][1] < w)
					&& (a[x+f[j][0]][y+f[j][1]])) {face = j; break;}
			if (face < 0) break;
			while (1)
			{
				if (x == gx)
				{
					min = y < gy ? y : gy;
					max = y > gy ? y : gy;
					have = 0;
					for (j = min; j <= max; j ++) if (a[x][j] == 0) {have = 1; break;}
					if (have == 0) {suc ++; break;}
				}
				else if (y == gy)
				{
					min = x < gx ? x : gx;
					max = x > gx ? x : gx;
					have = 0;
					for (j = min; j <= max; j ++) if (a[j][y] == 0) {have = 1; break;}
					if (have == 0) {suc ++; break;}
				}
				if ((x + f[face][0] < 0) || (x + f[face][0] >= h) || (y + f[face][1] < 0) || (y + f[face][1] >= w)) break;
				if (a[x + f[face][0]][y + f[face][1]])
				{
					right = (face+1) % 4;
					/*
					while ((a[x + f[face][0]][y + f[face][1]]) && (a[x + f[right][0]][y + f[right][1]] == 0))
					{
						x += f[face][0]; y += f[face][1];
						if (x == gx || y == gy) break;
					}
					*/
					x += f[face][0]; y += f[face][1];
					if (a[x + f[right][0]][y + f[right][1]])
					{
						x += f[right][0]; y += f[right][1];
						face = right;
					}
				}
				else
				{
					left = (face + 3) % 4;
					if (a[x + f[left][0]][y + f[left][1]])
					{
						x += f[left][0]; y += f[left][1];
						face = left;
					}
					else face = (face + 2) % 4;
				}

			}
		}
		printf("The goal would be found from %d out of %d entrances.\n" , suc , n);
	}
	return 0;
}