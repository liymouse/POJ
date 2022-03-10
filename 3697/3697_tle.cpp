#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int father[10005];
typedef struct
{
	int a , b;
}node;
node a[1000000];

int cmp(node &a , node &b)
{
	if (a.a == b.a) return a.b < b.b;
	return a.a < b.a;
}

int find(int x)
{
	if (x == father[x]) return x;
	father[x] = find(father[x]);
	return father[x];
}

int main()
{
int n , m , i , j , k;
int cas , res;

	cas = 0;
	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		cas ++;
		for (i = 1; i <= n; i ++) father[i] = i;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d" , &a[i].a , &a[i].b);
			if (a[i].a > a[i].b) swap(a[i].a , a[i].b);
		}
		sort(a , a + m , cmp);
		k = 0;
		for (i = 1; i <= n; i ++)
			for (j = i + 1; j <= n; j ++)
			{
				if (k < m && ((a[k].a < i) || (a[k].a == i && a[k].b < j))) k ++;
				if (a[k].a == i && a[k].b == j) continue;
				father[find(i)] = find(j);
			}
		res = 0;
		for (i = 2; i <= n; i ++)
			if (find(i) == find(1)) res ++;
		printf("Case %d: %d\n" , cas , res);
	}
	return 0;
}