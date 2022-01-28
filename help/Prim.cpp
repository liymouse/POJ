//Prim 算法   读入顶点数(n)、边数(m)，边的起始点和权值   用邻接矩阵储存
//例如
//7 12 (7个顶点12条边)
//1 2 2
//1 4 1
//1 3 4
//2 4 3
//2 5 10
//3 4 2
//4 5 7
//3 6 5
//4 6 8
//4 7 4
//5 7 6
//6 7 1
#include <stdio.h>
#include <string.h>

int main()
{
int m , n;
int a[201][201] , mark[201] , pre[201] , dist[201];
int s , t , w;
int i , j , k , min , tot;

	freopen("Prim.txt" , "r" , stdin);
	//读入数据
	memset(a , 0 , sizeof(a));
	scanf("%d %d" , &n , &m);
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d %d" , &s , &t , &w);
		a[s][t] = w; a[t][s] = w;
	}
	//赋初值
	memset(mark , 0 , sizeof(mark));
	memset(pre , 0 , sizeof(pre));
	memset(dist , 9999 , sizeof(dist));
	dist[1] = 0;
	//Prim
	for (i = 1; i <= n; i ++)
	{
		min = 9999; k = 0;
		for (j = 1; j <= n; j ++) 
			if ((mark[j] == 0) && (dist[j] < min)) {min = dist[j]; k = j;}
		if (k == 0) break;
		mark[k] = 1;
		for (j = 1; j <= n; j ++)
			if ((mark[j] == 0) && (a[k][j] < dist[j]) && (a[k][j] > 0))
			{
				dist[j] = a[k][j];
				pre[j] = k;
			}
	}
	tot = 0;
	for (i = 1; i <= n; i ++) tot += dist[i];
	printf("%d\n" , tot);
	return 0;
}