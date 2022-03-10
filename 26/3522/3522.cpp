#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int x , y , w;
}bian;

bian a[5000];
int father[105];
int n , m;

int find(int x)
{
int t;

	if (x == father[x]) return x;
	t = find(father[x]);
	father[x] = t;
	return t;
}

int kruskal(int x)
{
int i;
int p , q;
int b[5000] = {0};

	for (i = 1; i <= n; i ++) father[i] = i;
	for (i = x; i < m; i ++)
	{
		p = find(a[i].x);
		q = find(a[i].y);
		if (p != q)
		{
			b[i] = 1;
			father[p] = q;
		}
	}
	p = find(1);
	for (i = 2; i <= n; i ++) if (find(i) != p) return -1;
	for (q = m-1; q >= x; q --) if (b[q] == 1) break;
	for (p = x; p < m; p ++) if (b[p] == 1) break;
	return a[q].w - a[p].w;
}

int cmp(bian &a , bian &b)
{
	return a.w < b.w;
}

int main()
{
int i , min , x;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		for (i = 0; i < m; i ++)
			scanf("%d %d %d" , &a[i].x , &a[i].y , &a[i].w);
		sort(a , a + m , cmp);
		min = 999999999;
		for (i = 0; i < m; i ++)
		{
			x = kruskal(i);
			if (x != -1 && x < min) min = x;
		}
		if (min < 999999999) printf("%d\n" , min);
		else printf("-1\n");
	}
	return 0;
}
