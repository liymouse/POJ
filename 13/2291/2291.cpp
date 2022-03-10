#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int &x , int &y)
{
	return x > y;
}

int main()
{
int n , t , i , max;
int a[1000];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		sort(a , a + n , cmp);
		max = 0;
		for (i = 0; i < n; i ++) if (a[i] * (i + 1) > max) max = a[i] * (i + 1);
		printf("%d\n" , max);
	}
	return 0;
}