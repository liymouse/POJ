#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk {int s , int t;}a[5000];

bool cmp(kk &x , kk &y)
{
	return x.s < y.s;
}

int main()
{
int n , m , i , t;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0) break;
		n ++;
		for (i = 0; i < m; i ++) scanf("%d %d" , &a[i].s , &a[i].t);
		sort(a , a + m , cmp);
		t = 0;
		for (i = 0; i < m; i ++)
		{
			if (a[i].s >= t)
			{
				n = n - (a[i].t - a[i].s + 1);
				t = a[i].t + 1;
			}
		}
		printf("%d\n" , n);
	}
	return 0;
}