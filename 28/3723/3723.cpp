#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int g , b;
	int num;
}Re;

bool cmp(Re &x , Re &y)
{
	return x.num > y.num;
}

int father[20010];

int getfather(int x)
{
	if (father[x] == x) return x;
	father[x] = getfather(father[x]);
	return father[x];
}

int main()
{
int cas;
int n , m , r;
Re a[50010];
int res;
	
	
	scanf("%d" , &cas);
	while (cas --)
	{
		scanf("%d %d %d" , &n , &m , &r);
		for (int i = 0; i < m + n; i ++) father[i] = i;
		
		for (int i = 0; i < r; i ++)
			scanf("%d %d %d" , &a[i].g , &a[i].b , &a[i].num);
		sort(a , a + r , cmp);
		res = (n + m) * 10000;
		for (int i = 0; i < r; i ++)
		{
			int p = getfather(a[i].g);
			int q = getfather(a[i].b + n);
			if (p == q) continue;
			father[p] = q;
			res -= a[i].num;
		}
		printf("%d\n" , res);
	}
	return 0;
}
