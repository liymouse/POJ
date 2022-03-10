#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk{int id; double f;}a[65536];

bool cmp(kk &x , kk &y)
{
	return x.f < y.f;
}

int main()
{
int n , i , x;
double y;

	while (scanf("%d" , &n) == 1)
	{
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d %lf" , &a[i].id , &x , &y);
			a[i].f = double(x) / y;
		}
		sort(a , a + n , cmp);
		scanf("%d" , &n);
		printf("%d\n" , a[n-1].id);
	}
}