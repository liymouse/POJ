#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int &x , int &y)
{
	return x < y;
}

int main()
{
int n , a[10000] , i;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	sort(a , a + n , cmp);
	printf("%d\n" , a[n/2]);
	return 0;
}