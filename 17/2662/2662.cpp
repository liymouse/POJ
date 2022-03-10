#include <stdio.h>
#include <string.h>
#define MAX 2147483647

int a[1001][1001];
int n , dist[1001];
int num[1001] , no[1001];

void qu(int s , int t)
{
int i , j , x , y;

	i = s; j = t; x = dist[(i+j)/2];
	while (i <= j)
	{
		while (dist[i] < x) i ++;
		while (dist[j] > x) j --;
		if (i <= j)
		{
			y = dist[i]; dist[i] = dist[j]; dist[j] = y;
			y = no[i]; no[i] = no[j]; no[j] = y;
			i ++; j --;
		}
	}
	if (i < t) qu(i , t);
	if (s < j) qu(s , j);
}

int main()
{
int m , x , y , d;
int mark[1001];
int i , j , k , min;

	//freopen("2662.txt" , "r" , stdin);
	while (scanf("%d %d" , &n , &m) == 2)
	{
		memset(a , 0 , sizeof(a));
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d %d" , &x , &y , &d);
			a[x][y] = d; a[y][x] = d;
		}
		for (i = 1; i <= n; i ++) if (a[i][2] > 0) dist[i] = a[i][2]; else dist[i] = -1;
		memset(mark , 0 , sizeof(mark)); dist[2] = 0; mark[2] = 1;
		for (i = 1; i <= n; i ++)
		{
			k = 0; min = MAX;
			for (j = 1; j <= n; j ++)
				if ((mark[j] == 0) && (dist[j] != -1) && (dist[j] < min))
				{k = j; min = dist[j];}
			if (k == 0) break;
			mark[k] = 1;
			for (j = 1; j <= n; j ++)
				if ((mark[j] == 0) && (a[j][k] > 0) && ((dist[j] == -1) || (a[j][k] + dist[k] < dist[j])))
				{
					dist[j] = dist[k] + a[j][k];
				}
		}
		for (i = 1; i <= n; i ++) no[i] = i;
		memset(num , 0 , sizeof(num));
		qu(1 , n);
		num[2] = 1;
		for (i = 2; i <= n; i ++)
		{
			for (j = 1; j < i; j ++) if ((a[no[j]][no[i]] > 0) && (dist[i] > dist[j])) num[no[i]] += num[no[j]];
		}
		printf("%d\n" , num[1]);
	}
	return 0;
}