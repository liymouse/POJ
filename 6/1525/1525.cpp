#include <stdio.h>
#include <string.h>
int map[7][7] ={{ 0,        0,        1,        2,        3,        0,        0},
                { 0,        0,        4,        5,        6,        0,        0},
		        { 7,        8,        9,       10,       11,       12,       13},
                {14,       15,       16,       17,       18,       19,       20},
                {21,       22,       23,       24,       25,       26,       27},      
                { 0,        0,       28,       29,       30,        0,        0},
                { 0,        0,       31,       32,       33,        0,        0}};
typedef struct 
{
	int middle , end;
}node;
node a[4][34];
int b[34] = {0};

void prepare()
{
int p[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
int i , j , k , t , x , y , xx , yy;

	for (i = 0; i < 7; i ++)
		for (j = 0; j < 7; j ++)
			if (map[i][j] > 0)
			{
				t = map[i][j];
				for (k = 0; k < 4; k ++)
				{
					x = i + p[k][0];
					y = j + p[k][1];
					xx = x + p[k][0];
					yy = y + p[k][1];
					if (0 <= x && x < 7 && 0 <= y && y < 7 
						&& 0 <= xx && xx < 7 && 0 <= yy && yy < 7 
						&& map[x][y] > 0 && map[xx][yy] > 0)
					{
						a[k][t].end = map[xx][yy];
						a[k][t].middle = map[x][y];
					}
					else
					{
						a[k][t].end = -1;
						a[k][t].middle = -1;
					}
				}
			}
}

int moni()
{
int i , maxend = 1 , j , x , y , res;

	while (maxend > 0)
	{
		maxend = 0; x = 0; y = 0;
		for (i = 1; i <= 33; i ++)
			if (b[i])
			{
				for (j = 0; j < 4; j ++)
					if (a[j][i].end > 0 && b[a[j][i].end] == 0 && b[a[j][i].middle] == 1)
					{
						if (a[j][i].end >= maxend)
						{
							maxend = a[j][i].end;
							x = i;
							y = j;
						}
					}
			}
		if (maxend > 0)
		{
			b[x] = 0;
			b[a[y][x].middle] = 0;
			b[a[y][x].end] = 1;
		}
	}
	res = 0;
	for (i = 1; i <= 33; i ++) if (b[i]) res += i;
	return res;
}

int main()
{
int t , k;

	prepare();
	scanf("%d" , &t);
	printf("HI Q OUTPUT\n");
	while (scanf("%d" , &k) == 1)
	{
		if (k == 0)
		{
			printf("%d\n" , moni());
			memset(b , 0 , sizeof(b));
		}
		else
		{
			b[k] = 1;
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
