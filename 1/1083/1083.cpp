#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct{
	int a , b;
}kk;

bool cmp(kk &x , kk &y)
{
	return x.a < y.a;
}

int main()
{
int cases , n , x , y , t;
kk a[200];
int i , j , f[200] , tottime , max , k;

	scanf("%d" , &cases);
	while (cases--)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			if (x/2 + x%2 > y/2 + y%2) {t = x; x = y; y = t;}
			a[i].a = x/2 + x%2;
			a[i].b = y/2 + y%2;
		}
		sort(a , a + n , cmp);
		tottime = 0;
		for (i = 0; i < n; i ++)
		{
			max = -1;
			for (j = 0; j < tottime; j ++) if ((a[i].a > f[j]) && (f[j] > max)) {max = f[j]; k = j;}
			if (max == -1) f[tottime ++] = a[i].b;
			else f[k] = a[i].b;
		}
		printf("%d\n" , tottime * 10);
	}
	return 0;
}