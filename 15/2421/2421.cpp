#include <stdio.h>
#include <algorithm>
using namespace std;

int a[110][110];
int father[110];
typedef struct
{
	int a , b , w;
}bian;
bian b[6000];
int num;

int find(int x)
{
	if (x == father[x]) return x;
	father[x] = find(father[x]);
	return father[x];
}

int cmp(bian &a , bian &b)
{
	return a.w < b.w;
}

int main()
{
int n , i , j , m , x , y;
int res = 0;

	scanf("%d" , &n);
	for (i = 1; i <= n; i ++)
		for (j = 1; j <= n; j ++)
			scanf("%d" , &a[i][j]);
	
	scanf("%d" , &m);
	for (i = 1; i <= n; i ++) father[i] = i;
	for (i = 0; i < m; i ++)
	{
		scanf("%d %d" , &x , &y);
		a[x][y] = 0; a[y][x] = 0;
	}
	num = 0;
	for (i = 1; i <= n; i ++)
		for (j = 1; j < i; j ++)
		{
			b[num].a = i; b[num].b = j; b[num++].w = a[i][j];
		}
	sort(b , b + num , cmp);
	
	for (i = 0; i < num; i ++)
	{
		x = find(b[i].a);
		y = find(b[i].b);
		if (x != y)
		{
			father[x] = y;
			res += b[i].w;
		}
	}
	printf("%d\n" , res);
	return 0;
}
