#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct{
	int L , w;
}wood;

bool cmp(wood &x , wood &y)
{
	if (x.L == y.L) return x.w < y.w;
	else return x.L < y.L;
}

int main()
{
int cases , n , tot;
wood a[5000];
int f[5000];
int i , j , tottime , max , k;

	scanf("%d" , &cases);
	while (cases --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
			scanf("%d %d" , &a[i].L , &a[i].w);
		sort(a , a + n , cmp);
		tottime = 0;
		for (i = 0; i < n; i ++)
		{
			max = -1;
			for (j = 0; j < tottime; j ++) if ((a[i].w >= f[j]) && (max < f[j])) {max = f[j]; k = j;}
			if (max == -1) f[tottime ++] = a[i].w;
			else f[k] = a[i].w;
		}
		printf("%d\n" , tottime);
	}
	return 0;
}
