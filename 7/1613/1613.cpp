#include <cstdio>
#include <string>
#include <sstream>
#define MAX 999999999
using namespace std;

int n , m;
int nTime[501][36];
struct kk{int x , y , nTime;}bian[501];
int mark[51] , dist[51];
int p[501];

int tt(int x , int y , int s)
{
int i , j , t , min , b;

	min = MAX;
	for (i = 0; i < m; i ++)
		if (((x == bian[i].x) && (y == bian[i].y)) || ((x == bian[i].y) && (y == bian[i].x)))
		{
			t = s; b = 0;
			for (j = 1; j < p[i]; j ++)
			{
				if ((t >= nTime[i][j-1]) && (t < nTime[i][j]))
				{
					if (j % 2 == 0) t += nTime[i][j] - t;
					else
					{
						if (nTime[i][j] - t >= bian[i].nTime) {t = t + bian[i].nTime; b = 1; break;}
						else t += nTime[i][j] - t;
					}
				}
			}
			if ((b == 0) && (j % 2 == 0)) t = MAX;
			else if ((b == 0) && (j % 2 == 1)) t += bian[i].nTime;
			if (t < min) min = t;
		}
	return min;
}

int main()
{
int s , t , i , j , k , x  , min;
int a[51][51];
char line[2000];

	while (scanf("%d %d %d %d\n" , &n , &m , &s , &t) == 4)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < m; i ++)
		{
			gets(line);
			string str(line);
			istringstream input(str);
			input >> bian[i].x >> bian[i].y >> bian[i].nTime;
			a[bian[i].x][bian[i].y] = 1; a[bian[i].y][bian[i].x] = 1;
			p[i] = 1; nTime[i][0] = 0;
			while (input >> x) nTime[i][p[i]++] = x;
		}
		if (s == t) {printf("0\n"); continue;}
		for (i = 1; i <= n; i ++) dist[i] = MAX;
		memset(mark , 0 , sizeof(mark));
		for (i = 1; i <= n; i ++)
			if (a[s][i] > 0) dist[i] = tt(s , i , 0);
		mark[s] = 1;
		for (i = 1; i <= n; i ++)
		{
			min = MAX; k = 0;
			for (j = 1; j <= n; j ++)
				if ((mark[j] == 0) && (dist[j] < min))
				{min = dist[j]; k = j;}
			if (k == 0) break;
			mark[k] = 1;
			if (mark[t] == 1) break;
			for (j = 1; j <= n; j ++)
				if ((mark[j] == 0) && (a[k][j] > 0))
				{
					x = tt(k , j , dist[k]);
					if (x < dist[j]) dist[j] = x;
				}
		}
		if (dist[t] == MAX) printf("*\n");
		else printf("%d\n" , dist[t]);
	}
	return 0;
}