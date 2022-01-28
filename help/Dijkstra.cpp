//读入顶点总数n,边总数m，和m行的边（此处为无向图）,输出从点1到n的最短路 
#include <stdio.h>

int main()
{
int map[201][201] = {0};
int mark[201] = {0} , dist[201] = {0} , path[201] = {0} , road[201] = {0};
int n , m , w , i , j , s , t , min , k;

	scanf("%d %d" , &n , &m);
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d %d" , &s , &t , &w);
		map[s][t] = w; map[t][s] = w;
	}
	mark[1] = 1; path[1] = 0;
	for (i = 2; i <= n; i ++)
	{
		dist[i] = map[1][i];
		if (dist[i] > 0) path[i] = 1;
	}
	for (i = 2; i <= n; i ++)
	{
		min = 32767; k = 0;
		for (j = 2; j <= n; j ++)
			if ((mark[j] == 0) && (dist[j] > 0) && (dist[j] < min)) {k = j; min = dist[j];}
		if (k == 0) break;
		mark[k] = 1;
		for (j = 2; j <= n; j ++)
			if ((mark[j] == 0) && (map[k][j] > 0) && ((dist[j] == 0) || (dist[k] + map[k][j] < dist[j])))            {
				dist[j] = dist[k] + map[k][j];
				path[j] = k;
			}
	}
	k = n; t = 0;
	while (path[k] > 0)
	{
		road[t ++] = k;
		k = path[k];
	}
	road[t] = 1;
	printf("%d\n" , dist[n]);
	for (i = t; i >= 0; i --) printf("%d " , road[i]);
	getchar(); getchar();
	return 0;
}
