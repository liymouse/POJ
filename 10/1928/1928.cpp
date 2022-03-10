#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int x , y , val;
}kk;

int cmp(kk &x , kk &y)
{
	return x.val > y.val;
}

int main()
{
int m , n , k , t , totv , tott , tep , i , j , dis;
kk a[3000];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d %d" , &m , &n , &k);
		for (i = 0; i < m; i ++)
			for (j = 0; j < n; j ++)
			{
				a[i * n + j].x = i + 1; a[i * n + j].y = j + 1;
				scanf("%d" , &a[i * n + j].val);
			}
		tep = m * n;
		sort(a , a + tep , cmp);
		totv = 0;
		if (2 * a[0].x + 1 <= k)
		{
			totv += a[0].val;
			k -= a[0].x + 1;
			for (i = 1; i < tep; i ++)
			{
				dis = abs(a[i].x - a[i-1].x) + abs(a[i].y - a[i-1].y);
				k -= dis + 1;
				if (a[i].x <= k) totv += a[i].val;
				else break;
			}
		}
		printf("%d\n" , totv);
	}
	return 0;
}