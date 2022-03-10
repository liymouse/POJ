#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n , t , b[12] , tot;
struct kk{int v , num;} a[12];

bool cmp(kk &x , kk &y)
{
	return x.v > y.v;
}

void find(int x , int sum)
{
int i , k , c[12];

	if (sum == t)
	{
		for (i = 0; i < n; i ++) c[i] = b[i];
		for (i = 0; i < n; i ++) if (c[i] > 0) {printf("%d" , a[i]); c[i] --; break;}
		while (i < n)
		{
			while (c[i] > 0) {printf("+%d" , a[i]); c[i] --;}
			i ++;
		}
		printf("\n"); tot ++;
		return;
	}
	else if (sum > t) return;
	if (x == n) return;
	else
	{
		for (i = a[x].num; i >= 0; i --)
		{
			b[x] = i;
			find(x + 1 , sum + a[x].v * i);
			b[x] = 0;
		}
	}
}

int main()
{
int i , j , x , p , k;

	while (scanf("%d %d" , &t , &n) == 2)
	{
		if ((t == 0) && (n == 0)) break;
		p = 0; k = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &x); k = -1;
			for (j = 0; j < p; j ++)
				if (x == a[j].v) {k = j; break;}
			if (k == -1) {a[p].v = x; a[p].num = 1; p ++;}
			else a[k].num ++;
		}
		n = p;
		sort(a , a + n , cmp);
		memset(b , 0 , sizeof(b));
		printf("Sums of %d:\n" , t);
		tot = 0;
		find(0 , 0);
		if (tot == 0) printf("NONE\n");
	}
	return 0;
}