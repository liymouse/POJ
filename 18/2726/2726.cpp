#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk{int d , c;}a[10000] , b[10000];

bool cmp(kk &x , kk &y)
{
	if (x.d == y.d) return x.c < y.c;
	else return x.d < y.d;
}

int main()
{
int n , i , tot , m , x;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%d %d" , &a[i].d , &a[i].c);
		sort(a , a + n , cmp);
		m = 0; b[0] = a[0];
		for (i = 0; i < n; i ++)
			if (a[i].d != b[m].d) {m ++; b[m] = a[i];}
		m ++;
		tot = 0; x = 99999999;
		for (i = 0; i < m; i ++) if (b[i].c < x) {tot ++; x = b[i].c;}
		printf("%d\n" , tot);
	}
	return 0;
}