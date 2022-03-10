#include <stdio.h>
#include <string.h>

typedef struct
{
	int ID , x , y , z;
}kk;
int dist[1011][1011];

int dis(kk x , kk y)
{
	return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) + (x.z - y.z) * (x.z - y.z);
}

int main()
{

int max[1011];
int n , min , k;
int res[2];
int i , j;
kk a[1001];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(dist , 0 , sizeof(dist));
		for (i = 1; i <= n; i ++)
		{
			scanf("%d %d %d %d" , &a[i].ID , &a[i].x , &a[i].y , &a[i].z);
		}
		for (i = 1; i <= n; i ++)
		{
			k = 0; min = 1000000;
			for (j = 1; j < i; j ++)
				if (dis(a[i] , a[j]) < min) {min = dis(a[i] , a[j]); k = j;}
			for (j = 1; j < i; j ++)
			{
				dist[i][j] = dist[j][k] + 1;
				dist[j][i] = dist[i][j];
			}
		}
		min = 1000000;
		for (i = 1; i <= n; i ++)
		{
			max[i] = 0;
			for (j = 1; j <= n; j ++) if (dist[i][j] > max[i]) max[i] = dist[i][j];
			if (max[i] < min) min = max[i];
		}
		k = 0;
		for (i = 1; i <= n; i ++)
			if (max[i] == min)
			{
				res[k ++] = a[i].ID;
			}
		if (k == 1) printf("%d\n" , res[0]);
		else
		{
			if (res[0] < res[1]) printf("%d %d\n" , res[0] , res[1]);
			else printf("%d %d\n" , res[1] , res[0]);
		} 
	}
	return 0;
}


