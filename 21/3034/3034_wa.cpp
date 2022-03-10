#include <stdio.h>
#include <string.h>
#define de 4

int dist(int x1 , int y1 , int x2 , int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int min(int x , int y)
{
	return x > y ? y : x;
}

int max(int x , int y)
{
	return x > y ? x : y;
}

int gcd(int x , int y)
{
int t;

	if (x < 0) x = -x;
	if (y < 0) y = -y;
	while (1)
	{
		if (y == 0) return x;
		t = y; y = x % y; x = t;
	}
}

int main()
{
int n , d , m;
int tmap[20][30][30];
int f[21][30][30];
int i , j , x , y , t;
int maxx , maxt , tot;
int p , q;
int a , b;

	while (scanf("%d %d %d" , &n , &d , &m) == 3)
	{
		if ((n == 0) && (d == 0) && (m == 0)) break;
		memset(tmap , 0 , sizeof(tmap));
		memset(f , 0 , sizeof(f));
		maxt = 0;
		d = d * d;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d %d" , &x , &y , &t);
			if (t > maxt) maxt = t;
			tmap[t][x+de][y+de] = 1;
		}
		for (t = 1; t <= maxt; t ++)
		{
			for (x = 0; x < n + 2 * de; x ++)
			{
				for (y = 0; y < n + 2 * de; y ++)
				{
					maxx = 0;
					/*for (i = 0; i < n + 2 * de; i ++)
						for (j = 0; j < n + 2 * de; j ++)
						*/
					for (i = max(0 , x - d); i < min(n + 2 * de , x + d + 1); i ++)
						for (j = max(0 , y - d); j < min(n + 2 * de , y + d + 1); j ++)
						{
							if (dist(x , y , i , j) <= d)
							{
								tot = 0;
								a = i - x;
								b = j - y;
								if (gcd(a , b) > 0)
								{
									a /= gcd(a , b);
									b /= gcd(a , b);
									p = x; q = y;
									while ((min(x , i) <= p) && (p <= max(x , i)) && 
											(min(y , j) <= q) && (q <= max(y , j)))
									{
										tot += tmap[t][p][q];
										p += a; q += b;
									}
								}
								else tot += tmap[t][x][y];
								/*
								for (p = min(x , i); p <= max(x , i); p ++)
									for (q = min(y , j); q <= max(y , j); q ++)
										if (((p - x) * b - (q - y) * a) == 0)
											tot +=  tmap[t][p][q];
								*/

								if (tot + f[t-1][i][j] > maxx) maxx = tot + f[t-1][i][j];
							}
						}
					f[t][x][y] = maxx;
					//printf("%d " , maxx);
				}
				//printf("\n");
			}
			//printf("\n");
		}
		maxx = 0;
		for (i = 0; i < n + 2 * de; i ++)
			for (j = 0; j < n + 2 * de; j ++)
				if (f[maxt][i][j] > maxx) maxx = f[maxt][i][j];
		printf("%d\n" , maxx);
	}
	return 0;
}
