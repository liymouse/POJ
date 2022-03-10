#include <stdio.h>

/*
inline minnum(int a , int b , int c)
{
int k;
	
	if (a > b) k = b; else k = a;
	if (c > k) return k; else return c;
}

inline maxnum(int a , int b , int c)
{
int k;

	if (a > b) k = a; else k = b;
	if (c > k) return c; else return k;
}
*/

int u , v , c; // 1<=x<=u  1<=y<=v  max-min <= c
int map[701][701];// , min[701][701] , max[701][701];
int i , j , x , y , border , s , t , maxn , minn;
int maxarea , res;

int main()
{
	scanf("%d %d %d" , &v , &u , &c);
	for (i = 0; i < u; i ++)
		for (j = 0; j < v; j ++) scanf("%d" , &map[i][j]);
	/*
	min[0][0] = map[0][0]; max[0][0] = map[0][0];
	for (i = 1; i < u; i ++)
	{
		min[i][0] = min[i-1][0] < map[i][0] ? min[i-1][0] : map[i][0];
		max[i][0] = max[i-1][0] > map[i][0] ? max[i-1][0] : map[i][0];
	}
	for (j = 1; j < v; j ++)
	{
		min[0][j] = min[0][j-1] < map[0][j] ? min[0][j-1] : map[0][j];
		max[0][j] = max[0][j-1] > map[0][j] ? max[0][j-1] : map[0][j];
	}
	for (i = 1; i < u; i ++)
		for (j = 1; j < v; j ++)
		{
			min[i][j] = minnum(min[i-1][j] , min[i][j-1] , map[i][j]);
			max[i][j] = maxnum(max[i-1][j] , max[i][j-1] , map[i][j]);
		}
	*/
	maxarea = 0;
	for (i = 0; i < u; i ++)
		for (j = 0; j < v; j ++)
		{
			border = (j + 100) < v ? (j + 100) : v;
			for (x = i; x < u; x ++)
				for (y = j; y < border; y ++)
				{
					if ((x-i+1) * (y-j+1) < maxarea) continue;
					/*
					if ((max[x][j] == max[x][y]) || (max[i][y] == max[x][y])
						|| (min[x][j] == min[x][y]) || (min[i][y] == min[x][y]))
					{
					*/
						minn = 50000; maxn = -50000;
						for (s = i; s <= x; s ++)
							for (t = j; t <= y; t ++)
							{
								if (map[s][t] > maxn) maxn = map[s][t];
								if (map[s][t] < minn) minn = map[s][t];
							}
						res = maxn - minn;
					/*}
					else res = max[x][y] - min[x][y];
					*/
					if (res <= c) maxarea = (x-i+1) * (y-j+1);
				}
		}
	printf("%d\n" , maxarea);
	return 0;
}