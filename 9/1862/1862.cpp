#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(const double x , const double y)
{
	return x > y;
}

int main()
{
int i , n , a[100];
double sum;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	if (n == 1) printf("%d.000\n" , a[0]);
	else
	{
		sort(a , a + n , cmp);
		sum = 2 * sqrt(a[0] * a[1]);
		for (i = 2; i < n; i ++) sum = 2 * sqrt(sum * a[i]);
		printf("%.3lf\n" , sum);
	}
	return 0;
}