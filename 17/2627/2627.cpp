#include <stdio.h>
#include <math.h>

char map[1002][1002] = {0} , mark[1002] = {0};
int dist[1002] = {0};

int main()
{
int v , m;
int i , n , j , k , min;
double a[1002] , b[1002];

	scanf("%d %d" , &v , &m);
	n = 0; k = 60 * v * m;
	while (scanf("%lf %lf" , &a[n] , &b[n]) == 2) n ++;
	for (i = 0; i < n; i ++)
		for (j = i + 1; j < n; j ++)
			if (sqrt((a[i]-a[j]) * (a[i]-a[j]) + (b[i]-b[j]) * (b[i]-b[j])) <= k)
			{map[i][j] = 1; map[j][i] = 1;}
	for (i = 0; i < n; i ++) if (map[i][1]) dist[i] = 1;
	mark[1] = 1;
	for (i = 0; i < n; i ++)
	{
		k = -1; min = 9999;
		for (j = 0; j < n; j ++)
			if ((mark[j] == 0) && (dist[j] > 0) && (dist[j] < min)) {min = dist[j]; k = j;}
		if ((k == -1) || (k == 0)) break;
		mark[k] = 1;
		for (j = 0; j < n; j ++)
			if ((mark[j] == 0) && (map[j][k] > 0) && ((dist[j] == 0) || (map[j][k] + dist[k] < dist[j])))
				dist[j] = map[j][k] + dist[k];
	}
	if (dist[0] == 0) printf("No.\n");
	else printf("Yes, visiting %d other holes.\n" , dist[0] - 1);
	return 0;
}